/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:35:28 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/18 14:44:13 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"


void	resize_image(t_data *data, t_image *src)
{
	t_image	dst;
	dst.width = next_power_of_two(src->width);
	dst.height = dst.width;
	int x_ratio = (src->width << 16) / dst.width + 1;
	int y_ratio = (src->height << 16) / dst.height + 1;
	int x, y;

	dst.img = mlx_new_image(data->mlx.mlx, dst.width, dst.height);

	for (int i = 0; i < dst.height; i++) {
		for (int j = 0; j < dst.width; j++) {
			x = ((j * x_ratio) >> 16);
			y = ((i * y_ratio) >> 16);
			int color = mlx_get_image_pixel(data->mlx.mlx, src->img, x, y);
			mlx_set_image_pixel(data->mlx.mlx, dst.img, j, i, color);
		}
	}
	mlx_destroy_image(data->mlx.mlx, src->img);
	*src = dst;
}

void	resize_images(t_data *data)
{
	resize_image(data, &data->mlx.wall_sprite.wall_n);
	resize_image(data, &data->mlx.wall_sprite.wall_s);
	resize_image(data, &data->mlx.wall_sprite.wall_e);
	resize_image(data, &data->mlx.wall_sprite.wall_w);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (parsing(ac, av, &data) == -1)
		exit_game(data, PARSING_ERROR);
	init_data(&data);
	resize_images(&data);
	if (preload_textures(&data) == -1)
		exit_game(data, PRELOAD_ERROR);
	data.mlx.win = mlx_new_window(data.mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	print_first_background(&data);
	init_mlx(&data);
	return (EXIT_SUCCESS);
}
