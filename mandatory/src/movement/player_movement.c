/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:54:33 by asuc              #+#    #+#             */
/*   Updated: 2024/06/18 19:54:32 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	move_forward(t_player *player)
{
	player->pos.x += player->dir.x * player->move_speed;
	player->pos.y += player->dir.y * player->move_speed;
}

void	move_backward(t_player *player)
{
	player->pos.x -= player->dir.x * player->move_speed;
	player->pos.y -= player->dir.y * player->move_speed;
}

void	move_right(t_player *player)
{
	player->pos.x -= player->dir.y * player->move_speed;
	player->pos.y += player->dir.x * player->move_speed;
}

void	move_left(t_player *player)
{
	player->pos.x += player->dir.y * player->move_speed;
	player->pos.y -= player->dir.x * player->move_speed;
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
