/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_buttons.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:50:07 by asuc              #+#    #+#             */
/*   Updated: 2024/07/06 16:15:10 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_settings_menu.h"

static int	is_mouse_over_button(t_vec2i pos_button, t_vec2i size_button, \
t_vec2i pos_mouse)
{
	return (pos_mouse.x >= pos_button.x \
	&& pos_mouse.x <= pos_button.x + size_button.x \
	&& pos_mouse.y >= pos_button.y \
	&& pos_mouse.y <= pos_button.y + size_button.y);
}

static void	render_button(t_data *data, t_button_info *button, \
t_vec2i pos_mouse)
{
	if (is_mouse_over_button(button->pos, button->size, pos_mouse) == 1)
	{
		data->graphics.settings.button_state_hover = button->hover_state;
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win, \
		data->graphics.settings.back_button.img_hovered.img, button->pos.x, \
		button->pos.y);
	}
	else
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win, \
	data->graphics.settings.back_button.img.img, button->pos.x, button->pos.y);
	mlx_string_put(data->graphics.mlx, data->graphics.win, button->pos.x - 300, \
	button->pos.y + 50, (int)(uintptr_t)0xFFFFFFFF, button->label);
	if (data->graphics.settings.waiting_for_key \
	&& data->graphics.settings.button_state_press == button->press_state)
		mlx_string_put(data->graphics.mlx, data->graphics.win, \
		button->pos.x + 20, button->pos.y + 50, \
		(int)(uintptr_t)0xFFFFFFFF, "Press a key");
	else
		mlx_string_put(data->graphics.mlx, data->graphics.win, \
	button->pos.x + 20, button->pos.y + 50, \
	(int)(uintptr_t)0xFFFFFFFF, \
	(char *)(uintptr_t)SDL_GetKeyName(SDL_GetKeyFromScancode(button->key)));
}

static t_button_info	*get_settings_buttons(t_data *data)
{
	static t_button_info	buttons[9];
	t_vec2i					sizes;

	sizes = (t_vec2i){data->graphics.settings.back_button.img.width, \
	data->graphics.settings.back_button.img.height};
	buttons[0] = (t_button_info){{700, 250}, sizes, MOVE_FORWARD, \
	MOVE_FORWARD, "Move forward", data->settings.key_move_forward};
	buttons[1] = (t_button_info){{700, 350}, sizes, MOVE_BACKWARD, \
	MOVE_BACKWARD, "Move backward", data->settings.key_move_backward};
	buttons[2] = (t_button_info){{700, 450}, sizes, MOVE_LEFT, \
	MOVE_LEFT, "Move left", data->settings.key_move_left};
	buttons[3] = (t_button_info){{700, 550}, sizes, MOVE_RIGHT, \
	MOVE_RIGHT, "Move right", data->settings.key_move_right};
	buttons[4] = (t_button_info){{700, 650}, sizes, SPRINT, \
	SPRINT, "Sprint", data->settings.key_sprint};
	buttons[5] = (t_button_info){{700, 750}, sizes, \
	MAP_ZOOM, MAP_ZOOM, "Map zoom", data->settings.key_map_zoom};
	buttons[6] = (t_button_info){{1250, 250}, sizes, \
	SHOW_FLOOR_AND_CEILING, SHOW_FLOOR_AND_CEILING, \
	"Floor and ceiling", data->settings.key_show_floor_and_ceiling};
	buttons[7] = (t_button_info){{1250, 350}, sizes, ROTATE_LEFT, \
	ROTATE_LEFT, "Rotate left", data->settings.key_rotate_left};
	buttons[8] = (t_button_info){{1250, 450}, sizes, ROTATE_RIGHT, \
	ROTATE_RIGHT, "Rotate right", data->settings.key_rotate_right};
	return (buttons);
}

void	render_settings_buttons(t_data *data, t_vec2i pos_mouse)
{
	t_button_info	*buttons;
	int				i;

	buttons = get_settings_buttons(data);
	i = 0;
	while (i < 9)
	{
		render_button(data, &buttons[i], pos_mouse);
		i++;
	}
}
