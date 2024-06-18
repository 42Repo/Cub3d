/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:35:28 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/18 18:06:08 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	init_image(t_data *data, t_image *src, t_image *dst, t_vec2_int *ratio)
{
	dst->width = next_power_of_two(src->width);
	dst->height = dst->width;
	ratio->x = (src->width << 16) / dst->width + 1;
	ratio->y = (src->height << 16) / dst->height + 1;
	dst->img = mlx_new_image(data->mlx.mlx, dst->width, dst->height);
}

void	resize_image(t_data *data, t_image *src)
{
	t_image		dst;
	t_vec2_int	ratio;
	t_vec2_int	pos_src;
	t_vec2_int	pos_dst;
	int			color;

	init_image(data, src, &dst, &ratio);
	pos_dst.y = 0;
	while (pos_dst.y < dst.height)
	{
		pos_dst.x = 0;
		while (pos_dst.x < dst.width)
		{
			pos_src.x = (pos_dst.x * ratio.x) >> 16;
			pos_src.y = (pos_dst.y * ratio.y) >> 16;
			color = mlx_get_image_pixel
				(data->mlx.mlx, src->img, pos_src.x, pos_src.y);
			mlx_set_image_pixel
				(data->mlx.mlx, dst.img, pos_dst.x, pos_dst.y, color);
			pos_dst.x++;
		}
		pos_dst.y++;
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

void	invert_map(t_map *map)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = map->rows - 1;
	while (i < j)
	{
		tmp = map->map[i];
		map->map[i] = map->map[j];
		map->map[j] = tmp;
		i++;
		j--;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (parsing(ac, av, &data) == -1)
		exit_game(data, PARSING_ERROR);
	invert_map(&data.map);
	init_data(&data);
	resize_images(&data);
	preload_textures(&data);
	data.mlx.win = mlx_new_window(data.mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	print_first_background(&data);
	init_mlx(&data);
	return (EXIT_SUCCESS);
}
