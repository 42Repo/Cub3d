/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:37:15 by asuc              #+#    #+#             */
/*   Updated: 2024/06/25 00:18:46 by bgoron           ###   ########.fr       */
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
			mask[p.y * width + p.x] = (d.x * d.x + d.y * d.y <= radius * radius);
			p.x++;
		}
		p.y++;
	}
}

void	draw_circle(int radius, t_vec2_int center, t_data *data)
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
				p.x = center.x + d.x;
				p.y = center.y + d.y;
				mlx_set_image_pixel(data->graphics.mlx, data->graphics.img_mini_map, p.x, p.y,
					0xFF00FF00);
			}
			d.x++;
		}
		d.y++;
	}
}

void	draw_tip(int radius, int tip_length, int tip_width, t_vec2_int center, int offset, t_data *data)
{
	t_vec2_int	p;
	t_vec2_int	d;

	d.y = 0;
	while (d.y <= tip_length)
	{
		d.x = -tip_width;
		while (d.x <= tip_width)
		{
			if (abs(d.x) <= (tip_length - d.y))
			{
				p.x = center.x + d.x;
				p.y = center.y - radius - d.y + offset;
				mlx_set_image_pixel(data->graphics.mlx, data->graphics.img_mini_map, p.x, p.y,
					0xFF00FF00);
			}
			d.x++;
		}
		d.y++;
	}
}

void	draw_player_marker(t_data *data)
{
	t_vec2_int	center;

	center.x = 10 + (((WIN_HEIGHT * 0.28 / 2 ) / 1.5)) * data->settings.minimap_scale;
	center.y = 10 + (((WIN_HEIGHT * 0.28 / 2 ) / 1.5)) * data->settings.minimap_scale;
	draw_circle(3, center, data);
	draw_tip(3, 5, 3, center, 2, data);
}

void	reset_minimap(t_data *data, int minimap_size)
{
	t_vec2_int	pos;

	pos.y = 0;
	while (pos.y < minimap_size)
	{
		pos.x = 0;
		while (pos.x < minimap_size)
		{
			mlx_set_image_pixel(data->graphics.mlx, data->graphics.img_mini_map, pos.x, pos.y,
				0x00000000);
			pos.x++;
		}
		pos.y++;
	}
}

void	draw_minimap(t_data *data, int minimap_size, int *mask, t_vec2 player_map)
{
	t_vec2_int	pos;
	t_vec2_int	d;
	t_vec2_int	rotated;
	t_vec2		final;
	t_vec2_int	map;
	float		angle;
	float		cos_angle;
	float		sin_angle;
	int 		color;

	angle = atan2(data->player.dir.y, data->player.dir.x);
	cos_angle = cos(angle);
	sin_angle = sin(angle);
	pos.y = 0;
	while (pos.y < minimap_size)
	{
		pos.x = 0;
		while (pos.x < minimap_size)
		{
			if (mask[pos.y * minimap_size + pos.x])
			{
				d.x = pos.x - (((WIN_HEIGHT * 0.28 / 2 ) / 1.5)) * data->settings.minimap_scale;
				d.y = pos.y - (((WIN_HEIGHT * 0.28 / 2 ) / 1.5)) * data->settings.minimap_scale;
				rotated.x = -d.y;
				rotated.y = d.x;
				final.x = cos_angle * rotated.x - sin_angle * rotated.y;
				final.y = sin_angle * rotated.x + cos_angle * rotated.y;
				map.x = player_map.x + final.x / MINIMAP_SCALE * data->settings.minimap_scale;
				map.y = player_map.y + final.y / MINIMAP_SCALE * data->settings.minimap_scale;

				color = 0xFF808080;
				if (map.x >= 0 && map.x < data->map.cols && map.y >= 0
					&& map.y < data->map.rows)
				{
					if (data->map.map[map.y][map.x] == '1')
						color = 0xFFFF0000;
					if (data->map.map[map.y][map.x] == 'D')
						color = 0xFF0000FF;
				}
				mlx_set_image_pixel(data->graphics.mlx, data->graphics.img_mini_map, pos.x, pos.y,
					color);
			}
			pos.x++;
		}
		pos.y++;
	}
}

void	put_minimap(t_data *data, int minimap_size)
{
	t_vec2_int	pos;
	t_vec2_int	window_offset;
	int 		color;

	window_offset.x = 10;
	window_offset.y = 10;
	pos.y = 0;
	while (pos.y < minimap_size)
	{
		pos.x = 0;
		while (pos.x < minimap_size)
		{
			color = mlx_get_image_pixel(data->graphics.mlx,
					data->graphics.img_mini_map, pos.x, pos.y);
			if (color != 0x00000000)
				mlx_pixel_put(data->graphics.mlx, data->graphics.win, window_offset.x + pos.x,
					window_offset.y + pos.y, color);
			pos.x++;
		}
		pos.y++;
	}
}

void	print_minimap(t_data *data)
{
	t_vec2		player_map;
	int 		minimap_size;

	minimap_size = (2 * (((WIN_HEIGHT * 0.28 / 2 ) / 1.5))) * data->settings.minimap_scale;
	int mask[minimap_size * minimap_size];
	create_circular_mask(mask, minimap_size, minimap_size);
	player_map.x = data->player.pos.x;
	player_map.y = data->player.pos.y;
	reset_minimap(data, minimap_size);
	draw_minimap(data, minimap_size, mask, player_map);
	draw_player_marker(data);
	put_minimap(data, minimap_size);
}
