/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:42:50 by asuc              #+#    #+#             */
/*   Updated: 2024/06/27 14:09:14 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_floor_ceiling_render.h"

inline void	render_pixel_row(t_render_data *rd, t_pixel_data *pd,
		bool render_ceiling)
{
	const int	SHIFT = 20;
	int			color;

	for (pd->x = 0; pd->x < WIN_WIDTH; ++pd->x)
	{
		pd->tx = ((int)(pd->floor_xi >> (SHIFT - 16)) & 0xFFFF)
			* rd->width >> 16;
		pd->ty = ((int)(pd->floor_yi >> (SHIFT - 16)) & 0xFFFF)
			* rd->height >> 16;
		pd->tx &= rd->width_mask;
		pd->ty &= rd->height_mask;
		if (render_ceiling)
			pd->ty = rd->height - 1 - pd->ty;
		color = rd->texture[rd->width * pd->ty + pd->tx];
		mlx_pixel_put(rd->data->graphics.mlx, rd->data->graphics.win, pd->x,
			pd->y, color);
		pd->floor_xi += pd->floor_step_xi;
		pd->floor_yi += pd->floor_step_yi;
	}
}