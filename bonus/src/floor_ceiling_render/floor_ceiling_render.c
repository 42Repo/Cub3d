/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_render.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:42:48 by asuc              #+#    #+#             */
/*   Updated: 2024/07/06 16:28:23 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_floor_ceiling_render.h"

static inline void	set_texture_data(t_render_data *rd, bool render_ceiling)
{
	t_sprite	*sprite;

	sprite = &rd->data->graphics.wall_sprite;
	if (render_ceiling)
	{
		rd->texture = sprite->ceiling_texture;
		rd->width = sprite->ceiling.width;
		rd->height = sprite->ceiling.height;
	}
	else
	{
		rd->texture = sprite->floor_texture;
		rd->width = sprite->floor.width;
		rd->height = sprite->floor.height;
	}
	rd->width_mask = rd->width - 1;
	rd->height_mask = rd->height - 1;
}

static inline void	calculate_line_data(t_render_data *rd, int y,
		t_line_data *ld)
{
	ld->pitch = rd->data->player.pitch;
	ld->real_y = (int)((float)y + ld->pitch * WIN_HEIGHT);
	if ((float)ld->real_y < rd->center_line)
	{
		ld->render_ceiling = true;
		ld->p = rd->center_line - (float)ld->real_y;
	}
	else
	{
		ld->render_ceiling = false;
		ld->p = (float)ld->real_y - rd->center_line;
	}
	if (fabsf(ld->p) < FLT_EPSILON)
		ld->p = FLT_EPSILON;
	ld->row_distance = rd->pos_z / ld->p;
}

static inline void	prepare_pixel_data(t_render_data *rd, t_line_data *ld,
		t_pixel_data *pd, int y)
{
	t_vec2f	floor_step;
	t_vec2f	floor_pos;

	calculate_floor_step(rd, ld->row_distance, &floor_step);
	floor_pos.x = rd->data->player.pos.x + ld->row_distance * rd->ray_dir_x0;
	floor_pos.y = rd->data->player.pos.y + ld->row_distance * rd->ray_dir_y0;
	init_pixel_data(pd, floor_pos.x, floor_pos.y, floor_step);
	pd->y = y;
}

static inline void	render_horizontal_line(t_render_data *rd, int y)
{
	t_line_data		ld;
	t_pixel_data	pd;

	calculate_line_data(rd, y, &ld);
	set_texture_data(rd, ld.render_ceiling);
	prepare_pixel_data(rd, &ld, &pd, y);
	render_pixel_row(rd, &pd, ld.render_ceiling);
}

inline void	render_floor_and_ceiling(t_data *data)
{
	t_render_data	rd;
	int				i;

	i = 0;
	init_render_data(&rd, data);
	while (i < (int)WIN_HEIGHT)
	{
		render_horizontal_line(&rd, i);
		i++;
	}
}
