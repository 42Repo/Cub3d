/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:24:42 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/15 17:18:27 by bgoron           ###   ########.fr       */
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

	ceiling_color = argb_to_int(data->mlx.wall_sprite.ceiling_color);
	floor_color = argb_to_int(data->mlx.wall_sprite.floor_color);
	x = 0;
	while (data->map.width > x)
	{
		y = 0;
		while (data->map.height > y)
		{
			if (y < data->map.height / 2)
				mlx_set_image_pixel \
				(data->mlx.mlx, data->mlx.img_background, x, y, ceiling_color);
			else
				mlx_set_image_pixel \
				(data->mlx.mlx, data->mlx.img_background, x, y, floor_color);
			y++;
		}
		x++;
	}
}

