/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/11 15:39:01 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static inline void	print_background(t_data *data)
{
	int			pitch_shift;
	int			color;
	int			x;
	int			y;
	int			start_y;
	int			end_y;
	static int	prev_pitch_shift = 0;

	pitch_shift = (int)(data->player.pitch * WIN_HEIGHT);
	if (pitch_shift > prev_pitch_shift)
	{
		start_y = WIN_HEIGHT / 2 - prev_pitch_shift;
		end_y = WIN_HEIGHT / 2 - pitch_shift;
		color = 0xFF5B3C11;
	}
	else
	{
		start_y = WIN_HEIGHT / 2 - pitch_shift;
		end_y = WIN_HEIGHT / 2 - prev_pitch_shift;
		color = 0xFF0000FF;
	}
	for (y = end_y; y <= start_y; y++)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT && y >= 0 && x < WIN_WIDTH && x >= 0)
				mlx_set_image_pixel(data->mlx.mlx, data->mlx.img_background, x, y,
					color);
			x++;
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

void	mouse_move(t_data *data)
{
	int		screen_center_x;
	int		screen_center_y;
	float	old_dir_x;
	float	old_plane_x;
	int		mouse_x;
	int		mouse_y;
	float	sensitivity;
	float	delta_x;
	float	delta_y;

	sensitivity = 0.00075;
	screen_center_x = WIN_WIDTH / 2;
	screen_center_y = WIN_HEIGHT / 2;
	mlx_mouse_get_pos(data->mlx.mlx, &mouse_x, &mouse_y);
	delta_x = (mouse_x - screen_center_x) * sensitivity;
	delta_y = (mouse_y - screen_center_y) * sensitivity;
	old_dir_x = data->player.dir.x;
	data->player.dir.x = data->player.dir.x * cos(-delta_x) - data->player.dir.y
		* sin(-delta_x);
	data->player.dir.y = old_dir_x * sin(-delta_x) + data->player.dir.y
		* cos(-delta_x);
	old_plane_x = data->player.plane.x;
	data->player.plane.x = data->player.plane.x * cos(-delta_x)
		- data->player.plane.y * sin(-delta_x);
	data->player.plane.y = old_plane_x * sin(-delta_x) + data->player.plane.y
		* cos(-delta_x);
	data->player.pitch += delta_y;
	if (data->player.pitch > 1.0f)
		data->player.pitch = 1.0f;
	if (data->player.pitch < -1.0f)
		data->player.pitch = -1.0f;
	mlx_mouse_move(data->mlx.mlx, data->mlx.win, screen_center_x,
		screen_center_y);
}

void	move(t_data *data)
{
	float	old_dir_x;
	float	old_plane_x;

	if (data->mlx.key_states[W])
	{
		data->player.pos.x += data->player.dir.x * data->player.move_speed;
		data->player.pos.y += data->player.dir.y * data->player.move_speed;
	}
	if (data->mlx.key_states[S])
	{
		data->player.pos.x -= data->player.dir.x * data->player.move_speed;
		data->player.pos.y -= data->player.dir.y * data->player.move_speed;
	}
	if (data->mlx.key_states[D])
	{
		data->player.pos.x += data->player.dir.y * data->player.move_speed;
		data->player.pos.y -= data->player.dir.x * data->player.move_speed;
	}
	if (data->mlx.key_states[A])
	{
		data->player.pos.x -= data->player.dir.y * data->player.move_speed;
		data->player.pos.y += data->player.dir.x * data->player.move_speed;
	}
	if (data->mlx.key_states[LEFT])
	{
		old_dir_x = data->player.dir.x;
		data->player.dir.x = data->player.dir.x * cos(-data->player.rot_speed)
			- data->player.dir.y * sin(-data->player.rot_speed);
		data->player.dir.y = old_dir_x * sin(-data->player.rot_speed)
			+ data->player.dir.y * cos(-data->player.rot_speed);
		old_plane_x = data->player.plane.x;
		data->player.plane.x = data->player.plane.x
			* cos(-data->player.rot_speed) - data->player.plane.y
			* sin(-data->player.rot_speed);
		data->player.plane.y = old_plane_x * sin(-data->player.rot_speed)
			+ data->player.plane.y * cos(-data->player.rot_speed);
	}
	if (data->mlx.key_states[RIGHT])
	{
		old_dir_x = data->player.dir.x;
		data->player.dir.x = data->player.dir.x * cos(data->player.rot_speed)
			- data->player.dir.y * sin(data->player.rot_speed);
		data->player.dir.y = old_dir_x * sin(data->player.rot_speed)
			+ data->player.dir.y * cos(data->player.rot_speed);
		old_plane_x = data->player.plane.x;
		data->player.plane.x = data->player.plane.x
			* cos(data->player.rot_speed) - data->player.plane.y
			* sin(data->player.rot_speed);
		data->player.plane.y = old_plane_x * sin(data->player.rot_speed)
			+ data->player.plane.y * cos(data->player.rot_speed);
	}
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
