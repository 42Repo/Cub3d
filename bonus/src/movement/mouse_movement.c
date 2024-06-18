/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:21:02 by asuc              #+#    #+#             */
/*   Updated: 2024/06/18 18:34:03 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_player_movement.h"

static void	set_dir_and_plane(t_data *data, float delta)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = data->player.dir.x;
	data->player.dir.x = data->player.dir.x * cos(delta)
		- data->player.dir.y * sin(delta);
	data->player.dir.y = old_dir_x * sin(delta) + data->player.dir.y
		* cos(delta);
	old_plane_x = data->player.plane.x;
	data->player.plane.x = data->player.plane.x * cos(delta)
		- data->player.plane.y * sin(delta);
	data->player.plane.y = old_plane_x * sin(delta) + data->player.plane.y
		* cos(delta);
}

void	mouse_move(t_data *data)
{
	t_vec2_int	mouse;
	t_vec2		delta;
	t_vec2		screen_center;
	float		sensitivity;

	sensitivity = 0.00075;
	screen_center.x = WIN_WIDTH / 2;
	screen_center.y = WIN_HEIGHT / 2;
	mlx_mouse_get_pos(data->mlx.mlx, &mouse.x, &mouse.y);
	delta.x = (mouse.x - screen_center.x) * sensitivity;
	delta.y = (mouse.y - screen_center.y) * sensitivity;
	set_dir_and_plane(data, delta.x);
	data->player.pitch += delta.y;
	if (data->player.pitch > 1.0f)
		data->player.pitch = 1.0f;
	if (data->player.pitch < -1.0f)
		data->player.pitch = -1.0f;
	mlx_mouse_move(data->mlx.mlx, data->mlx.win, screen_center.x,
		screen_center.y);
}
