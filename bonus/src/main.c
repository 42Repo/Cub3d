/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:35:28 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/02 19:22:23 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	main(int ac, char **av)
{
	t_data		data;
	t_graphics	g;

	ft_bzero(&data, sizeof(t_data));
	if (parsing(ac, av, &data) == -1)
		exit_game(data, PARSING_ERROR);
	init_data(&data);
	resize_images(&data);
	if (preload_textures(&data) == -1)
		exit_game(data, PRELOAD_ERROR);
	g = data.graphics;
	data.graphics.win = mlx_new_window(g.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	print_first_background(&data);
	init_mlx(&data);
	return (EXIT_SUCCESS);
}
