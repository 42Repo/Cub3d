/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/27 15:21:51 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	other_move(t_data *data)
{
	data->settings.minimap_scale = 1;
	if (data->graphics.key_states[SDL_SCANCODE_Z])
		data->settings.minimap_scale = 1.5;
}

void	screen_state_game(bool *first, t_data *d)
{
	if (*first)
	{
		*first = false;
		system("aplay -q ./textures/menu/button_pressed.wav &");
		usleep(250000);
		mlx_mouse_hide();
	}
	mouse_move(d);
	move(d);
	other_move(d);
	render(d);
	fps_counter();
}

void	screen_state_menu(t_data *d)
{
	update_button_states(d);
	render_menu(d);
}

void	screen_state_settings(bool *first, t_data *d)
{
	(void)d;
	if (first)
	{
		first = false;
		system("aplay -q ./textures/menu/button_pressed.wav &");
		usleep(250000);
	}
	// d->settings.screen_state = MAIN_MENU;
}

void	screen_state_exit(bool *first, t_data *d)
{
	if (first)
	{
		first = false;
		system("aplay -q ./textures/menu/button_pressed.wav &");
		usleep(250000);
	}
	exit_game(*d, EXIT_GAME);
}

void	press_button(t_data *d)
{
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
}

int	update(void *param)
{
	t_data		*d;
	static bool	first = true;

	d = (t_data *)param;
	if (d->settings.screen_state == GAME)
		screen_state_game(&first, d);
	else if (d->settings.screen_state == MAIN_MENU)
		screen_state_menu(d);
	else if (d->settings.screen_state == SETTINGS)
		screen_state_settings(&first, d);
	else if (d->settings.screen_state == EXIT)
		screen_state_exit(&first, d);
	press_button(d);
	return (0);
}

int	key_press(int key, void *param)
{
	t_data	*data;
	t_game	*g;

	data = (t_data *)param;
	g = &data->graphics.game;
	if (key == SDL_SCANCODE_ESCAPE)
		exit_game(*data, EXIT_GAME);
	data->graphics.key_states[key] = 1;
	if (key == SDL_SCANCODE_F1)
		g->floor_and_ceiling = !g->floor_and_ceiling;
	return (0);
}

int	key_release(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->graphics.key_states[key] = 0;
	return (0);
}

int	mouse_press(int key, void *param)
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

int	mouse_release(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)key;
	(void)data;
	return (0);
}
