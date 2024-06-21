/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:10:56 by asuc              #+#    #+#             */
/*   Updated: 2024/06/21 02:51:38 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_menu.h"

void render_menu(t_data *data)
{
    float scale_factor_width = (float)WIN_WIDTH / 1920.0f;
    float scale_factor_height = (float)WIN_HEIGHT / 1080.0f;
    int button_x = (WIN_WIDTH / 2) - (data->graphics.menu.img_background_button.width / 2);
    int button_y = (WIN_HEIGHT / 2) - (data->graphics.menu.img_background_button.height / 2);
    int play_button_y_offset = (77 * scale_factor_height);
    int settings_button_y_offset = play_button_y_offset + data->graphics.menu.img_play.height + (14 * scale_factor_height);
    int exit_button_y_offset = settings_button_y_offset + data->graphics.menu.img_settings.height + (14 * scale_factor_height);


    mlx_put_image_to_window(data->graphics.mlx, data->graphics.win, data->graphics.menu.img_background.img, 0, 0);
    mlx_put_image_to_window(data->graphics.mlx, data->graphics.win, data->graphics.menu.img_background_button.img, button_x, button_y);
    mlx_put_image_to_window(data->graphics.mlx, data->graphics.win, data->graphics.menu.img_play.img, button_x + 56 * scale_factor_width, button_y + play_button_y_offset);
    mlx_put_image_to_window(data->graphics.mlx, data->graphics.win, data->graphics.menu.img_settings.img, button_x + 56 * scale_factor_width, button_y + settings_button_y_offset);
    mlx_put_image_to_window(data->graphics.mlx, data->graphics.win, data->graphics.menu.img_exit.img, button_x + 56 * scale_factor_width, button_y + exit_button_y_offset);
}