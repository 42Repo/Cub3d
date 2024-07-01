/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:58:24 by asuc              #+#    #+#             */
/*   Updated: 2024/07/01 15:00:57 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_player_movement.h"

void	manage_sprint(t_data *data)
{
	if (data->graphics.key_states[data->settings.key_sprint])
	{
		if (data->settings.fov < 91.0)
		{
			data->settings.fov += 0.25;
			data->player.move_speed = 0.07;
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
	if (data->graphics.key_states[data->settings.key_move_forward])
		move_forward(data);
	if (data->graphics.key_states[data->settings.key_move_backward])
		move_backward(data);
	if (data->graphics.key_states[data->settings.key_move_right])
		move_right(data);
	if (data->graphics.key_states[data->settings.key_move_left])
		move_left(data);
	if (data->graphics.key_states[data->settings.key_rotate_left])
		rotate(&data->player, -data->player.rot_speed);
	if (data->graphics.key_states[data->settings.key_rotate_right])
		rotate(&data->player, data->player.rot_speed);
}
