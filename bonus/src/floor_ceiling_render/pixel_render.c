/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 02:42:50 by asuc              #+#    #+#             */
/*   Updated: 2024/06/22 02:43:16 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_floor_ceiling_render.h"

inline void	render_pixel_row(t_render_data *rd, t_pixel_data *pd)
{
	const int	SHIFT = 20;
	int			color;

	for (pd->x = 0; pd->x < WIN_WIDTH; ++pd->x)
	{
		pd->tx = ((int)(pd->floorXi >> (SHIFT - 16)) & 0xFFFF)
			* rd->width >> 16;
		pd->ty = ((int)(pd->floorYi >> (SHIFT - 16)) & 0xFFFF)
			* rd->height >> 16;
		pd->tx &= rd->width_mask;
		pd->ty &= rd->height_mask;
		color = rd->texture[rd->width * pd->ty + pd->tx];
		mlx_pixel_put(rd->data->graphics.mlx, rd->data->graphics.win, pd->x,
			pd->y, color);
		pd->floorXi += pd->floorStepXi;
		pd->floorYi += pd->floorStepYi;
	}
}