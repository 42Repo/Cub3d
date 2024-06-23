/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/23 14:08:50 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include <unistd.h>

void	other_move(t_data *data)
{
	data->settings.minimap_scale = 1;
	if (data->graphics.key_states[SDL_SCANCODE_Z])
		data->settings.minimap_scale = 1.5;
}

int	update(void *param)
{
	t_data	*d;
	static bool first = true;

	d = (t_data *)param;
	if (d->settings.screen_state == GAME)
	{
		if (first)
		{
			first = false;
			system("aplay -q /home/asuc/Documents/42/Cub3d/bonus/textures/menu/button_pressed.wav &");
			usleep(250000);
			mlx_mouse_hide();
		}
		mouse_move(d);
		move(d);
		other_move(d);
		render(d);
		fps_counter();
	}
	else if (d->settings.screen_state == MAIN_MENU)
	{
		update_button_states(d);
		render_menu(d);
	}
	else if (d->settings.screen_state == SETTINGS)
	{
		if (first)
		{
			first = false;
			system("aplay -q /home/asuc/Documents/42/Cub3d/bonus/textures/menu/button_pressed.wav &");
			usleep(250000);
		}
		// d->settings.screen_state = MAIN_MENU;
	}
	else if (d->settings.screen_state == EXIT)
	{
		if (first)
		{
			first = false;
			system("aplay -q /home/asuc/Documents/42/Cub3d/bonus/textures/menu/button_pressed.wav &");
			usleep(250000);
		}
		exit_game(*d, EXIT_GAME);
	}
	if (d->graphics.menu.play_button.is_pressed == true)
	{
		d->graphics.menu.play_button.is_pressed = false;
		d->settings.screen_state = GAME;
	}
	if (d->graphics.menu.exit_button.is_pressed == true)
	{
		d->graphics.menu.exit_button.is_pressed = false;
		d->settings.screen_state = EXIT;
	}
	if (d->graphics.menu.settings_button.is_pressed == true)
	{
		d->graphics.menu.settings_button.is_pressed = false;
		d->settings.screen_state = SETTINGS;
	}
	return (0);
}

int	key_press(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == SDL_SCANCODE_ESCAPE)
		exit_game(*data, EXIT_GAME);
	data->graphics.key_states[key] = 1;
	if (key == SDL_SCANCODE_F1)
		data->graphics.game.floor_and_ceiling = !data->graphics.game.floor_and_ceiling;
	return (0);
}

int	key_release(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->graphics.key_states[key] = 0;
	return (0);
}

int mouse_press(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)key;
	if (data->graphics.menu.play_button.is_hovered)
		data->graphics.menu.play_button.is_pressed = true;
	else if (data->graphics.menu.exit_button.is_hovered)
		data->graphics.menu.exit_button.is_pressed = true;
	else if (data->graphics.menu.settings_button.is_hovered)
		data->graphics.menu.settings_button.is_pressed = true;
	return (0);
}

int mouse_release(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)key;
	(void)data;
	return (0);
}