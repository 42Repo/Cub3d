/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:10:40 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/29 17:11:14 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_menu.h"

void	load_menu_image(t_data *data, t_menu *m)
{
	m->img_background.img = mlx_png_file_to_image (data->graphics.mlx, BACKGROUND, &m->img_background.width, &m->img_background.height);
	m->img_background_button.img = mlx_png_file_to_image (data->graphics.mlx, GUI, &m->img_background_button.width, &m->img_background_button.height);
	m->play_button.img.img = mlx_png_file_to_image (data->graphics.mlx, START, &m->play_button.img.width, &m->play_button.img.height);
	m->play_button.img_hovered.img = mlx_png_file_to_image (data->graphics.mlx, START_HOVERED, &m->play_button.img_hovered.width, &m->play_button.img_hovered.height);
	m->play_button.img_pressed.img = mlx_png_file_to_image (data->graphics.mlx, START_PRESSED, &m->play_button.img_pressed.width, &m->play_button.img_pressed.height);
	m->exit_button.img.img = mlx_png_file_to_image (data->graphics.mlx, EXIT_MENU, &m->exit_button.img.width, &m->exit_button.img.height);
	m->exit_button.img_hovered.img = mlx_png_file_to_image (data->graphics.mlx, EXIT_HOVERED, &m->exit_button.img_hovered.width, &m->exit_button.img_hovered.height);
	m->exit_button.img_pressed.img = mlx_png_file_to_image (data->graphics.mlx, EXIT_PRESSED, &m->exit_button.img_pressed.width, &m->exit_button.img_pressed.height);
	m->settings_button.img.img = mlx_png_file_to_image (data->graphics.mlx, SETTINGS_MENU, &m->settings_button.img.width, &m->settings_button.img.height);
	m->settings_button.img_hovered.img = mlx_png_file_to_image (data->graphics.mlx, SETTINGS_HOVERED, &m->settings_button.img_hovered.width, &m->settings_button.img_hovered.height);
	m->settings_button.img_pressed.img = mlx_png_file_to_image (data->graphics.mlx, SETTINGS_PRESSED, &m->settings_button.img_pressed.width, &m->settings_button.img_pressed.height);
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
