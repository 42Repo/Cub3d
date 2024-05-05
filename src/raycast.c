/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:01:19 by bgoron            #+#    #+#             */
/*   Updated: 2024/05/05 21:30:07 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

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
		if (pos.x < 0 || pos.y < 0 || map_x >= map.cols || map_y >= map.rows)
			break ;
		if (map.map[map_y][map_x] == '1')
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

void	draw_ray(t_data d, double angle, double disto, int i)
{
	double	dist;
	double	wall_size;

	dist = cast_ray(d.player.pos, angle, d.map, d);
	if (!dist)
		wall_size = 5000;
	else
		wall_size = (TILE_SIZE / (dist * cos(angle - d.player.angle))) \
		* disto * cos(angle - d.player.angle);
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
