/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:54:33 by asuc              #+#    #+#             */
/*   Updated: 2024/06/17 16:03:13 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_player_movement.h"

void	move_forward(t_data *data)
{
	t_vec2 new;

	new.x = data->player.pos.x + data->player.dir.x * data->player.move_speed;
	new.y = data->player.pos.y + data->player.dir.y * data->player.move_speed;
	if (!check_collision(&data->map, new.x, data->player.pos.y))
		data->player.pos.x = new.x;
	if (!check_collision(&data->map, data->player.pos.x, new.y))
		data->player.pos.y = new.y;
}

void	move_backward(t_data *data)
{
	t_vec2 new;

	new.x = data->player.pos.x - data->player.dir.x * data->player.move_speed;
	new.y = data->player.pos.y - data->player.dir.y * data->player.move_speed;
	if (!check_collision(&data->map, new.x, data->player.pos.y))
		data->player.pos.x = new.x;
	if (!check_collision(&data->map, data->player.pos.x, new.y))
		data->player.pos.y = new.y;
}

void	move_right(t_data *data)
{
	t_vec2 new;

	new.x = data->player.pos.x + data->player.plane.x * data->player.move_speed;
	new.y = data->player.pos.y + data->player.plane.y * data->player.move_speed;
	if (!check_collision(&data->map, new.x, data->player.pos.y))
		data->player.pos.x = new.x;
	if (!check_collision(&data->map, data->player.pos.x, new.y))
		data->player.pos.y = new.y;
}

void	move_left(t_data *data)
{
	t_vec2 new;

	new.x = data->player.pos.x - data->player.plane.x * data->player.move_speed;
	new.y = data->player.pos.y - data->player.plane.y * data->player.move_speed;
	if (!check_collision(&data->map, new.x, data->player.pos.y))
		data->player.pos.x = new.x;
	if (!check_collision(&data->map, data->player.pos.x, new.y))
		data->player.pos.y = new.y;
}

void	rotate(t_player *player, float angle)
{
	float	old_dir_x;
	float	old_plane_x;

	old_plane_x = player->plane.x;
	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(angle) - player->dir.y * sin(angle);
	player->dir.y = old_dir_x * sin(angle) + player->dir.y * cos(angle);
	player->plane.x = player->plane.x * cos(angle) - player->plane.y
		* sin(angle);
	player->plane.y = old_plane_x * sin(angle) + player->plane.y * cos(angle);
}
