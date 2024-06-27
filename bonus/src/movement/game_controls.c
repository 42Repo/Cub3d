/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:58:24 by asuc              #+#    #+#             */
/*   Updated: 2024/06/27 15:35:19 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_player_movement.h"

void	manage_sprint(t_data *data)
{
	if (data->graphics.key_states[SDL_SCANCODE_LCTRL])
	{
		if (data->settings.fov < 91.0)
		{
			data->settings.fov += 0.25;
			data->player.move_speed = 0.08;
		}
	}
	else
	{
		if (data->settings.fov > 90)
		{
			data->settings.fov -= 0.25;
			data->player.move_speed = 0.05;
		}
	}
}

void	move(t_data *data)
{
	manage_sprint(data);
	if (data->graphics.key_states[W])
		move_forward(data);
	if (data->graphics.key_states[S])
		move_backward(data);
	if (data->graphics.key_states[D])
		move_right(data);
	if (data->graphics.key_states[A])
		move_left(data);
	if (data->graphics.key_states[RIGHT])
		rotate(&data->player, -data->player.rot_speed);
	if (data->graphics.key_states[LEFT])
		rotate(&data->player, data->player.rot_speed);
}
