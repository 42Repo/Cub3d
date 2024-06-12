/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:35:28 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/12 17:00:49 by bgoron           ###   ########.fr       */
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
int	main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (parsing(ac, av, &data) == -1)
	{
		free(data.mlx.wall_sprite.path_n);
		free(data.mlx.wall_sprite.path_s);
		free(data.mlx.wall_sprite.path_e);
		free(data.mlx.wall_sprite.path_w);
		ft_free_tab((void **)data.map.map);
		return (EXIT_FAILURE);
	}
	init_data(&data);
	preload_textures(&data);
	print_first_background(&data);
	init_mlx(&data);
	return (EXIT_SUCCESS);
}
