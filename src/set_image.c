/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:24:42 by bgoron            #+#    #+#             */
/*   Updated: 2024/05/04 23:24:58 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.width - 1 > x)
	{
		y = 0;
		while (data->map.height - 1 > y)
		{
			if (y < data->map.height / 2)
				mlx_set_image_pixel \
				(data->mlx.mlx, data->mlx.img_background, x, y, 0xFF0000FF);
			else
				mlx_set_image_pixel \
				(data->mlx.mlx, data->mlx.img_background, x, y, 0xFF5B3C11);
			y++;
		}
		x++;
	}
}

void	print_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.width - 1 > x)
	{
		y = 0;
		while (data->map.height - 1 > y)
		{
			if (data->map.map[y / TILE_SIZE][x / TILE_SIZE] == '1')
				mlx_set_image_pixel \
				(data->mlx.mlx, data->mlx.img_map, x, y, 0xFF202020);
			else
				mlx_set_image_pixel \
				(data->mlx.mlx, data->mlx.img_map, x, y, 0xFF5B3C11);
			y++;
		}
		x++;
	}
}

double	cast_ray(t_vector pos, double angle, t_map map, t_data d)
{
	t_vector	tmp;
	int			map_x;
	int			map_y;

	tmp = pos;
	while (42)
	{
		map_x = (int)pos.x / TILE_SIZE;
		map_y = (int)pos.y / TILE_SIZE;
		if (pos.x < 0 || pos.y < 0 || map_x >= map.width || map_y >= map.height
			|| map.map[map_y][map_x] == '1')
			break ;
		mlx_set_image_pixel(d.mlx.mlx, d.mlx.img_player,
			pos.x, pos.y, 0xFF303030);
		pos.x += cos(angle);
		pos.y += sin(angle);
	}

	return (sqrt(pow(pos.x - tmp.x, 2) + pow(pos.y - tmp.y, 2)));
}

void	add_wall(t_data d, int i, double wall_size)
{
	static int	half_height;
	int			half_wall_size;
	int			wall_width;
	int			x;
	int			y;

	wall_width = d.map.width / d.mlx.ray_nb;
	half_wall_size = wall_size / 2;
	half_height = d.map.height / 2;
	y = half_height - wall_size / 2;
	while (y < half_height + half_wall_size && y < d.map.height - 1)
	{
		x = i * wall_width;
		while (x < i * wall_width * 2 && x < d.map.width - 1)
			mlx_set_image_pixel \
			(d.mlx.mlx, d.mlx.img_wall, x++, y, 0xFF000000);
		y++;
	}
}

void	add_ray(t_data d)
{
	double			dist;
	double			angle;
	double			wall_size;
	double			increment;
	static double	disto = 0;
	int				i;

	if (!disto)
		disto = ((d.map.width / 2) / tan(CUB_PI_8));
	i = 1;
	angle = d.player.angle - CUB_PI_4;
	increment = CUB_PI_2 / d.mlx.ray_nb;
	if (d.mlx.ray_nb == 1)
	{
		dist = cast_ray(d.player.pos, d.player.angle, d.map, d);
		wall_size = (TILE_SIZE / dist) * disto;
		add_wall(d, i, wall_size);
		return ;
	}
	while (angle <= d.player.angle + CUB_PI_4)
	{
		dist = cast_ray(d.player.pos, angle, d.map, d);
		wall_size = (TILE_SIZE / dist) * disto;
		add_wall(d, i, wall_size);
		angle += increment;
		i++;
	}
}

void	add_player(t_data d)
{
	int	x;
	int	y;

	x = 0;
	while (d.map.width - 1 > x)
	{
		y = 0;
		while (d.map.height - 1 > y)
		{
			if ((x > d.player.pos.x - 5 && x < d.player.pos.x + 5) \
				&& (y > d.player.pos.y - 5 && y < d.player.pos.y + 5))
				mlx_set_image_pixel \
				(d.mlx.mlx, d.mlx.img_player, x, y, 0xFF000000);
			else
				mlx_set_image_pixel \
				(d.mlx.mlx, d.mlx.img_player, x, y, 0x00000000);
			y++;
		}
		x++;
	}
}
