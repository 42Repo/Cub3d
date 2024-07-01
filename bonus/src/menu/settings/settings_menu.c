/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:31:58 by asuc              #+#    #+#             */
/*   Updated: 2024/07/01 21:51:15 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_settings_menu.h"

void	render_settings_background(t_data *data)
{
	mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
		data->graphics.menu.img_background.img, 0, 0);
	mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
		data->graphics.settings.img_darken.img, 0, 0);
	mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
		data->graphics.settings.img_background.img,
		data->graphics.settings.pos_img_background.x,
		data->graphics.settings.pos_img_background.y);
}

void	render_settings_title(t_data *data)
{
	mlx_set_font_scale(data->graphics.mlx, data->graphics.win,
		"textures/menu/MinimalPixel_v2.ttf", 50);
	mlx_string_put(data->graphics.mlx, data->graphics.win, 100, 100, 0xFFFFFFFF,
		"Settings");
}

void	render_settings(t_data *data)
{
	t_vec2i	pos_mouse;

	mlx_mouse_get_pos(data->graphics.mlx, &pos_mouse.x, &pos_mouse.y);
	render_settings_background(data);
	render_settings_title(data);
	data->graphics.settings.button_state_hover = NOTHING;
	mlx_set_font_scale(data->graphics.mlx, data->graphics.win,
		"textures/menu/MinimalPixel_v2.ttf", 35);
	render_settings_buttons(data, pos_mouse);
}
