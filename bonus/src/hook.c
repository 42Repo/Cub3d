/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/01 15:46:48 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include <complex.h>

int	key_press(int key, void *param)
{
	t_data	*data;
	t_game	*g;

	data = (t_data *)param;
    const char *keyname = SDL_GetKeyName(SDL_GetKeyFromScancode(key));
	printf("Key pressed: %s\n", keyname);

	g = &data->graphics.game;
	if (key == SDL_SCANCODE_ESCAPE && data->settings.screen_state == MAIN_MENU)
		exit_game(*data, EXIT_GAME);
	if (key == SDL_SCANCODE_ESCAPE && data->settings.screen_state == GAME)
	{
		data->graphics.is_first_frame = true;
		data->settings.screen_state = MAIN_MENU;
		mlx_mouse_show();
	}
	if (key == SDL_SCANCODE_ESCAPE && data->settings.screen_state == SETTINGS && !data->graphics.settings.waiting_for_key)
	{
		data->graphics.is_first_frame = true;
		data->settings.screen_state = MAIN_MENU;
	}
	data->graphics.key_states[key] = 1;
	if (key == data->settings.key_show_floor_and_ceiling)
		g->floor_and_ceiling = !g->floor_and_ceiling;
	if (data->graphics.settings.waiting_for_key && key != SDL_SCANCODE_ESCAPE)
	{
		data->graphics.settings.waiting_for_key = false;
		if (data->graphics.settings.button_state_press == MOVE_FORWARD)
			data->settings.key_move_forward = key;
		else if (data->graphics.settings.button_state_press == MOVE_BACKWARD)
			data->settings.key_move_backward = key;
		else if (data->graphics.settings.button_state_press == MOVE_LEFT)
			data->settings.key_move_left = key;
		else if (data->graphics.settings.button_state_press == MOVE_RIGHT)
			data->settings.key_move_right = key;
		else if (data->graphics.settings.button_state_press == ROTATE_LEFT)
			data->settings.key_rotate_left = key;
		else if (data->graphics.settings.button_state_press == ROTATE_RIGHT)
			data->settings.key_rotate_right = key;
		else if (data->graphics.settings.button_state_press == SPRINT)
			data->settings.key_sprint = key;
		else if (data->graphics.settings.button_state_press == MAP_ZOOM)
			data->settings.key_map_zoom = key;
		else if (data->graphics.settings.button_state_press == SHOW_FLOOR_AND_CEILING)
			data->settings.key_show_floor_and_ceiling = key;
	}
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
	if (data->graphics.settings.button_state_hover == MOVE_FORWARD)
	{
		data->graphics.settings.button_state_press = MOVE_FORWARD;
		data->graphics.settings.waiting_for_key = true;
		printf("Move forward\n");
	}
	else if (data->graphics.settings.button_state_hover == MOVE_BACKWARD)
	{
		data->graphics.settings.button_state_press = MOVE_BACKWARD;
		data->graphics.settings.waiting_for_key = true;
		printf("Move backward\n");
	}
	else if (data->graphics.settings.button_state_hover == MOVE_LEFT)
	{
		data->graphics.settings.button_state_press = MOVE_LEFT;
		data->graphics.settings.waiting_for_key = true;
		printf("Move left\n");
	}
	else if (data->graphics.settings.button_state_hover == MOVE_RIGHT)
	{
		data->graphics.settings.waiting_for_key = true;
		data->graphics.settings.button_state_press = MOVE_RIGHT;
		printf("Move right\n");
	}
	else if (data->graphics.settings.button_state_hover == ROTATE_LEFT)
	{
		data->graphics.settings.waiting_for_key = true;
		data->graphics.settings.button_state_press = ROTATE_LEFT;
		printf("Rotate left\n");
	}
	else if (data->graphics.settings.button_state_hover == ROTATE_RIGHT)
	{
		data->graphics.settings.waiting_for_key = true;
		data->graphics.settings.button_state_press = ROTATE_RIGHT;
		printf("Rotate right\n");
	}
	else if (data->graphics.settings.button_state_hover == SPRINT)
	{
		data->graphics.settings.button_state_press = SPRINT;
		data->graphics.settings.waiting_for_key = true;
		printf("Sprint\n");
	}
	else if (data->graphics.settings.button_state_hover == MAP_ZOOM)
	{
		data->graphics.settings.button_state_press = MAP_ZOOM;
		data->graphics.settings.waiting_for_key = true;
		printf("Map zoom\n");
	}
	else if (data->graphics.settings.button_state_hover == SHOW_FLOOR_AND_CEILING)
	{
		data->graphics.settings.button_state_press = SHOW_FLOOR_AND_CEILING;
		data->graphics.settings.waiting_for_key = true;
		printf("Show floor and ceiling\n");
	}
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

int	destroy(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (!key)
		exit_game(*data, EXIT_GAME);
	return (0);
}
