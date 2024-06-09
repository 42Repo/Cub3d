/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:01:19 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/09 02:20:47 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	init_ray(t_ray *ray, t_player *player, float camera_x)
{
	ray->pos = player->pos;
	ray->dir.x = player->dir.x + player->plane.x * camera_x;
	ray->dir.y = player->dir.y + player->plane.y * camera_x;
	ray->map_x = (int)ray->pos.x;
	ray->map_y = (int)ray->pos.y;
	ray->delta_dist_x = fabs(1 / ray->dir.x);
	ray->delta_dist_y = fabs(1 / ray->dir.y);
	ray->hit = 0;
}

void	calculate_step_and_side_dist(t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->pos.x) * ray->delta_dist_x;
	}
	if (ray->dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->pos.y) * ray->delta_dist_y;
	}
}

void	perform_dda(t_ray *ray, t_map *map)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
	{
		ray->perp_wall_dist = (ray->map_x - ray->pos.x + (1 - ray->step_x) / 2)
			/ ray->dir.x;
	}
	else
	{
		ray->perp_wall_dist = (ray->map_y - ray->pos.y + (1 - ray->step_y) / 2)
			/ ray->dir.y;
	}
}

void	cast_ray(t_data *data, int x)
{
	float	camera_x;
	t_ray	ray;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		*texture;
	float	wall_x;
	int		tex_x;
	float	step;
	float	tex_pos;
	int		tex_y;
	int		color;

	camera_x = 2 * x / (float)data->map.width - 1;
	init_ray(&ray, &data->player, camera_x);
	calculate_step_and_side_dist(&ray);
	perform_dda(&ray, &data->map);
	line_height = (int)(data->map.height / ray.perp_wall_dist);
	draw_start = -line_height / 2 + data->map.height / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + data->map.height / 2;
	if (draw_end >= data->map.height)
		draw_end = data->map.height - 1;
	if (ray.side == 0)
	{
		if (ray.dir.x > 0)
			texture = data->mlx.wall_sprite.east_texture;
		else
			texture = data->mlx.wall_sprite.west_texture;
	}
	else
	{
		if (ray.dir.y > 0)
			texture = data->mlx.wall_sprite.south_texture;
		else
			texture = data->mlx.wall_sprite.north_texture;
	}
	if (ray.side == 0)
		wall_x = ray.pos.y + ray.perp_wall_dist * ray.dir.y;
	else
		wall_x = ray.pos.x + ray.perp_wall_dist * ray.dir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (float)data->mlx.wall_sprite.wall_n.width);
	if ((ray.side == 0 && ray.dir.x > 0) || (ray.side == 1 && ray.dir.y < 0))
		tex_x = data->mlx.wall_sprite.wall_n.width - tex_x - 1;
	step = 1.0 * data->mlx.wall_sprite.wall_n.height / line_height;
	tex_pos = (draw_start - (float)(data->map.height) / 2 + (float)line_height
			/ 2) * step;
	for (int y = draw_start; y < draw_end; y++)
	{
		tex_y = (int)tex_pos & (data->mlx.wall_sprite.wall_n.height - 1);
		tex_pos += step;
		color = texture[tex_y * data->mlx.wall_sprite.wall_n.width + tex_x];
		mlx_pixel_put(data->mlx.mlx, data->mlx.win, x, y, color);
	}
}

void	render_frame(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.width)
	{
		cast_ray(data, i);
		i++;
	}
}
