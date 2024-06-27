/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _minimap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:38:13 by asuc              #+#    #+#             */
/*   Updated: 2024/06/27 15:38:36 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINIMAP_H
# define _MINIMAP_H

# define MINIMAP_SCALE 30
# define MINIMAP_RADIUS 100

# include "struct.h"

void	draw_player_marker(t_data *data);

#endif // _MINIMAP_H