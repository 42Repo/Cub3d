/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_settings_menu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:26:54 by asuc              #+#    #+#             */
/*   Updated: 2024/06/28 17:02:25 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_settings_menu.h"

void	init_settings_menu(t_data *data)
{
	t_graphics	*g;
	t_menu		*m;
	int			i;
	int			j;

	g = &data->graphics;
	m = &g->menu;
	g->menu.img_darken.img = mlx_new_image(g->mlx, WIN_WIDTH, WIN_HEIGHT);
	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			mlx_set_image_pixel(g->mlx, m->img_darken.img, j, i, 0xBF000000);
			j++;
		}
		i++;
	}
}
