/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:13:00 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/21 01:17:49 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include "mlx.h"
#include "struct.h"

void	other_move(t_data *data)
{
	data->settings.minimap_scale = 1;
	if (data->graphics.key_states[SDL_SCANCODE_Z])
		data->settings.minimap_scale = 1.5;
}

int	update(void *param)
{
	t_data	*d;

	d = (t_data *)param;
	d->settings.screen_state = GAME; // TODO remove this line
	if (d->settings.screen_state == GAME)
	{
		mlx_mouse_hide();
		mouse_move(d);
		move(d);
		other_move(d);
		render(d);
		fps_counter();
	}
	else if (d->settings.screen_state == MAIN_MENU)
	{
		mlx_mouse_show();
		render_menu(d);
	}
	return (0);
}

int	key_press(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == SDL_SCANCODE_ESCAPE)
		exit_game(*data, EXIT_GAME);
	data->graphics.key_states[key] = 1;
	return (0);
}

int	key_release(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->graphics.key_states[key] = 0;
	return (0);
}
