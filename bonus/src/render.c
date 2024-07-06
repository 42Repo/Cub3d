/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:05:34 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/06 16:17:46 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static inline void	set_image(t_vec2f pos, int start_y, int color, t_data *data)
{
	while ((int)pos.y <= start_y)
	{
		pos.x = 0;
		while (pos.x < WIN_WIDTH)
		{
			if (pos.y < WIN_HEIGHT && pos.y >= 0 && pos.x < WIN_WIDTH
				&& pos.x >= 0)
				mlx_set_image_pixel(data->graphics.mlx,
					data->graphics.game.img_background, (int)pos.x, (int)pos.y,
					color);
			pos.x++;
		}
		pos.y++;
	}
}

static void	print_background(t_data *data)
{
	int			pitch_shift;
	int			color;
	t_vec2f		pos;
	int			start_y;
	static int	prev_pitch_shift = 0;

	pitch_shift = (int)(data->player.pitch * WIN_HEIGHT);
	if (pitch_shift > prev_pitch_shift)
	{
		start_y = (int)WIN_HEIGHT / 2 - prev_pitch_shift;
		pos.y = WIN_HEIGHT / 2.0f - (float)pitch_shift;
		color = argb_to_int(data->graphics.wall_sprite.floor_color);
	}
	else
	{
		start_y = (int)WIN_HEIGHT / 2 - pitch_shift;
		pos.y = WIN_HEIGHT / 2.0f - (float)prev_pitch_shift;
		color = argb_to_int(data->graphics.wall_sprite.ceiling_color);
	}
	set_image(pos, start_y, color, data);
	prev_pitch_shift = pitch_shift;
}

void	render(t_data *data)
{
	mlx_clear_window(data->graphics.mlx, data->graphics.win);
	if (data->graphics.game.floor_and_ceiling)
		render_floor_and_ceiling(data);
	else
	{
		print_background(data);
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.game.img_background, 0, 0);
	}
	render_frame(data);
	print_minimap(data);
}
