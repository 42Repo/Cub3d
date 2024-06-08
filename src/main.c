/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:35:28 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/08 21:03:27 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (parsing(ac, av, &data) == -1)
		return (EXIT_FAILURE);
	init_data(&data);
	print_background(&data);
	printf("data.mlx.wall_sprite.wall_e.img = %p\n", data.mlx.wall_sprite.wall_e.img);
	printf("data.mlx.wall_sprite.wall_e.width = %d\n", data.mlx.wall_sprite.wall_e.width);
	printf("data.mlx.wall_sprite.wall_e.height = %d\n", data.mlx.wall_sprite.wall_e.height);
	printf("data.mlx.wall_sprite.wall_w.img = %p\n", data.mlx.wall_sprite.wall_w.img);
	printf("data.mlx.wall_sprite.wall_w.width = %d\n", data.mlx.wall_sprite.wall_w.width);
	printf("data.mlx.wall_sprite.wall_w.height = %d\n", data.mlx.wall_sprite.wall_w.height);
	printf("data.mlx.wall_sprite.wall_n.img = %p\n", data.mlx.wall_sprite.wall_n.img);
	printf("data.mlx.wall_sprite.wall_n.width = %d\n", data.mlx.wall_sprite.wall_n.width);
	printf("data.mlx.wall_sprite.wall_n.height = %d\n", data.mlx.wall_sprite.wall_n.height);
	printf("data.mlx.wall_sprite.wall_s.img = %p\n", data.mlx.wall_sprite.wall_s.img);
	printf("data.mlx.wall_sprite.wall_s.width = %d\n", data.mlx.wall_sprite.wall_s.width);
	printf("data.mlx.wall_sprite.wall_s.height = %d\n", data.mlx.wall_sprite.wall_s.height);
	init_mlx(&data);
	return (EXIT_SUCCESS);
}
