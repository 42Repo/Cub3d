/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:10:40 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/02 05:55:03 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_menu.h"

static void	set_background_image(t_data *data, t_menu *m, t_vec2f scale_factor)
{
	t_vec2i	new_size;

	new_size = (t_vec2i){(int)scale_factor.x * 7, (int)scale_factor.y * 7};
	m->img_background.img = mlx_png_file_to_image (data->graphics.mlx, \
	BACKGROUND, &m->img_background.width, &m->img_background.height);
	resize_image(data, &m->img_background, (t_vec2i){WIN_WIDTH, WIN_HEIGHT});
	m->img_background_button.img = mlx_png_file_to_image (data->graphics.mlx, \
	GUI, &m->img_background_button.width, &m->img_background_button.height);
	resize_image(data, &m->img_background_button, \
	(t_vec2i){m->img_background_button.width * new_size.x, \
	m->img_background_button.height * new_size.y});
}

static void	set_start_button(t_data *data, t_menu *m, t_vec2f scale_factor)
{
	t_vec2i	new_size;

	new_size = (t_vec2i){(int)scale_factor.x * 7, (int)scale_factor.y * 7};
	m->play_button.img.img = mlx_png_file_to_image (data->graphics.mlx, \
	START, &m->play_button.img.width, &m->play_button.img.height);
	resize_image(data, &m->play_button.img, \
	(t_vec2i){m->play_button.img.width * new_size.x, \
	m->play_button.img.height * new_size.y});
	m->play_button.img_hovered.img = mlx_png_file_to_image (data->graphics.mlx, \
	START_HOVERED, &m->play_button.img_hovered.width, \
	&m->play_button.img_hovered.height);
	resize_image(data, &m->play_button.img_hovered, \
	(t_vec2i){m->play_button.img_hovered.width * new_size.x, \
	m->play_button.img_hovered.height * new_size.y});
	m->play_button.img_pressed.img = mlx_png_file_to_image (data->graphics.mlx, \
	START_PRESSED, &m->play_button.img_pressed.width, \
	&m->play_button.img_pressed.height);
	resize_image(data, &m->play_button.img_pressed, \
	(t_vec2i){m->play_button.img_pressed.width * new_size.x, \
	m->play_button.img_pressed.height * new_size.y});
}

static void	set_exit_button(t_data *data, t_menu *m, t_vec2f scale_factor)
{
	t_vec2i	new_size;

	new_size = (t_vec2i){(int)scale_factor.x * 7, (int)scale_factor.y * 7};
	m->exit_button.img.img = mlx_png_file_to_image (data->graphics.mlx, \
	EXIT_MENU, &m->exit_button.img.width, &m->exit_button.img.height);
	resize_image(data, &m->exit_button.img, \
	(t_vec2i){m->exit_button.img.width * new_size.x, \
	m->exit_button.img.height * new_size.y});
	m->exit_button.img_hovered.img = mlx_png_file_to_image (data->graphics.mlx, \
	EXIT_HOVERED, &m->exit_button.img_hovered.width, \
	&m->exit_button.img_hovered.height);
	resize_image(data, &m->exit_button.img_hovered, \
	(t_vec2i){m->exit_button.img_hovered.width * new_size.x, \
	m->exit_button.img_hovered.height * new_size.y});
	m->exit_button.img_pressed.img = mlx_png_file_to_image (data->graphics.mlx, \
	EXIT_PRESSED, &m->exit_button.img_pressed.width, \
	&m->exit_button.img_pressed.height);
	resize_image(data, &m->exit_button.img_pressed, \
	(t_vec2i){m->exit_button.img_pressed.width * new_size.x, \
	m->exit_button.img_pressed.height * new_size.y});
}

static void	set_settings_button(t_data *data, t_menu *m, t_vec2f scale_factor)
{
	t_vec2i	new_size;

	new_size = (t_vec2i){(int)scale_factor.x * 7, (int)scale_factor.y * 7};
	m->settings_button.img.img = mlx_png_file_to_image (data->graphics.mlx, \
	SETTINGS_MENU, &m->settings_button.img.width, \
	&m->settings_button.img.height);
	resize_image(data, &m->settings_button.img, \
	(t_vec2i){m->settings_button.img.width * new_size.x, \
	m->settings_button.img.height * new_size.y});
	m->settings_button.img_hovered.img = mlx_png_file_to_image \
	(data->graphics.mlx, SETTINGS_HOVERED, \
	&m->settings_button.img_hovered.width, \
	&m->settings_button.img_hovered.height);
	resize_image(data, &m->settings_button.img_hovered, \
	(t_vec2i){m->settings_button.img_hovered.width * new_size.x, \
	m->settings_button.img_hovered.height * new_size.y});
	m->settings_button.img_pressed.img = mlx_png_file_to_image \
	(data->graphics.mlx, SETTINGS_PRESSED, \
	&m->settings_button.img_pressed.width, \
	&m->settings_button.img_pressed.height);
	resize_image(data, &m->settings_button.img_pressed, \
	(t_vec2i){m->settings_button.img_pressed.width * new_size.x, \
	m->settings_button.img_pressed.height * new_size.y});
}

void	set_menu_image(t_data *data, t_menu *m, t_vec2f scale_factor)
{
	set_background_image(data, m, scale_factor);
	set_start_button(data, m, scale_factor);
	set_exit_button(data, m, scale_factor);
	set_settings_button(data, m, scale_factor);
}
