/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:58:24 by asuc              #+#    #+#             */
/*   Updated: 2024/06/15 20:29:22 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_player_movement.h"

void	move(t_data *data)
{
	if (data->mlx.key_states[W])
		move_forward(data);
	if (data->mlx.key_states[S])
		move_backward(data);
	if (data->mlx.key_states[D])
		move_right(data);
	if (data->mlx.key_states[A])
		move_left(data);
	if (data->mlx.key_states[LEFT])
		rotate(&data->player, -data->player.rot_speed);
	if (data->mlx.key_states[RIGHT])
		rotate(&data->player, data->player.rot_speed);
}
