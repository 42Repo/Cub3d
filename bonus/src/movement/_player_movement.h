/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _player_movement.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:01:25 by asuc              #+#    #+#             */
/*   Updated: 2024/07/02 01:13:05 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PLAYER_MOVEMENT_H
# define _PLAYER_MOVEMENT_H

# include "include.h"

void	move_forward(t_data *data);
void	move_backward(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	rotate(t_player *player, float angle);
int		check_collision(t_map *map, float x, float y) __attribute__((pure));

#endif // _PLAYER_MOVEMENT_H