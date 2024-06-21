/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:37:15 by asuc              #+#    #+#             */
/*   Updated: 2024/06/21 13:00:18 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_minimap.h"

void	create_circular_mask(int *mask, int width, int height)
{
	int			radius;
	t_vec2_int	center;
	t_vec2_int	p;
	t_vec2_int	d;

	radius = width / 2;
	center.x = width / 2;
	center.y = height / 2;
	p.y = 0;
	while (p.y < height)
	{
		p.x = 0;
		while (p.x < width)
		{
			d.x = center.x - p.x;
			d.y = center.y - p.y;
			if (d.x * d.x + d.y * d.y <= radius * radius)
				mask[p.y * width + p.x] = 1;
			else
				mask[p.y * width + p.x] = 0;
			p.x++;
		}
		p.y++;
	}
}

void	draw_circle(int radius, int center_x, int center_y, t_data *data)
{
	t_vec2_int	p;
	t_vec2_int	d;

	d.y = -radius;
	while (d.y <= radius)
	{
		d.x = -radius;
		while (d.x <= radius)
		{
			if (d.x * d.x + d.y * d.y <= radius * radius)
			{
				p.x = center_x + d.x;
				p.y = center_y + d.y;
				mlx_set_image_pixel(data->graphics.mlx, data->graphics.img_mini_map, p.x, p.y,
					0xFF00FF00);
			}
			d.x++;
		}
		d.y++;
	}
}

void	draw_tip(int radius, int tip_length, int tip_width, int center_x, int center_y, int offset, t_data *data)
{
	t_vec2_int	p;
	t_vec2_int	d;

	d.y = 0;
	while (d.y <= tip_length)
	{
		d.x = -tip_width;
		while (d.x <= tip_width)
		{
			if (abs(d.y) <= (tip_length - d.x))
			{
				p.x = center_x + d.y;
				p.y = center_y - radius - d.x + offset;
				mlx_set_image_pixel(data->graphics.mlx, data->graphics.img_mini_map, p.x, p.y,
					0xFF00FF00);
			}
			d.x++;
		}
		d.y++;
	}
}

void	draw_player_marker(t_data *data, int center_x, int center_y)
{
	draw_circle(3, center_x, center_y, data);
	draw_tip(3, 5, 3, center_x, center_y, 2, data);
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