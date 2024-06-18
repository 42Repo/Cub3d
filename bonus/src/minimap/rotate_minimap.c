/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 22:37:15 by asuc              #+#    #+#             */
/*   Updated: 2024/06/18 14:49:07 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_minimap.h"
#include "include.h"

void	draw_pixel(void *img, int x, int y, int color, t_data *d)
{
    if (x >= 0 && x < MINIMAP_SIZE && y >= 0 && y < MINIMAP_SIZE)
        mlx_set_image_pixel(d->mlx.mlx, img, x, y, color);
}

void	draw_square(void *img, int x, int y, int size, int color, t_data *data)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			draw_pixel(img, x + i, y + j, color, data);
}

t_vec2	rotate_point(t_vec2 point, float angle)
{
	t_vec2	new_point;
	new_point.x = point.x * cos(angle) - point.y * sin(angle);
	new_point.y = point.x * sin(angle) + point.y * cos(angle);
	return (new_point);
}

void	update_minimap(t_data *d)
{
	int		map_size = 200;
	float	scale = map_size / (float)fmax(d->map.rows, d->map.cols);
	t_vec2	player_pos = {d->player.pos.x * scale, d->player.pos.y * scale};
	float	angle = atan2(d->player.dir.y, d->player.dir.x);

    for (int i = 0; i < MINIMAP_SIZE; i++)
    {
        for (int j = 0; j < MINIMAP_SIZE; j++)
            mlx_set_image_pixel(d->mlx.mlx, d->mlx.img_mini_map, i, j, 0x00000000);
    }
    
	for (int i = 0; i < d->map.rows; i++)
	{
		for (int j = 0; j < d->map.cols; j++)
		{
			if (d->map.map[i][j] == '1')
			{
				t_vec2 pos = {j * scale, i * scale};
				pos = rotate_point((t_vec2){pos.x - player_pos.x, pos.y - player_pos.y}, angle);
				pos.x += map_size / 2;
				pos.y += map_size / 2;
				draw_square(d->mlx.img_mini_map, pos.x, pos.y, scale, 0xFFFFFFFF, d);
			}
		}
	}

	// Draw player
	draw_square(d->mlx.img_mini_map, map_size / 2 - 2, map_size / 2 - 2, 4, 0xFFFF0000, d);

	// Display minimap
	mlx_put_image_to_window(d->mlx.mlx, d->mlx.win, d->mlx.img_mini_map, WIN_WIDTH - map_size - 10, 10);
}