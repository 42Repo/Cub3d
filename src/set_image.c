/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:24:42 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/10 16:01:32 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"


// void	print_background(t_data *data)
// {
// 	int x, y;
// 	int pitch_shift = (int)(data->player.pitch * WIN_HEIGHT);
// 	int color;

// 	for (x = 0; x < WIN_HEIGHT; x++)
// 	{
// 		color = mlx_get_image_pixel(data->mlx.mlx, data->mlx.img_background, x, 0);
// 		if (y + pitch_shift < WIN_HEIGHT / 2
// 			&& color == 0x0000FF)
// 			continue ;
// 		else
// 			if (color == 0x5B3C11)
// 				continue ;
// 		if (y + pitch_shift < WIN_HEIGHT / 2)
// 			color = 0xFF0000FF; // Sky color
// 		else
// 			color = 0xFF5B3C11; // Ground color
// 		for (y = 0; y < WIN_WIDTH; y++)
// 		{
// 			mlx_pixel_put(data->mlx.mlx, data->mlx.win, x, y, color);
// 		}
// 	}
// }

// void	print_background(t_data *data)
// {
// 	int x, y;
// 	int pitch_shift = (int)(data->player.pitch * WIN_HEIGHT);
// 	int color;

// 	for (y = 0; y < WIN_HEIGHT; y++)
// 	{
// 		color = mlx_get_image_pixel(data->mlx.mlx, data->mlx.img_background, 0, y);
// 		if (y + pitch_shift < WIN_HEIGHT / 2
// 			&& color == 0x0000FF)
// 			continue ;
// 		else
// 			if (color == 0x5B3C11)
// 				continue ;
// 		if (y + pitch_shift < WIN_HEIGHT / 2)
// 			color = 0xFF0000FF; // Sky color
// 		else
// 			color = 0xFF5B3C11; // Ground color
// 		for (x = 0; x < WIN_WIDTH; x++)
// 		{
// 			mlx_pixel_put(data->mlx.mlx, data->mlx.win, x, y, color);
// 		}
// 	}
// }
