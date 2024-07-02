/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:21:02 by asuc              #+#    #+#             */
/*   Updated: 2024/07/02 05:03:16 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_player_movement.h"

static void	set_dir_and_plane(t_data *data, float delta)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = data->player.dir.x;
	data->player.dir.x = data->player.dir.x * cosf(delta)
		- data->player.dir.y * sinf(delta);
	data->player.dir.y = old_dir_x * sinf(delta) + data->player.dir.y
		* cosf(delta);
	old_plane_x = data->player.plane.x;
	data->player.plane.x = data->player.plane.x * cosf(delta)
		- data->player.plane.y * sinf(delta);
	data->player.plane.y = old_plane_x * sinf(delta) + data->player.plane.y
		* cosf(delta);
}

void	mouse_move(t_data *data)
{
	t_vec2i	mouse;
	t_vec2f	delta;
	t_vec2f	screen_center;
	float	sensitivity;

	sensitivity = 0.00075f;
	screen_center.x = WIN_WIDTH / 2.0f;
	screen_center.y = WIN_HEIGHT / 2.0f;
	mlx_mouse_get_pos(data->graphics.mlx, &mouse.x, &mouse.y);
	delta.x = ((float)mouse.x - screen_center.x) * sensitivity;
	delta.y = ((float)mouse.y - screen_center.y) * sensitivity;
	set_dir_and_plane(data, delta.x);
	data->player.pitch += delta.y;
	if (data->player.pitch > 1.0f)
		data->player.pitch = 1.0f;
	if (data->player.pitch < -1.0f)
		data->player.pitch = -1.0f;
	mlx_mouse_move(data->graphics.mlx, data->graphics.win, (int)screen_center.x,
		(int)screen_center.y);
}
