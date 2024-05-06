/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:01:19 by bgoron            #+#    #+#             */
/*   Updated: 2024/05/06 02:04:41 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	cast_ray(double angle, t_data d, t_ray *ray)
{
	int				map_x;
	int				map_y;
	const double	cos_angle = cos(angle);
	const double	sin_angle = sin(angle);

	ray->hit_pos = d.player.pos;
	while (42)
	{
		map_x = (int)ray->hit_pos.x / TILE_SIZE;
		map_y = (int)ray->hit_pos.y / TILE_SIZE;
		if (ray->hit_pos.x < 0 || ray->hit_pos.y < 0 || map_x >= d.map.cols || map_y >= d.map.rows)
			break ;
		if (d.map.map[map_y][map_x] == '1')
			break ;
		mlx_set_image_pixel(d.mlx.mlx, d.mlx.img_player,
			ray->hit_pos.x, ray->hit_pos.y, 0xFF303030);
		ray->hit_pos.x += cos_angle;
		ray->hit_pos.y += sin_angle;
	}
	ray->dist = sqrt(pow(d.player.pos.x - ray->hit_pos.x, 2) + pow(d.player.pos.y - ray->hit_pos.y, 2));
}

void	add_wall(t_data d, int i, double wall_size)
{
	const int	half_height = d.map.height >> 1;
	const int	half_wall_size = (int)wall_size >> 1;
	const int	wall_width = d.map.width / d.mlx.ray_nb;
	int			wall_y;
	int			wall_x;

	wall_y = half_height - ((int)wall_size >> 1);
	while (wall_y <= half_height + half_wall_size && wall_y <= d.map.height)
	{
		wall_x = i * wall_width;
		while (wall_x < (i + 1) * wall_width && wall_x < d.map.width)
		{
			mlx_set_image_pixel \
			(d.mlx.mlx, d.mlx.img_wall, wall_x++, wall_y, 0xFF000000);
			wall_x++;
		}
		wall_y++;
	}
}

void	draw_ray(t_data d, int i, t_ray *ray)
	{
	double	plane_distance;
	double	ray_angle;
	double	corrected_angle;
	double	correct_dist;
	double	wall_height;

	plane_distance = (d.map.width / 2) / tan(FOV_RAD / 2);
	ray_angle = d.player.angle + atan((i - d.map.width / 2.0) / plane_distance);
	corrected_angle = ray_angle - d.player.angle;
	correct_dist = ray->dist * cos(corrected_angle);
	wall_height = (TILE_SIZE / correct_dist) * plane_distance;
	cast_ray(ray_angle, d, ray);
	if (!ray->dist)
		wall_height = WIN_HEIGHT;
	add_wall(d, i, wall_height);
}

void	add_ray(t_data d)
{
	t_ray	ray;
	size_t	i;

	i = 0;
	reset_image(d, d.mlx.img_wall);
	while (i < d.mlx.ray_nb)
	{
		draw_ray(d, i, &ray);
		i++;
	}
}