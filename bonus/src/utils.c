/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:02:13 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/02 11:37:01 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	fps_counter(void)
{
	static clock_t	last_time = 0;
	static clock_t	last_avg_time = 0;
	static int		frame_count = 0;
	static float	fps_sum = 0.0;
	float			fps;

	fps = CLOCKS_PER_SEC / (float)(clock() - last_time);
	last_time = clock();
	fps_sum += fps;
	frame_count++;
	if ((clock() - last_avg_time) >= CLOCKS_PER_SEC * 10)
	{
		printf("\033[1;31mAverage FPS (10s): %.2f\033[0m\n", \
		(double)(fps_sum / (float)frame_count));
		fps_sum = 0.0;
		frame_count = 0;
		last_avg_time = clock();
	}
	printf("FPS: %.2f\n", (double)fps);
}
