/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_screen_state.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:41:28 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/29 21:40:39 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include "mlx.h"

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
