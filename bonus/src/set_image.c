/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:24:42 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/20 21:55:25 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	argb_to_int(t_color color)
{
	int	rgb;

	rgb = 0;
	rgb += color.a << 24;
	rgb += color.r << 16;
	rgb += color.g << 8;
	rgb += color.b;
	return (rgb);
}

void	print_first_background(t_data *data)
{
	int	x;
	int	y;
	int	ceiling_color;
	int	floor_color;

	ceiling_color = argb_to_int(data->graphics.wall_sprite.ceiling_color);
	floor_color = argb_to_int(data->graphics.wall_sprite.floor_color);
	x = 0;
	while (WIN_WIDTH > x)
	{
		y = 0;
		while (WIN_HEIGHT > y)
		{
			if (y < WIN_HEIGHT / 2)
				mlx_set_image_pixel \
				(data->graphics.mlx, data->graphics.game.img_background, x, y, ceiling_color);
			else
				mlx_set_image_pixel \
				(data->graphics.mlx, data->graphics.game.img_background, x, y, floor_color);
			y++;
		}
		x++;
	}
}
