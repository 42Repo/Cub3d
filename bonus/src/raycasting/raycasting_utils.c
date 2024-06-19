/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:34:29 by asuc              #+#    #+#             */
/*   Updated: 2024/06/19 11:41:29 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_raycasting.h"

inline void	init_ray(t_ray *ray, t_player *player, float camera_x)
{
	ray->pos = player->pos;
	ray->dir.x = player->dir.x + player->plane.x * camera_x;
	ray->dir.y = player->dir.y + player->plane.y * camera_x;
	ray->map_x = (int)ray->pos.x;
	ray->map_y = (int)ray->pos.y;
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
	ray->hit = 0;
}

inline void	calculate_step_and_side_dist(t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist.x = (ray->pos.x - ray->map_x) * ray->delta_dist.x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist.x = (ray->map_x + 1.0 - ray->pos.x) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist.y = (ray->pos.y - ray->map_y) * ray->delta_dist.y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist.y = (ray->map_y + 1.0 - ray->pos.y) * ray->delta_dist.y;
	}
}

inline int	*select_texture(t_ray_params *params, t_sprite *sprite)
{
	if (params->ray.side == 0)
	{
		if (params->ray.dir.x > 0)
		{
			params->texture_height = sprite->wall_e.height;
			params->texture_width = sprite->wall_e.width;
			return (sprite->east_texture);
		}
		params->texture_height = sprite->wall_w.height;
		params->texture_width = sprite->wall_w.width;
		return (sprite->west_texture);
	}
	else
	{
		if (params->ray.dir.y > 0)
		{
			params->texture_height = sprite->wall_s.height;
			params->texture_width = sprite->wall_s.width;
			return (sprite->south_texture);
		}
		params->texture_height = sprite->wall_n.height;
		params->texture_width = sprite->wall_n.width;
		return (sprite->north_texture);
	}
}

inline void	calculate_wall_x_and_tex_x(t_ray *ray, t_ray_params *params)
{
	float	wall_x;

	if (ray->side == 0)
		wall_x = ray->pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		wall_x = ray->pos.x + ray->perp_wall_dist * ray->dir.x;
	wall_x -= floor(wall_x);
	params->tex_x = (int)(wall_x * (float)params->texture_width);
	if ((ray->side == 0 && ray->dir.x > 0) || (ray->side == 1
			&& ray->dir.y < 0))
		params->tex_x = params->texture_width - params->tex_x - 1;
}

int	player_is_in_front_of_door(t_player *player, t_ray *ray)
{
	return ((((int)player->pos.x == ray->map_x \
	&& (int)player->pos.y == ray->map_y) \
	|| ((int)player->pos.x == ray->map_x + 1 \
	&& (int)player->pos.y == ray->map_y) \
	|| ((int)player->pos.x == ray->map_x - 1 \
	&& (int)player->pos.y == ray->map_y) \
	|| ((int)player->pos.x == ray->map_x \
	&& (int)player->pos.y == ray->map_y + 1) \
	|| ((int)player->pos.x == ray->map_x \
	&& (int)player->pos.y == ray->map_y - 1)));
}
