/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _player_movement.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:01:25 by asuc              #+#    #+#             */
/*   Updated: 2024/06/14 17:01:58 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PLAYER_MOVEMENT_H
# define _PLAYER_MOVEMENT_H

# include "struct.h"

void	move_forward(t_player *player);
void	move_backward(t_player *player);
void	move_right(t_player *player);
void	move_left(t_player *player);
void	rotate(t_player *player, float angle);

#endif // _PLAYER_MOVEMENT_H