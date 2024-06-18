/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:12:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/18 15:37:46 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	exit_parsingerror(t_data data)
{
	free(data.mlx.wall_sprite.path_n);
	free(data.mlx.wall_sprite.path_s);
	free(data.mlx.wall_sprite.path_e);
	free(data.mlx.wall_sprite.path_w);
	ft_free_tab((void **)data.map.map);
}

void	exit_preloaderror(t_data data)
{
	free(data.mlx.wall_sprite.north_texture);
	free(data.mlx.wall_sprite.south_texture);
	free(data.mlx.wall_sprite.east_texture);
	free(data.mlx.wall_sprite.west_texture);
}

void	exit_exitgame(t_data data)
{
	mlx_loop_end(data.mlx.mlx);
	mlx_destroy_image(data.mlx.mlx, data.mlx.img_background);
	mlx_destroy_image(data.mlx.mlx, data.mlx.wall_sprite.wall_e.img);
	mlx_destroy_image(data.mlx.mlx, data.mlx.wall_sprite.wall_w.img);
	mlx_destroy_image(data.mlx.mlx, data.mlx.wall_sprite.wall_s.img);
	mlx_destroy_image(data.mlx.mlx, data.mlx.wall_sprite.wall_n.img);
	mlx_destroy_window(data.mlx.mlx, data.mlx.win);
	mlx_destroy_display(data.mlx.mlx);
}

void	exit_game(t_data data, int status)
{
	if (status >= PARSING_ERROR)
		exit_parsingerror(data);
	if (status >= PRELOAD_ERROR)
		exit_preloaderror(data);
	if (status == EXIT_GAME)
		exit_exitgame(data);
	exit(EXIT_SUCCESS);
}

int	destroy(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (!key)
		exit_game(*data, EXIT_GAME);
	return (0);
}
