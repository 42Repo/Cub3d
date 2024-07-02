/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:37:15 by asuc              #+#    #+#             */
/*   Updated: 2024/07/02 05:09:21 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_minimap.h"

static void	reset_minimap(t_data *data, int size)
{
	t_vec2i	pos;

	pos.y = 0;
	while (pos.y < size)
	{
		pos.x = 0;
		while (pos.x < size)
		{
			mlx_set_image_pixel(data->graphics.mlx, \
			data->graphics.img_mini_map, pos.x, pos.y,
				0x00000000);
			pos.x++;
		}
		pos.y++;
	}
}

static void	draw_minimap(t_data *data, int size, int *mask, t_vec2f player_map)
{
	t_vec2i	pos;

	pos.y = 0;
	while (pos.y < size)
	{
		pos.x = 0;
		while (pos.x < size)
		{
			set_minimap_pixel(data, mask, pos, player_map);
			pos.x++;
		}
		pos.y++;
	}
}

static void	put_minimap(t_data *data, int size)
{
	t_vec2i	pos;
	t_vec2i	window_offset;
	int		color;

	window_offset.x = 10;
	window_offset.y = 10;
	pos.y = 0;
	while (pos.y < size)
	{
		pos.x = 0;
		while (pos.x < size)
		{
			color = mlx_get_image_pixel(data->graphics.mlx, \
					data->graphics.img_mini_map, pos.x, pos.y);
			if (color != 0x00000000)
				mlx_pixel_put(data->graphics.mlx, \
				data->graphics.win, window_offset.x + pos.x,
					window_offset.y + pos.y, color);
			pos.x++;
		}
		pos.y++;
	}
}

void	print_minimap(t_data *data)
{
	t_vec2f	player_map;
	int		size;
	int		*mask;

	size = (int)((WIN_HEIGHT * 0.56f / 3.0f) * data->settings.minimap_scale);
	mask = malloc(sizeof(int) * (unsigned int)size * (unsigned int)size);
	create_circular_mask(mask, size, size);
	player_map.x = data->player.pos.x;
	player_map.y = data->player.pos.y;
	reset_minimap(data, size);
	draw_minimap(data, size, mask, player_map);
	draw_player_marker(data);
	put_minimap(data, size);
	free(mask);
}
