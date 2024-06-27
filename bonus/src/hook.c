/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/27 15:41:20 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

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
