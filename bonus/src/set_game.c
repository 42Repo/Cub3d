/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:26:40 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/10 14:52:23 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	init_player(t_data *data)
{
	data->player.pos.x = 10.5;
	data->player.pos.y = 12.5;
	data->player.dir.x = -1.0;
	data->player.dir.y = 0.0;
	data->player.plane.x = 0.0;
	data->player.plane.y = 0.66;
	data->player.move_speed = 0.05;
	data->player.rot_speed = 0.04;
}

void	init_data(t_data *d)
{
	d->map.width = WIN_WIDTH;
	d->map.height = WIN_HEIGHT;
	init_player(d);
	d->mlx.mlx = mlx_init();
	// mlx_set_fps_goal(d- >mlx.mlx, 60);
	mlx_mouse_hide();
	ft_bzero(d->mlx.key_states, 256);
	d->mlx.wall_sprite.wall_e.img = mlx_png_file_to_image(d->mlx.mlx,
			d->mlx.wall_sprite.path_e, &d->mlx.wall_sprite.wall_e.width,
			&d->mlx.wall_sprite.wall_e.height);
	d->mlx.wall_sprite.wall_w.img = mlx_png_file_to_image(d->mlx.mlx,
			d->mlx.wall_sprite.path_w, &d->mlx.wall_sprite.wall_w.width,
			&d->mlx.wall_sprite.wall_w.height);
	d->mlx.wall_sprite.wall_s.img = mlx_png_file_to_image(d->mlx.mlx,
			d->mlx.wall_sprite.path_s, &d->mlx.wall_sprite.wall_s.width,
			&d->mlx.wall_sprite.wall_s.height);
	d->mlx.wall_sprite.wall_n.img = mlx_png_file_to_image(d->mlx.mlx,
			d->mlx.wall_sprite.path_n, &d->mlx.wall_sprite.wall_n.width,
			&d->mlx.wall_sprite.wall_n.height);
	d->mlx.win = mlx_new_window(d->mlx.mlx, d->map.width, d->map.height,
			"Cub3D");
	d->mlx.img_background = mlx_new_image(d->mlx.mlx, d->map.width,
			d->map.height);
}

void	init_mlx(t_data *data)
{
	mlx_on_event(data->mlx.mlx, data->mlx.win, MLX_WINDOW_EVENT, destroy,
		(void *)data);
	mlx_on_event(data->mlx.mlx, data->mlx.win, MLX_KEYDOWN, key_press,
		(void *)data);
	mlx_on_event(data->mlx.mlx, data->mlx.win, MLX_KEYUP, key_release,
		(void *)data);
	mlx_loop_hook(data->mlx.mlx, update, (void *)data);
	mlx_loop(data->mlx.mlx);
}
