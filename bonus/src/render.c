/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:05:34 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/18 16:11:27 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static inline void	set_image(t_vec2 pos, int start_y, int color, t_data *data)
{
	while (pos.y <= start_y)
	{
		pos.x = 0;
		while (pos.x < WIN_WIDTH)
		{
			if (pos.y < WIN_HEIGHT && pos.y >= 0 && pos.x < WIN_WIDTH
				&& pos.x >= 0)
				mlx_set_image_pixel(data->mlx.mlx, data->mlx.img_background,
					pos.x, pos.y, color);
			pos.x++;
		}
		pos.y++;
	}
}

static inline void	print_background(t_data *data)
{
	int			pitch_shift;
	int			color;
	t_vec2		pos;
	int			start_y;
	static int	prev_pitch_shift = 0;

	pitch_shift = (int)(data->player.pitch * WIN_HEIGHT);
	if (pitch_shift > prev_pitch_shift)
	{
		start_y = WIN_HEIGHT / 2 - prev_pitch_shift;
		pos.y = WIN_HEIGHT / 2 - pitch_shift;
		color = argb_to_int(data->mlx.wall_sprite.floor_color);
	}
	else
	{
		start_y = WIN_HEIGHT / 2 - pitch_shift;
		pos.y = WIN_HEIGHT / 2 - prev_pitch_shift;
		color = argb_to_int(data->mlx.wall_sprite.ceiling_color);
	}
	set_image(pos, start_y, color, data);
	prev_pitch_shift = pitch_shift;
}

void	render(t_data *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	render_frame(data);
	print_background(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
		data->mlx.img_background, 0, 0);
	// DRAW MINI MAP A FAIRE
	// mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
	// 	data->mlx.img_mini_map, WIN_WIDTH - 200 - 10, 10);
}
