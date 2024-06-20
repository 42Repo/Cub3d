/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:41:16 by asuc              #+#    #+#             */
/*   Updated: 2024/06/21 01:08:03 by asuc             ###   ########.fr       */
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

void	init_menu(t_data *data)
{
    data->graphics.menu.img_background.img = mlx_png_file_to_image(data->graphics.mlx, "textures/menu/menu_background.png", &data->graphics.menu.img_background.width, &data->graphics.menu.img_background.height);
    resize_image(data, &data->graphics.menu.img_background, (t_vec2_int){WIN_WIDTH, WIN_HEIGHT});
    data->graphics.menu.img_background_button.img = mlx_png_file_to_image(data->graphics.mlx, "textures/menu/GUI.png", &data->graphics.menu.img_background_button.width, &data->graphics.menu.img_background_button.height);
    resize_image(data, &data->graphics.menu.img_background_button, (t_vec2_int){data->graphics.menu.img_background_button.width * 1.5 , data->graphics.menu.img_background_button.height * 1.5});
}