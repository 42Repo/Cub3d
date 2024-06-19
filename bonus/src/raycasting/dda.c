/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:58:08 by asuc              #+#    #+#             */
/*   Updated: 2024/06/19 12:04:27 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_raycasting.h"

static inline int	is_within_map_bounds(t_ray *ray, t_map *map)
{
	return (ray->map.x >= 0 && ray->map.x < map->cols && ray->map.y >= 0
		&& ray->map.y < map->rows);
}

static inline int	has_reached_max_distance(t_ray *ray, int max_distance)
{
	return (fabs(ray->pos.x - ray->map.x) > max_distance || fabs(ray->pos.y
			- ray->map.y) > max_distance);
}

static inline void	update_ray_position(t_ray *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->map.x += ray->step.x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->map.y += ray->step.y;
		ray->side = 1;
	}
}

static inline void	calculate_perpendicular_distance(t_ray *ray)
{
	if (ray->side == 0)
	{
		ray->perp_wall_dist = (ray->map.x - ray->pos.x + (1 - ray->step.x) / 2)
			/ ray->dir.x;
	}
	else
	{
		ray->perp_wall_dist = (ray->map.y - ray->pos.y + (1 - ray->step.y) / 2)
			/ ray->dir.y;
	}
}

inline void	perform_dda(t_ray *ray, t_map *map, t_player *player)
{
	int	max_distance;

	max_distance = sqrt(WIN_WIDTH * WIN_WIDTH + WIN_HEIGHT * WIN_HEIGHT) + 1;
	while (ray->hit == 0)
	{
		update_ray_position(ray);
		if (is_within_map_bounds(ray, map) \
		&& (map->map[ray->map.y][ray->map.x] == '1' \
		|| (!player_is_in_front_of_door(player, ray) \
		&& (map->map[ray->map.y][ray->map.x] == 'D'))))
			ray->hit = 1;
		else if (has_reached_max_distance(ray, max_distance))
		{
			ray->hit = 2;
			break ;
		}
	}
	if (ray->hit == 1)
	{
		calculate_perpendicular_distance(ray);
	}
	else if (ray->hit == 2)
	{
		ray->perp_wall_dist = max_distance;
	}
}
