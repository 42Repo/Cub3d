/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:58:24 by asuc              #+#    #+#             */
/*   Updated: 2024/07/02 01:08:27 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_player_movement.h"

static void	manage_sprint(t_data *data)
{
	if (data->graphics.key_states[data->settings.key_sprint])
	{
		if (data->settings.fov < 91.0f)
		{
			data->settings.fov += 0.5f;
			data->player.move_speed = 0.07f;
		}
	}
	else
	{
		if (data->settings.fov > 90.0f)
		{
			data->settings.fov -= 0.5f;
			data->player.move_speed = 0.05f;
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
