/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:27:03 by asuc              #+#    #+#             */
/*   Updated: 2024/06/14 18:30:13 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_background(t_data *data)
{
	int			pitch_shift;
	int			color;
	int			x;
	int			y;
	int			start_y;
	int			end_y;
	static int	prev_pitch_shift = 0;

	pitch_shift = (int)(data->player.pitch * WIN_HEIGHT);
	if (pitch_shift > prev_pitch_shift)
	{
		start_y = WIN_HEIGHT / 2 - prev_pitch_shift;
		end_y = WIN_HEIGHT / 2 - pitch_shift;
		color = 0xFF5B3C11;
	}
	else
	{
		start_y = WIN_HEIGHT / 2 - pitch_shift;
		end_y = WIN_HEIGHT / 2 - prev_pitch_shift;
		color = 0xFF0000FF;
	}
	for (y = end_y; y <= start_y; y++)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT && y >= 0 && x < WIN_WIDTH && x >= 0)
				mlx_set_image_pixel(data->mlx.mlx, data->mlx.img_background, x, y,
					color);
			x++;
		}
	}
	prev_pitch_shift = pitch_shift;
}

void	print_first_background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (WIN_WIDTH > x)
	{
		y = 0;
		while (WIN_HEIGHT > y)
		{
			if (y < WIN_HEIGHT / 2)
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
