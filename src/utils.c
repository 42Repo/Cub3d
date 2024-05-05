/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:02:13 by bgoron            #+#    #+#             */
/*   Updated: 2024/05/05 21:50:34 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	reset_image(t_data d, void *image)
{
	int	x;
	int	y;

	x = 0;
	while (d.map.map_width > x)
	{
		y = 0;
		while (d.map.map_height > y)
			mlx_set_image_pixel(d.mlx.mlx, image, x, y++, 0x00000000);
		x++;
	}
}

void	fps_counter(void)
{
	static clock_t	last_time = 0;
	static clock_t	last_avg_time = 0;
	static int		frame_count = 0;
	static double	fps_sum = 0.0;
	clock_t			current_time;
	double			fps;
	double			avg_fps;

	current_time = clock();
	fps = CLOCKS_PER_SEC / (double)(current_time - last_time);
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
