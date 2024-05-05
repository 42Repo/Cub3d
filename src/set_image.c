/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:24:42 by bgoron            #+#    #+#             */
/*   Updated: 2024/05/05 19:21:31 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.width > x)
	{
		y = 0;
		while (data->map.height > y)
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
	while (data->map.width > x)
	{
		y = 0;
		while (data->map.height > y)
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
	double		cos_angle;
	double		sin_angle;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
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
		pos.x += cos_angle;
		pos.y += sin_angle;
	}
	return (sqrt(pow(pos.x - tmp.x, 2) + pow(pos.y - tmp.y, 2)));
}

void	add_wall(t_data d, int i, double wall_size)
{
	static int	half_height;
	int			half_wall_size;
	int			wall_width;
	int			wall_x;
	int			wall_y;

	wall_width = d.map.width / d.mlx.ray_nb;
	half_wall_size = (int)wall_size >> 1;
	half_height = d.map.height >> 1;
	wall_y = half_height - ((int)wall_size >> 1);
	while (wall_y <= half_height + half_wall_size && wall_y <= d.map.height)
	{
		wall_x = i * wall_width;
		while (wall_x <= i * wall_width + wall_width && wall_x <= d.map.width)
			mlx_set_image_pixel \
			(d.mlx.mlx, d.mlx.img_wall, wall_x++, wall_y, 0xFF000000);
		wall_y++;
	}
}

void	reset_image(t_data d, void *image)
{
	int	x;
	int	y;

	x = 0;
	while (d.map.width > x)
	{
		y = 0;
		while (d.map.height > y)
			mlx_set_image_pixel(d.mlx.mlx, image, x, y++, 0x00000000);
		x++;
	}
}

void	draw_ray(t_data d, double angle, double disto, int i)
{
	double	dist;
	double	wall_size;

	dist = cast_ray(d.player.pos, angle, d.map, d);
	// wall_size = (TILE_SIZE / (dist * cos(angle - d.player.angle))) * disto;
	wall_size = (TILE_SIZE / (dist * cos(angle - d.player.angle))) * \
	disto * cos(angle - d.player.angle);
	add_wall(d, i, wall_size);
}

void	add_ray(t_data d)
{
	double	angle;
	double	increment;
	double	disto;
	double	angle_end;
	int		i;

	angle = d.player.angle - FOV_RAD / 2;
	increment = FOV_RAD / d.mlx.ray_nb;
	angle_end = d.player.angle + FOV_RAD / 2;
	disto = ((d.map.width / 2) / tan(FOV_RAD / 2));
	i = 1;
	reset_image(d, d.mlx.img_wall);
	while (angle <= angle_end)
	{
		draw_ray(d, angle, disto, i);
		angle += increment;
		i++;
	}
}

void	add_player(t_data d)
{
	int	x;
	int	y;

	x = 0;
	while (d.map.width > x)
	{
		y = 0;
		while (d.map.height > y)
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
