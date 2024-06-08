/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:24:42 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/08 18:53:51 by asuc             ###   ########.fr       */
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
