/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/10 17:02:54 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"


void	render(t_data *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
		data->mlx.img_background, 0, 0);
	render_frame(data);
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
