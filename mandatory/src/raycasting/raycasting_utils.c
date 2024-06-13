/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:34:29 by asuc              #+#    #+#             */
/*   Updated: 2024/06/13 16:45:46 by asuc             ###   ########.fr       */
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
	ray->delta_dist_x = fabs(1 / ray->dir.x);
	ray->delta_dist_y = fabs(1 / ray->dir.y);
	ray->hit = 0;
}

inline void	calculate_step_and_side_dist(t_ray *ray)
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

inline int	*select_texture(t_ray *ray, t_sprite *sprite)
{
	if (ray->side == 0)
	{
		if (ray->dir.x > 0)
			return (sprite->east_texture);
		return (sprite->west_texture);
	}
	else
	{
		if (ray->dir.y > 0)
			return (sprite->south_texture);
		return (sprite->north_texture);
	}
}

inline void	calculate_wall_x_and_tex_x(t_ray *ray, t_ray_params *params,
		t_sprite *sprite)
{
	if (ray->side == 0)
		params->wall_x = ray->pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		params->wall_x = ray->pos.x + ray->perp_wall_dist * ray->dir.x;
	params->wall_x -= floor(params->wall_x);
	params->tex_x = (int)(params->wall_x * (float)sprite->wall_n.width);
	if ((ray->side == 0 && ray->dir.x > 0) || (ray->side == 1
			&& ray->dir.y < 0))
		params->tex_x = sprite->wall_n.width - params->tex_x - 1;
}
