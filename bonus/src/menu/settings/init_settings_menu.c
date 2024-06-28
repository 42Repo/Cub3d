/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_settings_menu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:26:54 by asuc              #+#    #+#             */
/*   Updated: 2024/06/28 12:30:35 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_settings_menu.h"

void	init_settings_menu(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->graphics.menu.img_darken.img = mlx_new_image(data->graphics.mlx, \
	WIN_WIDTH, WIN_HEIGHT);
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			mlx_set_image_pixel(data->graphics.mlx, data->graphics.menu.img_darken.img, j, i, 0xBF000000);
			j++;
		}
		i++;
	}
}
