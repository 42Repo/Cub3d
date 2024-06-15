/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:35:28 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/15 15:55:04 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

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
