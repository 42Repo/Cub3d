/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:10:56 by asuc              #+#    #+#             */
/*   Updated: 2024/06/21 01:08:35 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_menu.h"
#include "struct.h"

void	render_menu(t_data *data)
{
    int button_x = (WIN_WIDTH / 2) - (data->graphics.menu.img_background_button.height / 2);
    int button_y = (WIN_HEIGHT / 2) - (data->graphics.menu.img_background_button.width / 2);
    mlx_put_image_to_window(data->graphics.mlx, data->graphics.win, data->graphics.menu.img_background.img, 0, 0);
    mlx_put_image_to_window(data->graphics.mlx, data->graphics.win, data->graphics.menu.img_background_button.img, button_x, button_y);
}