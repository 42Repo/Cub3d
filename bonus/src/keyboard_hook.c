/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/01 16:59:21 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include <complex.h>

void	map_keyboard(t_data *data, int key)
{
	t_settings	*settings;

	settings = &data->graphics.settings;
	settings->waiting_for_key = false;
	if (settings->button_state_press == MOVE_FORWARD)
		data->settings.key_move_forward = key;
	else if (settings->button_state_press == MOVE_BACKWARD)
		data->settings.key_move_backward = key;
	else if (settings->button_state_press == MOVE_LEFT)
		data->settings.key_move_left = key;
	else if (settings->button_state_press == MOVE_RIGHT)
		data->settings.key_move_right = key;
	else if (settings->button_state_press == ROTATE_LEFT)
		data->settings.key_rotate_left = key;
	else if (settings->button_state_press == ROTATE_RIGHT)
		data->settings.key_rotate_right = key;
	else if (settings->button_state_press == SPRINT)
		data->settings.key_sprint = key;
	else if (settings->button_state_press == MAP_ZOOM)
		data->settings.key_map_zoom = key;
	else if (settings->button_state_press == SHOW_FLOOR_AND_CEILING)
		data->settings.key_show_floor_and_ceiling = key;
}

int	key_press(int key, void *param)
{
	t_data		*data;
	t_game		*g;

	data = (t_data *)param;
	g = &data->graphics.game;
	if (key == SDL_SCANCODE_ESCAPE && data->settings.screen_state == MAIN_MENU)
		exit_game(*data, EXIT_GAME);
	if (key == SDL_SCANCODE_ESCAPE && data->settings.screen_state == GAME)
	{
		data->graphics.is_first_frame = true;
		data->settings.screen_state = MAIN_MENU;
		mlx_mouse_show();
	}
	if (key == SDL_SCANCODE_ESCAPE && data->settings.screen_state == SETTINGS \
	&& !data->graphics.settings.waiting_for_key)
	{
		data->graphics.is_first_frame = true;
		data->settings.screen_state = MAIN_MENU;
	}
	data->graphics.key_states[key] = 1;
	if (key == data->settings.key_show_floor_and_ceiling)
		g->floor_and_ceiling = !g->floor_and_ceiling;
	if (data->graphics.settings.waiting_for_key && key != SDL_SCANCODE_ESCAPE)
		map_keyboard(data, key);
	return (0);
}

int	key_release(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->graphics.key_states[key] = 0;
	return (0);
}

int	destroy(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (!key)
		exit_game(*data, EXIT_GAME);
	return (0);
}