/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:12:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/11 16:22:33 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	exit_game(t_data data)
{
	mlx_loop_end(data.mlx.mlx);
	mlx_destroy_image(data.mlx.mlx, data.mlx.img_background);
	mlx_destroy_image(data.mlx.mlx, data.mlx.wall_sprite.wall_e.img);
	mlx_destroy_image(data.mlx.mlx, data.mlx.wall_sprite.wall_w.img);
	mlx_destroy_image(data.mlx.mlx, data.mlx.wall_sprite.wall_s.img);
	mlx_destroy_image(data.mlx.mlx, data.mlx.wall_sprite.wall_n.img);
	mlx_destroy_window(data.mlx.mlx, data.mlx.win);
	mlx_destroy_display(data.mlx.mlx);
	ft_free_tab((void **) data.map.map);
	free(data.mlx.wall_sprite.path_n);
	free(data.mlx.wall_sprite.path_s);
	free(data.mlx.wall_sprite.path_e);
	free(data.mlx.wall_sprite.path_w);
	exit(0);
}

int	destroy(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (!key)
		exit_game(*data);
	return (0);
}
