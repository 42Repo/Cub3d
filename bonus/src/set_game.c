/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:26:40 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/27 17:04:23 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	init_image(t_data *data)
{
	t_graphics	*g;
	t_sprite	*s;

	g = &data->graphics;
	s = &g->wall_sprite;
	g->wall_sprite.wall_e.img = mlx_png_file_to_image(g->mlx, s->path_e, \
	&s->wall_e.width, &s->wall_e.height);
	s->wall_w.img = mlx_png_file_to_image(g->mlx, s->path_w, \
	&s->wall_w.width, &s->wall_w.height);
	s->wall_s.img = mlx_png_file_to_image(g->mlx, s->path_s, \
	&s->wall_s.width, &s->wall_s.height);
	s->wall_n.img = mlx_png_file_to_image(g->mlx, s->path_n, \
	&s->wall_n.width, &s->wall_n.height);
	s->floor.img = mlx_png_file_to_image(g->mlx, s->path_floor, \
	&s->floor.width, &s->floor.height);
	s->ceiling.img = mlx_png_file_to_image(g->mlx, s->path_ceiling, \
	&s->ceiling.width, &s->ceiling.height);
}

void	init_data(t_data *d)
{
	t_graphics	*g;
	t_sprite	*s;
	t_vec2i		map_size;

	g = &d->graphics;
	s = &g->wall_sprite;
	d->settings.fov = 90;
	map_size = (t_vec2i){WIN_WIDTH * 0.17, WIN_HEIGHT * 0.28};
	d->settings.minimap_scale = 1.5;
	g->mlx = mlx_init();
	d->settings.screen_state = MAIN_MENU;
	d->graphics.is_first_frame = true;
	g->game.floor_and_ceiling = false;
	init_menu(d);
	init_settings_menu(d);
	s->path_ceiling = "textures/wall/x.png";
	s->path_floor = "textures/wall/x.png";
	ft_bzero(g->key_states, 256);
	init_image(d);
	g->game.img_background = mlx_new_image(g->mlx, WIN_WIDTH, WIN_HEIGHT);
	g->img_mini_map = mlx_new_image(g->mlx, map_size.x, map_size.y);
}

void	init_mlx(t_data *data)
{
	mlx_on_event(data->graphics.mlx, data->graphics.win, \
	MLX_WINDOW_EVENT, destroy, (void *)data);
	mlx_on_event(data->graphics.mlx, data->graphics.win, \
	MLX_KEYDOWN, key_press, (void *)data);
	mlx_on_event(data->graphics.mlx, data->graphics.win, \
	MLX_KEYUP, key_release, (void *)data);
	mlx_on_event(data->graphics.mlx, data->graphics.win, \
	MLX_MOUSEDOWN, mouse_press, (void *)data);
	mlx_on_event(data->graphics.mlx, data->graphics.win, \
	MLX_MOUSEUP, mouse_release, (void *)data);
	mlx_loop_hook(data->graphics.mlx, update, (void *)data);
	mlx_loop(data->graphics.mlx);
}
