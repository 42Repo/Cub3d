/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:42:52 by asuc              #+#    #+#             */
/*   Updated: 2024/07/02 05:58:39 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_floor_ceiling_render.h"

inline void	init_pixel_data(t_pixel_data *pd, float floor_x,
		float floor_y, t_vec2f floor_step)
{
	const int	shift = 20;
	const int	fixed_1 = 1 << shift;

	pd->floor_xi = (int64_t)(floor_x * (float)fixed_1);
	pd->floor_yi = (int64_t)(floor_y * (float)fixed_1);
	pd->floor_step_xi = (int64_t)(floor_step.x * (float)fixed_1);
	pd->floor_step_yi = (int64_t)(floor_step.y * (float)fixed_1);
}

inline void	init_render_data(t_render_data *rd, t_data *data)
{
	rd->data = data;
	rd->ray_dir_x0 = data->player.dir.x - data->player.plane.x;
	rd->ray_dir_y0 = data->player.dir.y - data->player.plane.y;
	rd->ray_dir_x1 = data->player.dir.x + data->player.plane.x;
	rd->ray_dir_y1 = data->player.dir.y + data->player.plane.y;
	rd->center_line = WIN_HEIGHT / 2.0f;
	rd->pos_z = 0.5f * WIN_HEIGHT;
}

inline void	calculate_floor_step(t_render_data *rd, float row_distance,
		t_vec2f *floor_step)
{
	floor_step->x = row_distance * (rd->ray_dir_x1 - rd->ray_dir_x0) \
	/ WIN_WIDTH;
	floor_step->y = row_distance * (rd->ray_dir_y1 - rd->ray_dir_y0) \
	/ WIN_WIDTH;
}
