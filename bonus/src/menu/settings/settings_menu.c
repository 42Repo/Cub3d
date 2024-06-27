/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:31:58 by asuc              #+#    #+#             */
/*   Updated: 2024/06/27 16:39:16 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_settings_menu.h"

void	render_settings(t_data *data)
{
	mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
		data->graphics.menu.img_background.img, 0, 0);
	mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
		data->graphics.menu.img_darken.img, 0, 0);
	mlx_set_font_scale(data->graphics.mlx, data->graphics.win,
		"textures/menu/MinimalPixel_v2.ttf", 50);
	mlx_string_put(data->graphics.mlx, data->graphics.win, 100, 100, 0xFFFFFFFF,
		"Settings");
	mlx_string_put(data->graphics.mlx, data->graphics.win, 100, 200, 0xFFFFFFFF,
		"Press 'ESC' to go back to the main menu");
}
