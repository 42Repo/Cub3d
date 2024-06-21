/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:41:16 by asuc              #+#    #+#             */
/*   Updated: 2024/06/21 05:24:51 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_menu.h"
#include "struct.h"

static void	init_image(t_data *data, t_image *src, t_image *dst, t_vec2_int *ratio)
{
	ratio->x = (src->width << 16) / dst->width + 1;
	ratio->y = (src->height << 16) / dst->height + 1;
	dst->img = mlx_new_image(data->graphics.mlx, dst->width, dst->height);
}

static void	resize_image(t_data *data, t_image *src, t_vec2_int new_size)
{
	t_image		dst;
	t_vec2_int	ratio;
	t_vec2_int	pos_src;
	t_vec2_int	pos_dst;

    dst.width = new_size.x;
    dst.height = new_size.y;
	init_image(data, src, &dst, &ratio);
	pos_dst.y = 0;
	while (pos_dst.y < dst.height)
	{
		pos_dst.x = 0;
		while (pos_dst.x < dst.width)
		{
			pos_src.x = (pos_dst.x * ratio.x) >> 16;
			pos_src.y = (pos_dst.y * ratio.y) >> 16;
			mlx_set_image_pixel
				(data->graphics.mlx, dst.img, pos_dst.x, pos_dst.y, mlx_get_image_pixel
				(data->graphics.mlx, src->img, pos_src.x, pos_src.y));
			pos_dst.x++;
		}
		pos_dst.y++;
	}
	mlx_destroy_image(data->graphics.mlx, src->img);
	*src = dst;
}

void init_menu(t_data *data)
{
    float scale_factor_width = (float)WIN_WIDTH / 1920.0f;
    float scale_factor_height = (float)WIN_HEIGHT / 1080.0f;

    data->graphics.menu.img_background.img = mlx_png_file_to_image(data->graphics.mlx, "textures/menu/menu_background.png", &data->graphics.menu.img_background.width, &data->graphics.menu.img_background.height);
    resize_image(data, &data->graphics.menu.img_background, (t_vec2_int){WIN_WIDTH, WIN_HEIGHT});

    data->graphics.menu.img_background_button.img = mlx_png_file_to_image(data->graphics.mlx, "textures/menu/GUI.png", &data->graphics.menu.img_background_button.width, &data->graphics.menu.img_background_button.height);
    resize_image(data, &data->graphics.menu.img_background_button, (t_vec2_int){data->graphics.menu.img_background_button.width * scale_factor_width * 7, data->graphics.menu.img_background_button.height * scale_factor_height * 7});

    data->graphics.menu.play_button.img.img = mlx_png_file_to_image(data->graphics.mlx, "textures/menu/start.png", &data->graphics.menu.play_button.img.width, &data->graphics.menu.play_button.img.height);
    resize_image(data, &data->graphics.menu.play_button.img, (t_vec2_int){data->graphics.menu.play_button.img.width * scale_factor_width * 7, data->graphics.menu.play_button.img.height * scale_factor_height * 7});

	data->graphics.menu.play_button_hovered.img.img = mlx_png_file_to_image(data->graphics.mlx, "textures/menu/start_hovered.png", &data->graphics.menu.play_button_hovered.img.width, &data->graphics.menu.play_button_hovered.img.height);
	resize_image(data, &data->graphics.menu.play_button_hovered.img, (t_vec2_int){data->graphics.menu.play_button_hovered.img.width * scale_factor_width * 7, data->graphics.menu.play_button_hovered.img.height * scale_factor_height * 7});

    data->graphics.menu.exit_button.img.img = mlx_png_file_to_image(data->graphics.mlx, "textures/menu/exit.png", &data->graphics.menu.exit_button.img.width, &data->graphics.menu.exit_button.img.height);
    resize_image(data, &data->graphics.menu.exit_button.img, (t_vec2_int){data->graphics.menu.exit_button.img.width * scale_factor_width * 7, data->graphics.menu.exit_button.img.height * scale_factor_height * 7});

    data->graphics.menu.settings_button.img.img = mlx_png_file_to_image(data->graphics.mlx, "textures/menu/settings.png", &data->graphics.menu.settings_button.img.width, &data->graphics.menu.settings_button.img.height);
    resize_image(data, &data->graphics.menu.settings_button.img, (t_vec2_int){data->graphics.menu.settings_button.img.width * scale_factor_width * 7, data->graphics.menu.settings_button.img.height * scale_factor_height * 7});


    // Initialiser les positions des boutons
    data->graphics.menu.play_button.pos = (t_vec2_int){(WIN_WIDTH / 2) - (data->graphics.menu.img_background_button.width / 2) + 56 * scale_factor_width, (WIN_HEIGHT / 2) - (data->graphics.menu.img_background_button.height / 2) + 77 * scale_factor_height};
    data->graphics.menu.play_button.size = (t_vec2_int){data->graphics.menu.play_button.img.width, data->graphics.menu.play_button.img.height};

	data->graphics.menu.play_button_hovered.pos = (t_vec2_int){data->graphics.menu.play_button.pos.x , data->graphics.menu.play_button.pos.y + 8};
	data->graphics.menu.play_button_hovered.size = (t_vec2_int){data->graphics.menu.play_button_hovered.img.width, data->graphics.menu.play_button_hovered.img.height};

    data->graphics.menu.settings_button.pos = (t_vec2_int){data->graphics.menu.play_button.pos.x, data->graphics.menu.play_button.pos.y + data->graphics.menu.play_button.size.y + 14 * scale_factor_height};
    data->graphics.menu.settings_button.size = (t_vec2_int){data->graphics.menu.settings_button.img.width, data->graphics.menu.settings_button.img.height};

	data->graphics.menu.exit_button.pos = (t_vec2_int){data->graphics.menu.settings_button.pos.x, data->graphics.menu.settings_button.pos.y + data->graphics.menu.settings_button.size.y + 14 * scale_factor_height};
	data->graphics.menu.exit_button.size = (t_vec2_int){data->graphics.menu.exit_button.img.width, data->graphics.menu.exit_button.img.height};


	data->graphics.menu.play_button_is_hovered = false;
}