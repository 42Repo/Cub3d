/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:16:22 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/27 13:07:23 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	next_power_of_two(int n)
{
	int	power;

	power = 1;
	while (power < n)
		power *= 2;
	return (power);
}

void	init_image(t_data *data, t_image *src, t_image *dst, t_vec2i *ratio)
{
	dst->width = next_power_of_two(src->width);
	dst->height = dst->width;
	ratio->x = (src->width << 16) / dst->width + 1;
	ratio->y = (src->height << 16) / dst->height + 1;
	dst->img = mlx_new_image(data->graphics.mlx, dst->width, dst->height);
}

static void	resize_image(t_data *data, t_image *src)
{
	t_image	dst;
	t_vec2i	ratio;
	t_vec2i	pos_src;
	t_vec2i	pos_dst;
	int		color;

	init_image(data, src, &dst, &ratio);
	pos_dst.y = 0;
	while (pos_dst.y < dst.height)
	{
		pos_dst.x = 0;
		while (pos_dst.x < dst.width)
		{
			pos_src.x = (pos_dst.x * ratio.x) >> 16;
			pos_src.y = (pos_dst.y * ratio.y) >> 16;
			color = mlx_get_image_pixel
				(data->graphics.mlx, src->img, pos_src.x, pos_src.y);
			mlx_set_image_pixel
				(data->graphics.mlx, dst.img, pos_dst.x, pos_dst.y, color);
			pos_dst.x++;
		}
		pos_dst.y++;
	}
	mlx_destroy_image(data->graphics.mlx, src->img);
	*src = dst;
}

void	resize_images(t_data *data)
{
	resize_image(data, &data->graphics.wall_sprite.wall_n);
	resize_image(data, &data->graphics.wall_sprite.wall_s);
	resize_image(data, &data->graphics.wall_sprite.wall_e);
	resize_image(data, &data->graphics.wall_sprite.wall_w);
}
