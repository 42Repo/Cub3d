/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:37:15 by asuc              #+#    #+#             */
/*   Updated: 2024/06/19 05:38:51 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_minimap.h"

void	create_circular_mask(int *mask, int width, int height)
{
	int	radius;
	int	center_x;
	int	center_y;
	int	dx;
	int	dy;

	radius = width / 2;
	center_x = width / 2;
	center_y = height / 2;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			dx = center_x - x;
			dy = center_y - y;
			if (dx * dx + dy * dy <= radius * radius)
			{
				mask[y * width + x] = 1;
			}
			else
			{
				mask[y * width + x] = 0;
			}
		}
	}
}

void	draw_minimap(t_data *data)
{
	int minimap_size = 2 * MINIMAP_RADIUS;
	int mask[minimap_size * minimap_size];
	create_circular_mask(mask, minimap_size, minimap_size);

	int player_map_x = (int)data->player.pos.x;
	int player_map_y = (int)data->player.pos.y;

	for (int y = 0; y < minimap_size; y++)
	{
		for (int x = 0; x < minimap_size; x++)
		{
			mlx_set_image_pixel(data->mlx.mlx, data->mlx.img_mini_map, x, y,
				0x00000000);
		}
	}

	float angle = atan2(data->player.dir.y, data->player.dir.x) + M_PI_2;
	float cos_angle = cos(angle);
	float sin_angle = sin(angle);

	for (int dy = -MINIMAP_RADIUS; dy < MINIMAP_RADIUS; dy++)
	{
		for (int dx = -MINIMAP_RADIUS; dx < MINIMAP_RADIUS; dx++)
		{
			int map_x = player_map_x + dx / MINIMAP_SCALE;
			int map_y = player_map_y + dy / MINIMAP_SCALE;

			int rotated_x = cos_angle * dx + sin_angle * dy;
			int rotated_y = -sin_angle * dx + cos_angle * dy;
			int minimap_x = MINIMAP_RADIUS + rotated_x;
			int minimap_y = MINIMAP_RADIUS + rotated_y;

			if (minimap_x >= 0 && minimap_x < minimap_size && minimap_y >= 0
				&& minimap_y < minimap_size)
			{
				if (mask[minimap_y * minimap_size + minimap_x])
				{
					int color = 0xFF808080;
					if (map_x >= 0 && map_x < data->map.cols && map_y >= 0
						&& map_y < data->map.rows)
					{
						if (data->map.map[map_y][map_x] == '1')
						{
							color = 0xFFFF0000;
						}
					}
					mlx_pixel_put(data->mlx.mlx, data->mlx.win,
						minimap_x, minimap_y, color);
				}
			}
		}
	}
	for (int y = -2; y <= 2; y++)
	{
		for (int x = -2; x <= 2; x++)
		{
			if (mask[(MINIMAP_RADIUS + y) * minimap_size + (MINIMAP_RADIUS
					+ x)])
			{
				mlx_pixel_put(data->mlx.mlx, data->mlx.win,
					 MINIMAP_RADIUS + x,  MINIMAP_RADIUS + y, 0xFF00FF00);
			}
		}
	}
}