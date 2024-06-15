/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/15 18:14:27 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static inline void	print_background(t_data *data)
{
	int			pitch_shift;
	int			color;
	t_vec2		pos;
	int			start_y;
	int			end_y;
	static int	prev_pitch_shift = 0;

	pitch_shift = (int)(data->player.pitch * WIN_HEIGHT);
	if (pitch_shift > prev_pitch_shift)
	{
		start_y = WIN_HEIGHT / 2 - prev_pitch_shift;
		end_y = WIN_HEIGHT / 2 - pitch_shift;
		color = argb_to_int(data->mlx.wall_sprite.floor_color);
	}
	else
	{
		start_y = WIN_HEIGHT / 2 - pitch_shift;
		end_y = WIN_HEIGHT / 2 - prev_pitch_shift;
		color = argb_to_int(data->mlx.wall_sprite.ceiling_color);
	}
	for (pos.y = end_y; pos.y <= start_y; pos.y++)
	{
		pos.x = 0;
		while (pos.x < WIN_WIDTH)
		{
			if (pos.y < WIN_HEIGHT && pos.y >= 0 && pos.x < WIN_WIDTH && pos.x >= 0)
				mlx_set_image_pixel(data->mlx.mlx, data->mlx.img_background, pos.x, pos.y,
					color);
			pos.x++;
		}
	}
	prev_pitch_shift = pitch_shift;
}

void	render(t_data *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	print_background(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
		data->mlx.img_background, 0, 0);
	render_frame(data);
}

int	update(void *param)
{
	t_data	*d;

	d = (t_data *)param;
	mouse_move(d);
	move(d);
	render(d);
	fps_counter();
	return (0);
}

int	key_press(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == SDL_SCANCODE_ESCAPE)
		exit_game(*data);
	data->mlx.key_states[key] = 1;
	return (0);
}

int	key_release(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->mlx.key_states[key] = 0;
	return (0);
}
