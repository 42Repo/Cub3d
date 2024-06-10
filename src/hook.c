/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/10 16:10:51 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

// static inline void	print_background(t_data *data)
// {
// 	int	pitch_shift;
// 	int	color;
// 	int x;
// 	int y;

// 	pitch_shift = (int)(data->player.pitch * WIN_HEIGHT);
// 	y = 0;
// 	while (y < WIN_HEIGHT)
// 	{
// 		x = 0;
// 		color = mlx_get_image_pixel(data->mlx.mlx, data->mlx.img_background, 0,
// 				y);
// 		if (y + pitch_shift < WIN_HEIGHT / 2 && color == 0x0000FF)
// 			continue ;
// 		else if (color == 0x5B3C11)
// 			continue ;
// 		if (y + pitch_shift < WIN_HEIGHT / 2)
// 			color = 0xFF0000FF; // Sky color
// 		else
// 			color = 0xFF5B3C11; // Ground color
// 		while (x < WIN_WIDTH)
// 		{
// 			mlx_pixel_put(data->mlx.mlx, data->mlx.win, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

static inline void	print_background(t_data *data)
{
	int			pitch_shift;
	int			color;
	int			x;
	int			y;
	static int	old_pitch;
	int			min_y;
	int			max_y;

	pitch_shift = (int)(data->player.pitch * WIN_HEIGHT);
	min_y = (WIN_HEIGHT / 2 - old_pitch - (WIN_HEIGHT / 4) < 0) ? 0 : WIN_HEIGHT
		/ 2 - old_pitch - (WIN_HEIGHT / 4);
	max_y = (WIN_HEIGHT / 2 - old_pitch + (WIN_HEIGHT
				/ 4) >= WIN_HEIGHT) ? WIN_HEIGHT - 1 : WIN_HEIGHT / 2
		- old_pitch + (WIN_HEIGHT / 4);
	old_pitch = pitch_shift;
	for (y = min_y; y <= max_y; y++)
	{
		x = 0;
		color = mlx_get_image_pixel(data->mlx.mlx, data->mlx.img_background, x,
				y);
		if (y + pitch_shift < WIN_HEIGHT / 2 && color != 0x0000FF)
			color = 0xFF0000FF;
		else if (y + pitch_shift >= WIN_HEIGHT / 2 && color != 0x5B3C11)
			color = 0xFF5B3C11;
		while (x < WIN_WIDTH)
		{
			mlx_set_image_pixel(data->mlx.mlx, data->mlx.img_background, x, y,
				color);
			x++;
		}
	}
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
		mlx_loop_end(data->mlx.mlx);
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
