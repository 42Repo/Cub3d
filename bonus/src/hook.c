/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/20 18:39:48 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include <SDL2/SDL_scancode.h>

void	other_move(t_data *data)
{
	data->settings.minimap_scale = 1;
	if (data->mlx.key_states[SDL_SCANCODE_Z])
		data->settings.minimap_scale = 1.5;
}

int	update(void *param)
{
	t_data	*d;

	d = (t_data *)param;
	mouse_move(d);
	move(d);
	other_move(d);
	render(d);
	fps_counter();
	return (0);
}

int	key_press(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == SDL_SCANCODE_ESCAPE)
		exit_game(*data, EXIT_GAME);
	data->mlx.key_states[key] = 1;
	return (0);
}

int	key_release(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->mlx.key_states[key] = 0;
	return (0);
}
