/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:41:16 by asuc              #+#    #+#             */
/*   Updated: 2024/06/29 13:44:42 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_menu.h"

static void	init_image(t_data *data, t_image *src, t_image *dst, t_vec2i *ratio)
{
	ratio->x = (src->width << 16) / dst->width + 1;
	ratio->y = (src->height << 16) / dst->height + 1;
	dst->img = mlx_new_image(data->graphics.mlx, dst->width, dst->height);
}

static void	resize_image(t_data *data, t_image *src, t_vec2i new_size)
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
			mlx_set_image_pixel(data->graphics.mlx, dst.img, pos_d.x, pos_d.y, \
			mlx_get_image_pixel(data->graphics.mlx, src->img, pos_s.x, pos_s.y));
			pos_d.x++;
		}
		pos_d.y++;
	}
	mlx_destroy_image(data->graphics.mlx, src->img);
	*src = dst;
}

void	load_menu_image(t_data *data, t_menu *m)
{
	m->img_background.img = mlx_png_file_to_image(data->graphics.mlx, "textures/menu/menu_background.png", &m->img_background.width, &m->img_background.height);
	m->img_background_button.img = mlx_png_file_to_image(data->graphics.mlx, "textures/menu/GUI.png", &m->img_background_button.width, &m->img_background_button.height);
	m->play_button.img.img = mlx_png_file_to_image(data->graphics.mlx, "textures/menu/start.png", &m->play_button.img.width, &m->play_button.img.height);
	m->play_button.img_hovered.img = mlx_png_file_to_image(data->graphics.mlx, "textures/menu/start_hovered.png", &m->play_button.img_hovered.width, &m->play_button.img_hovered.height);
	m->play_button.img_pressed.img = mlx_png_file_to_image(data->graphics.mlx, "textures/menu/start_pressed.png", &m->play_button.img_pressed.width, &m->play_button.img_pressed.height);
	m->exit_button.img.img = mlx_png_file_to_image(data->graphics.mlx, "textures/menu/exit.png", &m->exit_button.img.width, &m->exit_button.img.height);
	m->exit_button.img_hovered.img = mlx_png_file_to_image(data->graphics.mlx, "textures/menu/exit_hovered.png", &m->exit_button.img_hovered.width, &m->exit_button.img_hovered.height);
	m->exit_button.img_pressed.img = mlx_png_file_to_image(data->graphics.mlx, "textures/menu/exit_pressed.png", &m->exit_button.img_pressed.width, &m->exit_button.img_pressed.height);
	m->settings_button.img.img = mlx_png_file_to_image(data->graphics.mlx, "textures/menu/settings.png", &m->settings_button.img.width, &m->settings_button.img.height);
	m->settings_button.img_hovered.img = mlx_png_file_to_image(data->graphics.mlx, "textures/menu/settings_hovered.png", &m->settings_button.img_hovered.width, &m->settings_button.img_hovered.height);
	m->settings_button.img_pressed.img = mlx_png_file_to_image(data->graphics.mlx, "textures/menu/settings_pressed.png", &m->settings_button.img_pressed.width, &m->settings_button.img_pressed.height);
}

void	resize_menu_image(t_data *data, t_menu *m, t_vec2f scale_factor)
{
	t_vec2i	new_size;

	new_size = (t_vec2i){scale_factor.x * 7, scale_factor.y * 7};
	resize_image(data, &m->img_background, (t_vec2i){WIN_WIDTH, WIN_HEIGHT});
	resize_image(data, &m->img_background_button, (t_vec2i){m->img_background_button.width * new_size.x, m->img_background_button.height * new_size.y});
	resize_image(data, &m->play_button.img, (t_vec2i){m->play_button.img.width * new_size.x, m->play_button.img.height * new_size.y});
	resize_image(data, &m->play_button.img_hovered, (t_vec2i){m->play_button.img_hovered.width * new_size.x, m->play_button.img_hovered.height * new_size.y});
	resize_image(data, &m->play_button.img_pressed, (t_vec2i){m->play_button.img_pressed.width * new_size.x, m->play_button.img_pressed.height * new_size.y});
	resize_image(data, &m->exit_button.img, (t_vec2i){m->exit_button.img.width * new_size.x, m->exit_button.img.height * new_size.y});
	resize_image(data, &m->exit_button.img_hovered, (t_vec2i){m->exit_button.img_hovered.width * new_size.x, m->exit_button.img_hovered.height * new_size.y});
	resize_image(data, &m->exit_button.img_pressed, (t_vec2i){m->exit_button.img_pressed.width * new_size.x, m->exit_button.img_pressed.height * new_size.y});
	resize_image(data, &m->settings_button.img, (t_vec2i){m->settings_button.img.width * new_size.x, m->settings_button.img.height * new_size.y});
	resize_image(data, &m->settings_button.img_hovered, (t_vec2i){m->settings_button.img_hovered.width * new_size.x, m->settings_button.img_hovered.height * new_size.y});
	resize_image(data, &m->settings_button.img_pressed, (t_vec2i){m->settings_button.img_pressed.width * new_size.x, m->settings_button.img_pressed.height * new_size.y});
}

void	set_button_pos(t_menu *m, t_vec2f scale_factor)
{
	m->play_button.pos.x = (WIN_WIDTH / 2) - (m->img_background_button.width / 2) + 56 * scale_factor.x;
	m->play_button.pos.y = (WIN_HEIGHT / 2) - (m->img_background_button.height / 2) + 77 * scale_factor.y;
	m->play_button.size.x = m->play_button.img.width;
	m->play_button.size.y = m->play_button.img.height;
	m->settings_button.pos.x = m->play_button.pos.x;
	m->settings_button.pos.y = m->play_button.pos.y + m->play_button.size.y + 14 * scale_factor.y;
	m->settings_button.size.x = m->settings_button.img.width;
	m->settings_button.size.y = m->settings_button.img.height;
	m->exit_button.pos.x = m->settings_button.pos.x;
	m->exit_button.pos.y = m->settings_button.pos.y + m->settings_button.size.y + 14 * scale_factor.y;
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
	load_menu_image(data, m);
	resize_menu_image(data, m, scale_factor);
	set_button_pos(m, scale_factor);
	m->play_button.is_hovered = false;
	m->settings_button.is_hovered = false;
	m->exit_button.is_hovered = false;
	m->play_button.is_pressed = false;
	m->settings_button.is_pressed = false;
	m->exit_button.is_pressed = false;
}
