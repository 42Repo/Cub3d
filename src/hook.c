/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/05/04 21:51:40 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	render(t_data *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	add_player(*data);
	for (int i = 0; i < data->map.width; i++)
	{
		for (int j = 0; j < data->map.height; j++)
		{
			mlx_set_image_pixel(data->mlx.mlx, data->mlx.img_wall, i, j, 0x00000000);	
		}
	}
	add_ray(*data);
	mlx_put_image_to_window
	(data->mlx.mlx, data->mlx.win, data->mlx.img_background, 0, 0);
	mlx_put_image_to_window
	(data->mlx.mlx, data->mlx.win, data->mlx.img_wall, 0, 0);
	// mlx_put_image_to_window
	// (data->mlx.mlx, data->mlx.win, data->mlx.img_map, 0, 0);
	// mlx_put_image_to_window
	// (data->mlx.mlx, data->mlx.win, data->mlx.img_player, 0, 0);
}

void	move(t_data *d)
{
	t_vector	trig;

	trig = (t_vector){cos(d->player.angle), sin(d->player.angle)};
	d->player.speed = 5;
	if (d->mlx.input_map[SDL_SCANCODE_LSHIFT])
		d->player.speed += 5;
	if (d->mlx.input_map[SDL_SCANCODE_W])
	{
		d->player.pos.x += d->player.speed * (trig.x);
		d->player.pos.y += d->player.speed * (trig.y);
	}
	if (d->mlx.input_map[SDL_SCANCODE_S])
	{
		d->player.pos.x -= d->player.speed * (trig.x);
		d->player.pos.y -= d->player.speed * (trig.y);
	}
	if (d->mlx.input_map[SDL_SCANCODE_A])
		d->player.angle -= (CUB_PI / 60);
	if (d->mlx.input_map[SDL_SCANCODE_D])
		d->player.angle += (CUB_PI / 60);
	d->player.angle = fmod(d->player.angle, CUB_2_PI);
	d->player.pos.x = fmod(d->map.width + d->player.pos.x, d->map.width);
	d->player.pos.y = fmod(d->map.height + d->player.pos.y, d->map.height);
	d->player.dir.x = (trig.x * 10) + d->player.pos.x;
	d->player.dir.x = (trig.y * 10) + d->player.pos.y;
}

int	update(void *param)
{
	t_data		*d;

	d = (t_data *)param;
	move(d);
	render(d);
	return (0);
}

int	key_press(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(data->mlx.mlx);
	if (key == SDL_SCANCODE_MINUS)
		data->mlx.ray_nb /= 1 + (data->mlx.ray_nb > 1);
	if (key == SDL_SCANCODE_EQUALS)
		data->mlx.ray_nb *= 1 + ((int)data->mlx.ray_nb < data->map.width);
	data->mlx.input_map[key] = 1;
	return (0);
}

int	key_release(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->mlx.input_map[key] = 0;
	return (0);
}
