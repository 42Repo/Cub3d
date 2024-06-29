/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:10:56 by asuc              #+#    #+#             */
/*   Updated: 2024/06/29 21:35:41 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_menu.h"

void	update_button_states(t_data *data)
{
	int		was_hovered;
	t_vec2i	mouse;

	was_hovered = data->graphics.menu.play_button.is_hovered;
	mlx_mouse_get_pos(data->graphics.mlx, &mouse.x, &mouse.y);
	data->graphics.menu.play_button.is_hovered = is_mouse_over_button \
	(&data->graphics.menu.play_button, mouse.x, mouse.y);
	if (was_hovered == 0 && data->graphics.menu.play_button.is_hovered == 1)
		system("aplay -q ./textures/menu/button_hover.wav &");
	was_hovered = data->graphics.menu.settings_button.is_hovered;
	data->graphics.menu.settings_button.is_hovered = is_mouse_over_button \
	(&data->graphics.menu.settings_button, mouse.x, mouse.y);
	if (was_hovered == 0 && data->graphics.menu.settings_button.is_hovered == 1)
		system("aplay -q ./textures/menu/button_hover.wav &");
	was_hovered = data->graphics.menu.exit_button.is_hovered;
	data->graphics.menu.exit_button.is_hovered = is_mouse_over_button \
	(&data->graphics.menu.exit_button, mouse.x, mouse.y);
	if (was_hovered == 0 && data->graphics.menu.exit_button.is_hovered == 1)
		system("aplay -q ./textures/menu/button_hover.wav &");
}

void	manage_play_button(t_data *data)
{
	if (data->graphics.menu.play_button.is_pressed)
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.menu.play_button.img_pressed.img,
			data->graphics.menu.play_button.pos.x,
			data->graphics.menu.play_button.pos.y + 8);
	else if (data->graphics.menu.play_button.is_hovered)
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.menu.play_button.img_hovered.img,
			data->graphics.menu.play_button.pos.x,
			data->graphics.menu.play_button.pos.y);
	else
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.menu.play_button.img.img,
			data->graphics.menu.play_button.pos.x,
			data->graphics.menu.play_button.pos.y);
}

void	manage_settings_button(t_data *data)
{
	if (data->graphics.menu.settings_button.is_pressed)
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.menu.settings_button.img_pressed.img,
			data->graphics.menu.settings_button.pos.x,
			data->graphics.menu.settings_button.pos.y + 8);
	else if (data->graphics.menu.settings_button.is_hovered)
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.menu.settings_button.img_hovered.img,
			data->graphics.menu.settings_button.pos.x,
			data->graphics.menu.settings_button.pos.y);
	else
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.menu.settings_button.img.img,
			data->graphics.menu.settings_button.pos.x,
			data->graphics.menu.settings_button.pos.y);
}

void	manage_exit_button(t_data *data)
{
	if (data->graphics.menu.exit_button.is_pressed)
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.menu.exit_button.img_pressed.img,
			data->graphics.menu.exit_button.pos.x,
			data->graphics.menu.exit_button.pos.y + 8);
	else if (data->graphics.menu.exit_button.is_hovered)
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.menu.exit_button.img_hovered.img,
			data->graphics.menu.exit_button.pos.x,
			data->graphics.menu.exit_button.pos.y);
	else
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.menu.exit_button.img.img,
			data->graphics.menu.exit_button.pos.x,
			data->graphics.menu.exit_button.pos.y);
}

void	render_menu(t_data *data)
{
	t_vec2i	button;

	button.x = (WIN_WIDTH / 2)
		- (data->graphics.menu.img_background_button.width / 2);
	button.y = (WIN_HEIGHT / 2)
		- (data->graphics.menu.img_background_button.height / 2);
	mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
		data->graphics.menu.img_background.img, 0, 0);
	mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
		data->graphics.menu.img_background_button.img, button.x, button.y);
	manage_play_button(data);
	manage_settings_button(data);
	manage_exit_button(data);
}
