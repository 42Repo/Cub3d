/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:12:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/28 12:32:35 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	exit_parsingerror(t_data data)
{
	free(data.graphics.wall_sprite.path_n);
	free(data.graphics.wall_sprite.path_s);
	free(data.graphics.wall_sprite.path_e);
	free(data.graphics.wall_sprite.path_w);
	ft_free_tab((void **)data.map.map);
}

void	exit_preloaderror(t_data data)
{
	free(data.graphics.wall_sprite.north_texture);
	free(data.graphics.wall_sprite.south_texture);
	free(data.graphics.wall_sprite.east_texture);
	free(data.graphics.wall_sprite.west_texture);
	free(data.graphics.wall_sprite.ceiling_texture);
	free(data.graphics.wall_sprite.floor_texture);
}

void	exit_exitgame(t_data d)
{
	t_graphics	*g;

	g = &d.graphics;
	mlx_loop_end(g->mlx);
	mlx_destroy_image(g->mlx, g->game.img_background);
	mlx_destroy_image(g->mlx, g->wall_sprite.wall_e.img);
	mlx_destroy_image(g->mlx, g->wall_sprite.wall_w.img);
	mlx_destroy_image(g->mlx, g->wall_sprite.wall_s.img);
	mlx_destroy_image(g->mlx, g->wall_sprite.wall_n.img);
	mlx_destroy_image(g->mlx, g->img_mini_map);
	mlx_destroy_image(g->mlx, g->menu.img_background.img);
	mlx_destroy_image(g->mlx, g->menu.play_button.img.img);
	mlx_destroy_image(g->mlx, g->menu.play_button.img_hovered.img);
	mlx_destroy_image(g->mlx, g->menu.play_button.img_pressed.img);
	mlx_destroy_image(g->mlx, g->menu.exit_button.img.img);
	mlx_destroy_image(g->mlx, g->menu.exit_button.img_hovered.img);
	mlx_destroy_image(g->mlx, g->menu.exit_button.img_pressed.img);
	mlx_destroy_image(g->mlx, g->menu.settings_button.img.img);
	mlx_destroy_image(g->mlx, g->menu.settings_button.img_hovered.img);
	mlx_destroy_image(g->mlx, g->menu.settings_button.img_pressed.img);
	mlx_destroy_image(g->mlx, g->menu.img_background_button.img);
	mlx_destroy_image(g->mlx, g->wall_sprite.floor.img);
	mlx_destroy_image(g->mlx, g->wall_sprite.ceiling.img);
	mlx_destroy_image(g->mlx, g->menu.img_darken.img);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
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
