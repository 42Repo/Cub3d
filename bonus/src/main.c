/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:35:28 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/19 11:28:34 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (parsing(ac, av, &data) == -1)
		exit_game(data, PARSING_ERROR);
	init_data(&data);
	resize_images(&data);
	preload_textures(&data);
	data.mlx.win = mlx_new_window(data.mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	print_first_background(&data);
	init_mlx(&data);
	return (EXIT_SUCCESS);
}
