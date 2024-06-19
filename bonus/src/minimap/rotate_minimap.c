/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:37:15 by asuc              #+#    #+#             */
/*   Updated: 2024/06/19 19:02:01 by asuc             ###   ########.fr       */
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
	float angle = atan2(data->player.dir.y, data->player.dir.x);
	float cos_angle = cos(angle);
	float sin_angle = sin(angle);

	for (int y = 0; y < minimap_size; y++)
	{
		for (int x = 0; x < minimap_size; x++)
		{
			if (mask[y * minimap_size + x])
			{
				int dx = x - MINIMAP_RADIUS;
				int dy = y - MINIMAP_RADIUS;
				int rotated_x = -dy;
				int rotated_y = dx;
				float final_x = cos_angle * rotated_x - sin_angle * rotated_y;
				float final_y = sin_angle * rotated_x + cos_angle * rotated_y;
				int map_x = player_map_x + final_x / MINIMAP_SCALE + 0.5;
				int map_y = player_map_y + final_y / MINIMAP_SCALE + 0.5;

				int color = 0xFF808080;
				if (map_x >= 0 && map_x < data->map.cols && map_y >= 0
					&& map_y < data->map.rows)
				{
					if (data->map.map[map_y][map_x] == '1')
					{
						color = 0xFFFF0000;
					}
					if (data->map.map[map_y][map_x] == 'D')
					{
						color = 0xFF0000FF;
					}
				}
				mlx_set_image_pixel(data->mlx.mlx, data->mlx.img_mini_map,
					x, y, color);
			}
		}
	}

	for (int y = -2; y <= 2; y++)
	{
		for (int x = -2; x <= 2; x++)
		{
			int px = MINIMAP_RADIUS + x;
			int py = MINIMAP_RADIUS + y;
			if (px >= 0 && px < minimap_size && py >= 0 && py < minimap_size &&
				mask[py * minimap_size + px])
			{
				mlx_set_image_pixel(data->mlx.mlx, data->mlx.img_mini_map,
					px, py, 0xFF00FF00);
			}
		}
	}
	for (int y = 0; y < minimap_size; y++)
	{
		for (int x = 0; x < minimap_size; x++)
		{
			int color = mlx_get_image_pixel(data->mlx.mlx, data->mlx.img_mini_map, x, y);
			if (color != 0x00000000)
				mlx_pixel_put(data->mlx.mlx, data->mlx.win, x, y, color);
		}
	}
}