/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:10:56 by asuc              #+#    #+#             */
/*   Updated: 2024/06/21 05:28:04 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_menu.h"
#include <stdbool.h>


int is_mouse_over_button(t_button *button, int mouse_x, int mouse_y)
{
    return (mouse_x >= button->pos.x && mouse_x <= button->pos.x + button->size.x &&
            mouse_y >= button->pos.y && mouse_y <= button->pos.y + button->size.y);
}

void update_button_states(t_data *data)
{
    int mouse_x, mouse_y;
    mlx_mouse_get_pos(data->graphics.mlx, &mouse_x, &mouse_y);

    data->graphics.menu.play_button_is_hovered = is_mouse_over_button(&data->graphics.menu.play_button, mouse_x, mouse_y);
    // data->graphics.menu.settings_button.is_hovered = is_mouse_over_button(&data->graphics.menu.settings_button, mouse_x, mouse_y);
    // data->graphics.menu.exit_button.is_hovered = is_mouse_over_button(&data->graphics.menu.exit_button, mouse_x, mouse_y);
}

void render_menu(t_data *data)
{
    int button_x = (WIN_WIDTH / 2) - (data->graphics.menu.img_background_button.width / 2);
    int button_y = (WIN_HEIGHT / 2) - (data->graphics.menu.img_background_button.height / 2);

    mlx_put_image_to_window(data->graphics.mlx, data->graphics.win, data->graphics.menu.img_background.img, 0, 0);
    mlx_put_image_to_window(data->graphics.mlx, data->graphics.win, data->graphics.menu.img_background_button.img, button_x, button_y);
    
    if (data->graphics.menu.play_button_is_hovered)
       mlx_put_image_to_window(data->graphics.mlx, data->graphics.win, data->graphics.menu.play_button_hovered.img.img, data->graphics.menu.play_button_hovered.pos.x, data->graphics.menu.play_button_hovered.pos.y);
    else
        mlx_put_image_to_window(data->graphics.mlx, data->graphics.win, data->graphics.menu.play_button.img.img, data->graphics.menu.play_button.pos.x, data->graphics.menu.play_button.pos.y);

    // if (data->graphics.menu.settings_button.is_hovered)
    //     mlx_put_image_to_window(data->graphics.mlx, data->graphics.win, data->graphics.menu.settings_button.img.img, data->graphics.menu.settings_button.pos.x, data->graphics.menu.settings_button.pos.y);
    // else
    //     mlx_put_image_to_window(data->graphics.mlx, data->graphics.win, data->graphics.menu.settings_button.img.img, data->graphics.menu.settings_button.pos.x, data->graphics.menu.settings_button.pos.y);

    // if (data->graphics.menu.exit_button.is_hovered)
    //     mlx_put_image_to_window(data->graphics.mlx, data->graphics.win, data->graphics.menu.exit_button.img.img, data->graphics.menu.exit_button.pos.x, data->graphics.menu.exit_button.pos.y);
    // else
    //     mlx_put_image_to_window(data->graphics.mlx, data->graphics.win, data->graphics.menu.exit_button.img.img, data->graphics.menu.exit_button.pos.x, data->graphics.menu.exit_button.pos.y);
}