/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:54:33 by asuc              #+#    #+#             */
/*   Updated: 2024/07/02 01:11:58 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_player_movement.h"

void	move_forward(t_data *data)
{
	t_vec2f	new;

	new.x = data->player.pos.x + data->player.dir.x * data->player.move_speed;
	new.y = data->player.pos.y + data->player.dir.y * data->player.move_speed;
	if (!check_collision(&data->map, new.x, data->player.pos.y))
		data->player.pos.x = new.x;
	if (!check_collision(&data->map, data->player.pos.x, new.y))
		data->player.pos.y = new.y;
}

void	move_backward(t_data *data)
{
	t_vec2f	new;

	new.x = data->player.pos.x - data->player.dir.x * data->player.move_speed;
	new.y = data->player.pos.y - data->player.dir.y * data->player.move_speed;
	if (!check_collision(&data->map, new.x, data->player.pos.y))
		data->player.pos.x = new.x;
	if (!check_collision(&data->map, data->player.pos.x, new.y))
		data->player.pos.y = new.y;
}

void	move_right(t_data *data)
{
	t_vec2f	new;

	new.x = data->player.pos.x + data->player.plane.x * data->player.move_speed;
	new.y = data->player.pos.y + data->player.plane.y * data->player.move_speed;
	if (!check_collision(&data->map, new.x, data->player.pos.y))
		data->player.pos.x = new.x;
	if (!check_collision(&data->map, data->player.pos.x, new.y))
		data->player.pos.y = new.y;
}

void	move_left(t_data *data)
{
	t_vec2f	new;

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
	player->dir.x = player->dir.x * cosf(angle) - player->dir.y * sinf(angle);
	player->dir.y = old_dir_x * sinf(angle) + player->dir.y * cosf(angle);
	player->plane.x = player->plane.x * cosf(angle) - player->plane.y
		* sinf(angle);
	player->plane.y = old_plane_x * sinf(angle) + player->plane.y * cosf(angle);
}
