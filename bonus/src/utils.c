/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:02:13 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/18 14:44:20 by bgoron           ###   ########.fr       */
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

int	next_power_of_two(int n)
{
	int	power;

	power = 1;
	while (power < n)
		power *= 2;
	return (power);
}