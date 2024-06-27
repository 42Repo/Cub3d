/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:41:28 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/27 17:07:26 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include "mlx.h"

void	other_move(t_data *data)
{
	data->settings.minimap_scale = 1;
	if (data->graphics.key_states[SDL_SCANCODE_Z])
		data->settings.minimap_scale = 1.5;
}

void	screen_state_game(t_data *d)
{
	if (d->graphics.is_first_frame)
	{
		d->graphics.is_first_frame = false;
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
	mlx_clear_window(d->graphics.mlx, d->graphics.win);
	update_button_states(d);
	render_menu(d);
}

void	screen_state_settings(t_data *d)
{
	(void)d;
	if (d->graphics.is_first_frame)
	{
		d->graphics.is_first_frame = false;
		system("aplay -q ./textures/menu/button_pressed.wav &");
		usleep(250000);
		mlx_mouse_show();
	}
	render_settings(d);
	// d->settings.screen_state = MAIN_MENU;
}

void	screen_state_exit( t_data *d)
{
	if (d->graphics.is_first_frame)
	{
		d->graphics.is_first_frame = false;
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

	d = (t_data *)param;
	if (d->settings.screen_state == GAME)
		screen_state_game(d);
	else if (d->settings.screen_state == MAIN_MENU)
		screen_state_menu(d);
	else if (d->settings.screen_state == SETTINGS)
		screen_state_settings(d);
	else if (d->settings.screen_state == EXIT)
		screen_state_exit(d);
	press_button(d);
	return (0);
}
