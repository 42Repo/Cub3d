/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:12:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/05/07 14:06:31 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	exit_game(t_data data)
{
	mlx_loop_end(data.mlx.mlx);
	mlx_destroy_image(data.mlx.mlx, data.mlx.img_map);
	mlx_destroy_image(data.mlx.mlx, data.mlx.img_player);
	mlx_destroy_image(data.mlx.mlx, data.mlx.img_background);
	mlx_destroy_image(data.mlx.mlx, data.mlx.img_wall);
	mlx_destroy_window(data.mlx.mlx, data.mlx.win);
	mlx_destroy_display(data.mlx.mlx);
	ft_free_tab((void **) data.map.map);
	exit(EXIT_SUCCESS);
}

int	destroy(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (!key)
		exit_game(*data);
	return (0);
}
