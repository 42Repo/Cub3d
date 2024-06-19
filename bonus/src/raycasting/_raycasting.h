/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _raycasting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:59:19 by asuc              #+#    #+#             */
/*   Updated: 2024/06/19 10:09:44 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RAYCASTING_H
# define _RAYCASTING_H

# include "../../include/struct.h"

typedef struct s_ray_params
{
	t_ray	ray;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		*texture;
	int		tex_x;
	float	step;
	float	tex_pos;
	int		line_offset;
	int		texture_height;
	int		texture_width;
}			t_ray_params;

void		perform_dda(t_ray *ray, t_map *map, t_player *player);
void		calculate_wall_x_and_tex_x(t_ray *ray, t_ray_params *params);
int			*select_texture(t_ray_params *params, t_sprite *sprite);
void		calculate_step_and_side_dist(t_ray *ray);
void		init_ray(t_ray *ray, t_player *player, float camera_x);

#endif // _RAYCASTING_H