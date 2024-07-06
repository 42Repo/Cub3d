/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/06 14:09:03 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static bool is_key_already_mapped(t_data *data, int key)
{
	if (key == data->settings.key_move_forward || key == data->settings.key_move_backward
		|| key == data->settings.key_move_left || key == data->settings.key_move_right
		|| key == data->settings.key_rotate_left || key == data->settings.key_rotate_right
		|| key == data->settings.key_sprint || key == data->settings.key_map_zoom
		|| key == data->settings.key_show_floor_and_ceiling)
		return (true);
	return (false);
}

static void	map_keyboard(t_data *data, int key)
{
	t_settings	*settings;

	settings = &data->graphics.settings;
	settings->waiting_for_key = false;
	if (settings->button_state_press == MOVE_FORWARD && !is_key_already_mapped(data, key))
		data->settings.key_move_forward = key;
	else if (settings->button_state_press == MOVE_BACKWARD && !is_key_already_mapped(data, key))
		data->settings.key_move_backward = key;
	else if (settings->button_state_press == MOVE_LEFT && !is_key_already_mapped(data, key))
		data->settings.key_move_left = key;
	else if (settings->button_state_press == MOVE_RIGHT && !is_key_already_mapped(data, key))
		data->settings.key_move_right = key;
	else if (settings->button_state_press == ROTATE_LEFT && !is_key_already_mapped(data, key))
		data->settings.key_rotate_left = key;
	else if (settings->button_state_press == ROTATE_RIGHT && !is_key_already_mapped(data, key))
		data->settings.key_rotate_right = key;
	else if (settings->button_state_press == SPRINT && !is_key_already_mapped(data, key))
		data->settings.key_sprint = key;
	else if (settings->button_state_press == MAP_ZOOM && !is_key_already_mapped(data, key))
		data->settings.key_map_zoom = key;
	else if (settings->button_state_press == SHOW_FLOOR_AND_CEILING && !is_key_already_mapped(data, key))
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
