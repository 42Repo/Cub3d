/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:35:28 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/10 16:01:52 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	preload_textures(t_data *data)
{
	int	x;
	int	y;

	data->mlx.wall_sprite.north_texture = malloc(data->mlx.wall_sprite.wall_n.width
			* data->mlx.wall_sprite.wall_n.height * sizeof(int));
	data->mlx.wall_sprite.south_texture = malloc(data->mlx.wall_sprite.wall_s.width
			* data->mlx.wall_sprite.wall_s.height * sizeof(int));
	data->mlx.wall_sprite.east_texture = malloc(data->mlx.wall_sprite.wall_e.width
			* data->mlx.wall_sprite.wall_e.height * sizeof(int));
	data->mlx.wall_sprite.west_texture = malloc(data->mlx.wall_sprite.wall_w.width
			* data->mlx.wall_sprite.wall_w.height * sizeof(int));
	for (y = 0; y < data->mlx.wall_sprite.wall_n.height; y++)
	{
		for (x = 0; x < data->mlx.wall_sprite.wall_n.width; x++)
		{
			data->mlx.wall_sprite.north_texture[y
				* data->mlx.wall_sprite.wall_n.width
				+ x] = mlx_get_image_pixel(data->mlx.mlx,
					data->mlx.wall_sprite.wall_n.img, x, y);
			data->mlx.wall_sprite.south_texture[y
				* data->mlx.wall_sprite.wall_s.width
				+ x] = mlx_get_image_pixel(data->mlx.mlx,
					data->mlx.wall_sprite.wall_s.img, x, y);
			data->mlx.wall_sprite.east_texture[y
				* data->mlx.wall_sprite.wall_e.width
				+ x] = mlx_get_image_pixel(data->mlx.mlx,
					data->mlx.wall_sprite.wall_e.img, x, y);
			data->mlx.wall_sprite.west_texture[y
				* data->mlx.wall_sprite.wall_w.width
				+ x] = mlx_get_image_pixel(data->mlx.mlx,
					data->mlx.wall_sprite.wall_w.img, x, y);
		}
	}
}

static void	print_background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.width > x)
	{
		y = 0;
		while (data->map.height > y)
		{
			if (y < data->map.height / 2)
				mlx_set_image_pixel \
				(data->mlx.mlx, data->mlx.img_background, x, y, 0xFF0000FF);
			else
				mlx_set_image_pixel \
				(data->mlx.mlx, data->mlx.img_background, x, y, 0xFF5B3C11);
			y++;
		}
		x++;
	}
}


int	main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (parsing(ac, av, &data) == -1)
		return (EXIT_FAILURE);
	init_data(&data);
	preload_textures(&data);
	print_background(&data);
	init_mlx(&data);
	return (EXIT_SUCCESS);
}
