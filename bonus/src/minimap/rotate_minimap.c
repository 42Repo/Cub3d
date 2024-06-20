/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:37:15 by asuc              #+#    #+#             */
/*   Updated: 2024/06/21 01:27:31 by asuc             ###   ########.fr       */
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

void	draw_player_marker(t_data *data, int center_x, int center_y)
{
	int	radius;
	int	tip_length;
	int	tip_width;
	int	offset;
	int	x;
	int	y;

	radius = 3;
	tip_length = 5;
	tip_width = 3;
	offset = 2;
	for (int dy = -radius; dy <= radius; dy++)
	{
		for (int dx = -radius; dx <= radius; dx++)
		{
			if (dx * dx + dy * dy <= radius * radius)
			{
				x = center_x + dx;
				y = center_y + dy;
				mlx_set_image_pixel(data->graphics.mlx, data->graphics.img_mini_map, x, y,
					0xFF00FF00);
			}
		}
	}
	for (int i = 0; i <= tip_length; i++)
	{
		for (int j = -tip_width; j <= tip_width; j++)
		{
			if (abs(j) <= (tip_length - i))
			{
				x = center_x + j;
				y = center_y - radius - i + offset;
				mlx_set_image_pixel(data->graphics.mlx, data->graphics.img_mini_map, x, y,
					0xFF00FF00);
			}
		}
	}
}

void	draw_minimap(t_data *data)
{
	int minimap_size = (2 * (((WIN_HEIGHT * 0.28 / 2 ) / 1.5))) * data->settings.minimap_scale;
	int mask[minimap_size * minimap_size];
	create_circular_mask(mask, minimap_size, minimap_size);

	float player_map_x = data->player.pos.x;
	float player_map_y = data->player.pos.y;

	for (int y = 0; y < minimap_size; y++)
	{
		for (int x = 0; x < minimap_size; x++)
		{
			mlx_set_image_pixel(data->graphics.mlx, data->graphics.img_mini_map, x, y,
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
				int dx = x - (((WIN_HEIGHT * 0.28 / 2 ) / 1.5)) * data->settings.minimap_scale;
				int dy = y - (((WIN_HEIGHT * 0.28 / 2 ) / 1.5)) * data->settings.minimap_scale;
				int rotated_x = -dy;
				int rotated_y = dx;
				float final_x = cos_angle * rotated_x - sin_angle * rotated_y;
				float final_y = sin_angle * rotated_x + cos_angle * rotated_y;
				int map_x = player_map_x + final_x / MINIMAP_SCALE * data->settings.minimap_scale;
				int map_y = player_map_y + final_y / MINIMAP_SCALE * data->settings.minimap_scale;

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
				mlx_set_image_pixel(data->graphics.mlx, data->graphics.img_mini_map, x, y,
					color);
			}
		}
	}
	draw_player_marker(data, (((WIN_HEIGHT * 0.28 / 2 ) / 1.5)) * data->settings.minimap_scale, (((WIN_HEIGHT * 0.28 / 2 ) / 1.5)) * data->settings.minimap_scale);
	int window_offset_x = 10;
	int window_offset_y = 10;
	for (int y = 0; y < minimap_size; y++)
	{
		for (int x = 0; x < minimap_size; x++)
		{
			int color = mlx_get_image_pixel(data->graphics.mlx,
					data->graphics.img_mini_map, x, y);
			if (color != 0x00000000)
				mlx_pixel_put(data->graphics.mlx, data->graphics.win, window_offset_x + x,
					window_offset_y + y, color);
		}
	}
}