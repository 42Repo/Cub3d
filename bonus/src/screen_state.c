/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 21:40:07 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/01 13:50:54 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	screen_state_game(t_data *d)
{
	if (d->graphics.is_first_frame)
	{
		d->graphics.is_first_frame = false;
		system("paplay ./textures/menu/button_pressed.wav &");
		usleep(250000);
		mlx_mouse_hide();
	}
	mouse_move(d);
	move(d);
	d->settings.minimap_scale = 1;
	if (d->graphics.key_states[SDL_SCANCODE_Z])
		d->settings.minimap_scale = 1.5;
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
	if (d->graphics.is_first_frame)
	{
		d->graphics.is_first_frame = false;
		system("paplay ./textures/menu/button_pressed.wav &");
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
		system("paplay ./textures/menu/button_pressed.wav &");
		usleep(250000);
	}
	exit_game(*d, EXIT_GAME);
}
