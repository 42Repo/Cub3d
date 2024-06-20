/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:26:40 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/21 01:21:24 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include "struct.h"

void	init_data(t_data *d)
{
	d->settings.minimap_scale = 1.5;
	d->graphics.mlx = mlx_init();
	d->settings.screen_state = MAIN_MENU;
	mlx_mouse_hide();
	init_menu(d);
	ft_bzero(d->graphics.key_states, 256);
	d->graphics.wall_sprite.wall_e.img = mlx_png_file_to_image(d->graphics.mlx,
			d->graphics.wall_sprite.path_e, &d->graphics.wall_sprite.wall_e.width,
			&d->graphics.wall_sprite.wall_e.height);
	d->graphics.wall_sprite.wall_w.img = mlx_png_file_to_image(d->graphics.mlx,
			d->graphics.wall_sprite.path_w, &d->graphics.wall_sprite.wall_w.width,
			&d->graphics.wall_sprite.wall_w.height);
	d->graphics.wall_sprite.wall_s.img = mlx_png_file_to_image(d->graphics.mlx,
			d->graphics.wall_sprite.path_s, &d->graphics.wall_sprite.wall_s.width,
			&d->graphics.wall_sprite.wall_s.height);
	d->graphics.wall_sprite.wall_n.img = mlx_png_file_to_image(d->graphics.mlx,
			d->graphics.wall_sprite.path_n, &d->graphics.wall_sprite.wall_n.width,
			&d->graphics.wall_sprite.wall_n.height);
	d->graphics.game.img_background = mlx_new_image(d->graphics.mlx, WIN_WIDTH, WIN_HEIGHT);
	d->graphics.img_mini_map = mlx_new_image(d->graphics.mlx, WIN_WIDTH * 0.17, WIN_HEIGHT * 0.28);
}

void	init_mlx(t_data *data)
{
	mlx_on_event(data->graphics.mlx, data->graphics.win, MLX_WINDOW_EVENT, destroy,
		(void *)data);
	mlx_on_event(data->graphics.mlx, data->graphics.win, MLX_KEYDOWN, key_press,
		(void *)data);
	mlx_on_event(data->graphics.mlx, data->graphics.win, MLX_KEYUP, key_release,
		(void *)data);
	mlx_loop_hook(data->graphics.mlx, update, (void *)data);
	mlx_loop(data->graphics.mlx);
}
