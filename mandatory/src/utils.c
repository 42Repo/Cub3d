/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:02:13 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/12 12:40:22 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	fps_counter(void)
{
	static clock_t	last_time = 0;
	static clock_t	last_avg_time = 0;
	static int		frame_count = 0;
	static float	fps_sum = 0.0;
	clock_t			current_time;
	float			fps;
	float			avg_fps;

	current_time = clock();
	fps = CLOCKS_PER_SEC / (float)(current_time - last_time);
	last_time = current_time;
	fps_sum += fps;
	frame_count++;
	if ((current_time - last_avg_time) >= CLOCKS_PER_SEC * 10)
	{
		avg_fps = fps_sum / frame_count;
		printf("\033[1;31mAverage FPS (10s): %.2f\033[0m\n", avg_fps);
		fps_sum = 0.0;
		frame_count = 0;
		last_avg_time = current_time;
	}
	printf("FPS: %.2f\n", fps);
}

int	print_error(char *error)
{
	printf("\033[1;31mError\n%s\033[0m\n", error);
	return (-1);
}

size_t	ft_ctablen(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	print_parsing(t_data *data)
{
	char	**tmp;

	tmp = data->map.map;
	printf("NO: %s\n", data->mlx.wall_sprite.path_n);
	printf("SO: %s\n", data->mlx.wall_sprite.path_s);
	printf("WE: %s\n", data->mlx.wall_sprite.path_w);
	printf("EA: %s\n", data->mlx.wall_sprite.path_e);
	printf("F: %d, %d, %d\n", \
	data->mlx.wall_sprite.floor_color.r, \
	data->mlx.wall_sprite.floor_color.g, \
	data->mlx.wall_sprite.floor_color.b);
	printf("C: %d, %d, %d\n", \
	data->mlx.wall_sprite.ceiling_color.r, \
	data->mlx.wall_sprite.ceiling_color.g, \
	data->mlx.wall_sprite.ceiling_color.b);
	printf("Map:\n");
	while (*tmp)
	{
		printf("%s\n", *tmp);
		tmp++;
	}
}
