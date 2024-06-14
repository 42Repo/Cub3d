/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:58:24 by asuc              #+#    #+#             */
/*   Updated: 2024/06/14 18:22:45 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_player_movement.h"

void	move(t_data *data)
{
	if (data->mlx.key_states[W])
		move_forward(&data->player);
	if (data->mlx.key_states[S])
		move_backward(&data->player);
	if (data->mlx.key_states[D])
		move_right(&data->player);
	if (data->mlx.key_states[A])
		move_left(&data->player);
	if (data->mlx.key_states[LEFT])
		rotate(&data->player, -data->player.rot_speed);
	if (data->mlx.key_states[RIGHT])
		rotate(&data->player, data->player.rot_speed);
}
