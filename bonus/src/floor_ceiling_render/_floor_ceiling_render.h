/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _floor_ceiling_render.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:39:58 by asuc              #+#    #+#             */
/*   Updated: 2024/06/24 21:53:50 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FLOOR_CEILING_RENDER_H
# define _FLOOR_CEILING_RENDER_H

# include "include.h"
# include <math.h>

typedef struct s_render_data
{
	t_data	*data;
	float	rayDirX0;
	float	rayDirY0;
	float	rayDirX1;
	float	rayDirY1;
	float	centerLine;
	float	posZ;
	int		*texture;
	int		width;
	int		height;
	int		width_mask;
	int		height_mask;
}			t_render_data;

typedef struct s_pixel_data
{
	int64_t	floorXi;
	int64_t	floorYi;
	int64_t	floorStepXi;
	int64_t	floorStepYi;
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
	float	rowDistance;
}			t_line_data;

void		render_pixel_row(t_render_data *rd, t_pixel_data *pd,
				bool render_ceiling);
void		init_pixel_data(t_pixel_data *pd, float floorX, float floorY,
				t_vec2 floor_step);
void		init_render_data(t_render_data *rd, t_data *data);
void		calculate_floor_step(t_render_data *rd, float rowDistance,
				t_vec2 *floor_step);

#endif