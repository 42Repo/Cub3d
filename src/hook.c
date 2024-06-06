/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/06 19:51:45 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	render(t_data *data)
{
	// mlx_clear_window(data->mlx.mlx, data->mlx.win);
	add_player(*data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
		data->mlx.img_background, 0, 0);
	render_frame(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img_wall, 0,
		0);
	// 2D
	// mlx_put_image_to_window
	// 	(data->mlx.mlx, data->mlx.win, data->mlx.img_map, 0, 0);
	// mlx_put_image_to_window
	// 	(data->mlx.mlx, data->mlx.win, data->mlx.img_player, 0, 0);
}

void	move(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

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
	if (data->mlx.key_states[A])
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
	// if (key == SDL_SCANCODE_MINUS)
	// 	data->mlx.ray_nb /= 1 + (data->mlx.ray_nb > 1);
	// if (key == SDL_SCANCODE_EQUALS)
	// 	data->mlx.ray_nb *= 1 + ((int)data->mlx.ray_nb < data->map.width);
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
