/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preload_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:42:33 by asuc              #+#    #+#             */
/*   Updated: 2024/06/16 17:54:06 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	check_size(t_sprite *sprite)
{
	if (sprite->wall_n.width != sprite->wall_n.height
		|| sprite->wall_s.width != sprite->wall_s.height
		|| sprite->wall_e.width != sprite->wall_e.height
		|| sprite->wall_w.width != sprite->wall_w.height)
		return (print_error("Textures must be square\n"));
	return (0);
}

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
	load_texture_data(data->mlx.mlx, wall_img, *texture);
}

int	preload_textures(t_data *data)
{
	preload_texture(data, data->mlx.wall_sprite.wall_n,
		&data->mlx.wall_sprite.north_texture);
	preload_texture(data, data->mlx.wall_sprite.wall_s,
		&data->mlx.wall_sprite.south_texture);
	preload_texture(data, data->mlx.wall_sprite.wall_e,
		&data->mlx.wall_sprite.east_texture);
	preload_texture(data, data->mlx.wall_sprite.wall_w,
		&data->mlx.wall_sprite.west_texture);
	if (check_size(&data->mlx.wall_sprite) == -1)
		return (-1);
	return (0);
}
