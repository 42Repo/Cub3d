/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:21:02 by asuc              #+#    #+#             */
/*   Updated: 2024/06/15 16:15:45 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_player_movement.h"

void	mouse_move(t_data *data)
{
	t_vec2	screen_center;
	float	old_dir_x;
	float	old_plane_x;
	int		mouse_x;
	int		mouse_y;
	float	sensitivity;
	float	delta_x;
	float	delta_y;

	sensitivity = 0.00075;
	screen_center.x = WIN_WIDTH / 2;
	screen_center.y = WIN_HEIGHT / 2;
	mlx_mouse_get_pos(data->mlx.mlx, &mouse_x, &mouse_y);
	delta_x = (mouse_x - screen_center.x) * sensitivity;
	delta_y = (mouse_y - screen_center.y) * sensitivity;
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
	mlx_mouse_move(data->mlx.mlx, data->mlx.win, screen_center.x,
		screen_center.y);
}
