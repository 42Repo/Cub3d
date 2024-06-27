/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _floor_ceiling_render.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:39:58 by asuc              #+#    #+#             */
/*   Updated: 2024/06/27 15:30:32 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FLOOR_CEILING_RENDER_H
# define _FLOOR_CEILING_RENDER_H

# include "include.h"
# include <math.h>

typedef struct s_render_data
{
	t_data	*data;
	float	ray_dir_x0;
	float	ray_dir_y0;
	float	ray_dir_x1;
	float	ray_dir_y1;
	float	center_line;
	float	pos_z;
	int		*texture;
	int		width;
	int		height;
	int		width_mask;
	int		height_mask;
}			t_render_data;

typedef struct s_pixel_data
{
	int64_t	floor_xi;
	int64_t	floor_yi;
	int64_t	floor_step_xi;
	int64_t	floor_step_yi;
	int		x;
	int		y;
	int		tx;
	int		ty;
}			t_pixel_data;

typedef struct s_line_data
{
	float	pitch;
	int		real_y;
	bool	render_ceiling;
	float	p;
	float	row_distance;
}			t_line_data;

void		render_pixel_row(t_render_data *rd, t_pixel_data *pd,
				bool render_ceiling);
void		init_pixel_data(t_pixel_data *pd, float floor_x, float floor_y,
				t_vec2f floor_step);
void		init_render_data(t_render_data *rd, t_data *data);
void		calculate_floor_step(t_render_data *rd, float row_distance,
				t_vec2f *floor_step);

#endif