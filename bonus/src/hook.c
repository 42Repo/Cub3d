/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/27 17:08:00 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	key_press(int key, void *param)
{
	t_data	*data;
	t_game	*g;

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
	if (key == SDL_SCANCODE_ESCAPE && data->settings.screen_state == SETTINGS)
	{
		data->graphics.is_first_frame = true;
		data->settings.screen_state = MAIN_MENU;
	}
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
