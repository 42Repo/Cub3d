/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:24:42 by bgoron            #+#    #+#             */
/*   Updated: 2024/05/05 21:02:47 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.width > x)
	{
		y = 0;
		while (data->map.height > y)
		{
			if (y < data->map.height / 2)
				mlx_set_image_pixel \
				(data->mlx.mlx, data->mlx.img_background, x, y, 0xFF0000FF);
			else
				mlx_set_image_pixel \
				(data->mlx.mlx, data->mlx.img_background, x, y, 0xFF5B3C11);
			y++;
		}
		x++;
	}
}

void	print_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.map_width > x)
	{
		y = 0;
		while (data->map.map_height > y)
		{
			if (data->map.map[y / TILE_SIZE][x / TILE_SIZE] == '1')
				mlx_set_image_pixel \
				(data->mlx.mlx, data->mlx.img_map, x, y, 0xFF202020);
			else
				mlx_set_image_pixel \
				(data->mlx.mlx, data->mlx.img_map, x, y, 0xFF5B3C11);
			y++;
		}
		x++;
	}
}

void	add_player(t_data d)
{
	int	x;
	int	y;

	x = 0;
	while (d.map.map_width > x)
	{
		y = 0;
		while (d.map.map_height > y)
		{
			if ((x > d.player.pos.x - 5 && x < d.player.pos.x + 5) \
				&& (y > d.player.pos.y - 5 && y < d.player.pos.y + 5))
				mlx_set_image_pixel \
				(d.mlx.mlx, d.mlx.img_player, x, y, 0xFF000000);
			else
				mlx_set_image_pixel \
				(d.mlx.mlx, d.mlx.img_player, x, y, 0x00000000);
			y++;
		}
		x++;
	}
}
