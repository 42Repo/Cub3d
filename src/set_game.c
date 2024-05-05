/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:26:40 by bgoron            #+#    #+#             */
/*   Updated: 2024/05/05 23:30:04 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	init_data(char *file, t_data *d)
{
	d->map.map = parse_file(file, &d->map);
	d->map.width = WIN_WIDTH;
	d->map.height = WIN_HEIGHT;
	d->player.pos.x = 100;
	d->player.pos.y = 100;
	d->player.dir.x = 0;
	d->player.dir.y = 0;
	d->player.angle = 0;
	d->mlx.ray_nb = WIN_WIDTH;
	ft_memset(d->mlx.input_map, 0, 65536 * sizeof(char));
	d->mlx.mlx = mlx_init();
	// 3D
	d->mlx.win = mlx_new_window \
	(d->mlx.mlx, d->map.width, d->map.height, "Cub3D");
	d->mlx.img_background = mlx_new_image \
	(d->mlx.mlx, d->map.width, d->map.height);
	d->mlx.img_wall = mlx_new_image \
	(d->mlx.mlx, d->map.width, d->map.height);
	// 2D
	// d->mlx.win = mlx_new_window
	// (d->mlx.mlx, d->map.map_width, d->map.map_height, "Cub3D");
	d->mlx.img_map = mlx_new_image \
	(d->mlx.mlx, d->map.map_width, d->map.map_height);
	d->mlx.img_player = mlx_new_image \
	(d->mlx.mlx, d->map.map_width, d->map.map_height);
}

void	init_mlx(t_data *data)
{
	mlx_on_event(data->mlx.mlx, data->mlx.win, \
	MLX_WINDOW_EVENT, destroy, (void *)data);
	mlx_on_event(data->mlx.mlx, data->mlx.win, \
	MLX_KEYDOWN, key_press, (void *)data);
	mlx_on_event(data->mlx.mlx, data->mlx.win, \
	MLX_KEYUP, key_release, (void *)data);
	mlx_loop_hook(data->mlx.mlx, update, (void *)data);
	mlx_loop(data->mlx.mlx);
}
