/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:37:39 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/27 15:38:08 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_minimap.h"

void	draw_circle(int radius, t_vec2i center, t_data *data)
{
	t_vec2i	p;
	t_vec2i	d;

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
				mlx_set_image_pixel(data->graphics.mlx, \
				data->graphics.img_mini_map, p.x, p.y, 0xFF00FF00);
			}
			d.x++;
		}
		d.y++;
	}
}

void	draw_tip(t_vec2i center, t_data *data)
{
	t_vec2i	p;
	t_vec2i	d;

	d.y = 0;
	while (d.y <= 5)
	{
		d.x = -3;
		while (d.x <= 3)
		{
			if (abs(d.x) <= (5 - d.y))
			{
				p.x = center.x + d.x;
				p.y = center.y - 3 - d.y + 2;
				mlx_set_image_pixel(data->graphics.mlx, \
				data->graphics.img_mini_map, p.x, p.y,
					0xFF00FF00);
			}
			d.x++;
		}
		d.y++;
	}
}

void	draw_player_marker(t_data *data)
{
	t_vec2i	center;

	center.x = (WIN_HEIGHT * 0.28 / 3) * data->settings.minimap_scale;
	center.y = (WIN_HEIGHT * 0.28 / 3) * data->settings.minimap_scale;
	draw_circle(3, center, data);
	draw_tip(center, data);
}
