/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:59:13 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/01 21:24:11 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	set_button_state(t_settings *settings, int button_state)
{
	settings->button_state_press = button_state;
	settings->waiting_for_key = true;
}

void	mouse_settings(t_data *data, t_settings *settings)
{
	if (settings->button_state_hover == MOVE_FORWARD)
		set_button_state(&data->graphics.settings, MOVE_FORWARD);
	else if (settings->button_state_hover == MOVE_BACKWARD)
		set_button_state(&data->graphics.settings, MOVE_BACKWARD);
	else if (settings->button_state_hover == MOVE_LEFT)
		set_button_state(&data->graphics.settings, MOVE_LEFT);
	else if (settings->button_state_hover == MOVE_RIGHT)
		set_button_state(&data->graphics.settings, MOVE_RIGHT);
	else if (settings->button_state_hover == ROTATE_LEFT)
		set_button_state(&data->graphics.settings, ROTATE_LEFT);
	else if (settings->button_state_hover == ROTATE_RIGHT)
		set_button_state(&data->graphics.settings, ROTATE_RIGHT);
	else if (settings->button_state_hover == SPRINT)
		set_button_state(&data->graphics.settings, SPRINT);
	else if (settings->button_state_hover == MAP_ZOOM)
		set_button_state(&data->graphics.settings, MAP_ZOOM);
	else if (settings->button_state_hover == SHOW_FLOOR_AND_CEILING)
		set_button_state(&data->graphics.settings, SHOW_FLOOR_AND_CEILING);
}

int	mouse_press(int __attribute__((unused)) key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->graphics.menu.play_button.is_hovered)
		data->graphics.menu.play_button.is_pressed = true;
	else if (data->graphics.menu.exit_button.is_hovered)
		data->graphics.menu.exit_button.is_pressed = true;
	else if (data->graphics.menu.settings_button.is_hovered)
		data->graphics.menu.settings_button.is_pressed = true;
	if (data->settings.screen_state == SETTINGS)
		mouse_settings(data, &data->graphics.settings);
	return (0);
}

int	mouse_release(int __attribute__((unused)) key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)data;
	return (0);
}
