/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preload_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:42:33 by asuc              #+#    #+#             */
/*   Updated: 2024/06/21 23:06:32 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	load_texture_data(void *mlx, t_image wall_img, int *texture)
{
	int	x;
	int	y;

	y = 0;
	while (y < wall_img.height)
	{
		x = 0;
		while (x < wall_img.width)
		{
			texture[y * wall_img.width + x] = mlx_get_image_pixel(mlx,
					wall_img.img, x, y);
			x++;
		}
		y++;
	}
}

void	preload_texture(t_data *data, t_image wall_img, int **texture)
{
	*texture = malloc(wall_img.width * wall_img.height * sizeof(int));
	load_texture_data(data->graphics.mlx, wall_img, *texture);
}

void	preload_textures(t_data *data)
{
	preload_texture(data, data->graphics.wall_sprite.wall_n,
		&data->graphics.wall_sprite.north_texture);
	preload_texture(data, data->graphics.wall_sprite.wall_s,
		&data->graphics.wall_sprite.south_texture);
	preload_texture(data, data->graphics.wall_sprite.wall_e,
		&data->graphics.wall_sprite.east_texture);
	preload_texture(data, data->graphics.wall_sprite.wall_w,
		&data->graphics.wall_sprite.west_texture);
	preload_texture(data, data->graphics.wall_sprite.floor,
		&data->graphics.wall_sprite.floor_texture);
	preload_texture(data, data->graphics.wall_sprite.ceiling,
		&data->graphics.wall_sprite.ceiling_texture);
}
