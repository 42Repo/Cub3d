/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:41:16 by asuc              #+#    #+#             */
/*   Updated: 2024/06/29 21:35:46 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_menu.h"

int	is_mouse_over_button(t_button *button, int mouse_x, int mouse_y)
{
	return (mouse_x >= button->pos.x && mouse_x <= button->pos.x
		+ button->size.x && mouse_y >= button->pos.y && mouse_y <= button->pos.y
		+ button->size.y);
}

static void	init_image(t_data *data, t_image *src, t_image *dst, t_vec2i *ratio)
{
	ratio->x = (src->width << 16) / dst->width + 1;
	ratio->y = (src->height << 16) / dst->height + 1;
	dst->img = mlx_new_image(data->graphics.mlx, dst->width, dst->height);
}

void	resize_image(t_data *data, t_image *src, t_vec2i new_size)
{
	t_image	dst;
	t_vec2i	ratio;
	t_vec2i	pos_s;
	t_vec2i	pos_d;

	dst.width = new_size.x;
	dst.height = new_size.y;
	init_image(data, src, &dst, &ratio);
	pos_d.y = 0;
	while (pos_d.y < dst.height)
	{
		pos_d.x = 0;
		while (pos_d.x < dst.width)
		{
			pos_s.x = (pos_d.x * ratio.x) >> 16;
			pos_s.y = (pos_d.y * ratio.y) >> 16;
			mlx_set_image_pixel(data->graphics.mlx, \
			dst.img, pos_d.x, pos_d.y, mlx_get_image_pixel \
			(data->graphics.mlx, src->img, pos_s.x, pos_s.y));
			pos_d.x++;
		}
		pos_d.y++;
	}
	mlx_destroy_image(data->graphics.mlx, src->img);
	*src = dst;
}

void	set_button_pos(t_menu *m, t_vec2f scale_factor)
{
	m->play_button.pos.x = (WIN_WIDTH / 2) \
	- (m->img_background_button.width / 2) + 56 * scale_factor.x;
	m->play_button.pos.y = (WIN_HEIGHT / 2) \
	- (m->img_background_button.height / 2) + 77 * scale_factor.y;
	m->play_button.size.x = m->play_button.img.width;
	m->play_button.size.y = m->play_button.img.height;
	m->settings_button.pos.x = m->play_button.pos.x;
	m->settings_button.pos.y = m->play_button.pos.y \
	+ m->play_button.size.y + 14 * scale_factor.y;
	m->settings_button.size.x = m->settings_button.img.width;
	m->settings_button.size.y = m->settings_button.img.height;
	m->exit_button.pos.x = m->settings_button.pos.x;
	m->exit_button.pos.y = m->settings_button.pos.y + \
	m->settings_button.size.y + 14 * scale_factor.y;
	m->exit_button.size.x = m->exit_button.img.width;
	m->exit_button.size.y = m->exit_button.img.height;
}

void	init_menu(t_data *data)
{
	t_menu	*m;
	t_vec2f	scale_factor;

	scale_factor.x = (float)WIN_WIDTH / 1920.0f;
	scale_factor.y = (float)WIN_HEIGHT / 1080.0f;
	m = &data->graphics.menu;
	set_menu_image(data, m, scale_factor);
	set_button_pos(m, scale_factor);
	m->play_button.is_hovered = false;
	m->settings_button.is_hovered = false;
	m->exit_button.is_hovered = false;
	m->play_button.is_pressed = false;
	m->settings_button.is_pressed = false;
	m->exit_button.is_pressed = false;
}
