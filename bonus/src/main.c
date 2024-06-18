/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:35:28 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/18 18:08:18 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

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
