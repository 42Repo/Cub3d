/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preload_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:42:33 by asuc              #+#    #+#             */
/*   Updated: 2024/07/02 19:25:59 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	load_texture_data(void *mlx, t_image wall_img, int *texture)
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

static int	preload_texture(t_data *data, t_image wall_img, int **texture)
{
	*texture = malloc((unsigned int)wall_img.width
			* (unsigned int)wall_img.height * sizeof(int));
	if (!(*texture))
		return (-1);
	load_texture_data(data->graphics.mlx, wall_img, *texture);
	return (0);
}

int	preload_textures(t_data *data)
{
	int	alloc_error;

	alloc_error = 0;
	alloc_error += preload_texture(data, data->graphics.wall_sprite.wall_n, \
	&data->graphics.wall_sprite.north_texture);
	alloc_error += preload_texture(data, data->graphics.wall_sprite.wall_s, \
	&data->graphics.wall_sprite.south_texture);
	alloc_error += preload_texture(data, data->graphics.wall_sprite.wall_e, \
	&data->graphics.wall_sprite.east_texture);
	alloc_error += preload_texture(data, data->graphics.wall_sprite.wall_w, \
	&data->graphics.wall_sprite.west_texture);
	alloc_error += preload_texture(data, data->graphics.wall_sprite.floor, \
	&data->graphics.wall_sprite.floor_texture);
	alloc_error += preload_texture(data, data->graphics.wall_sprite.ceiling, \
	&data->graphics.wall_sprite.ceiling_texture);
	if (alloc_error < 0)
		return (-1);
	return (0);
}
