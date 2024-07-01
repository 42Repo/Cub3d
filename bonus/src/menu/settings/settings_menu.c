/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:31:58 by asuc              #+#    #+#             */
/*   Updated: 2024/07/01 15:36:04 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_settings_menu.h"
#include "mlx.h"
#include "struct.h"

static int	is_mouse_over_button(t_vec2i pos_button, t_vec2i size_button,
		t_vec2i pos_mouse)
{
	if (pos_mouse.x >= pos_button.x && pos_mouse.x <= pos_button.x
		+ size_button.x && pos_mouse.y >= pos_button.y
		&& pos_mouse.y <= pos_button.y + size_button.y)
		return (1);
	return (0);
}

void	render_settings(t_data *data)
{
	t_vec2i	pos_mouse;

	mlx_mouse_get_pos(data->graphics.mlx, &pos_mouse.x, &pos_mouse.y);
	mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
		data->graphics.menu.img_background.img, 0, 0);
	mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
		data->graphics.settings.img_darken.img, 0, 0);
	mlx_set_font_scale(data->graphics.mlx, data->graphics.win,
		"textures/menu/MinimalPixel_v2.ttf", 50);
	mlx_string_put(data->graphics.mlx, data->graphics.win, 100, 100, 0xFFFFFFFF,
		"Settings");
	data->graphics.settings.button_state_hover = NOTHING;
	mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
		data->graphics.settings.img_background.img,
		data->graphics.settings.pos_img_background.x,
		data->graphics.settings.pos_img_background.y);
	mlx_set_font_scale(data->graphics.mlx, data->graphics.win,
		"textures/menu/MinimalPixel_v2.ttf", 35);
	mlx_string_put(data->graphics.mlx, data->graphics.win, 400, 300, 0xFFFFFFFF,
		"Move forward");
	if (is_mouse_over_button((t_vec2i){700, 250},
			(t_vec2i){data->graphics.settings.back_button.img.width,
			data->graphics.settings.back_button.img.height}, pos_mouse) == 1)
	{
		data->graphics.settings.button_state_hover = MOVE_FORWARD;
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.settings.back_button.img_hovered.img, 700, 250);
	}
	else
	{
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.settings.back_button.img.img, 700, 250);
	}
	if (data->graphics.settings.waiting_for_key == true && data->graphics.settings.button_state_press == MOVE_FORWARD)
	{
		mlx_string_put(data->graphics.mlx, data->graphics.win, 720, 300, 0xFFFFFFFF,
			"Press a key");
	}
	else
	{
		mlx_string_put(data->graphics.mlx, data->graphics.win, 720, 300, 0xFFFFFFFF,
    		(char *)SDL_GetKeyName(SDL_GetKeyFromScancode(data->settings.key_move_forward)));
	}
	mlx_string_put(data->graphics.mlx, data->graphics.win, 400, 400, 0xFFFFFFFF,
		"Move backward");
	if (is_mouse_over_button((t_vec2i){700, 350},
			(t_vec2i){data->graphics.settings.back_button.img.width,
			data->graphics.settings.back_button.img.height}, pos_mouse) == 1)
	{
		data->graphics.settings.button_state_hover = MOVE_BACKWARD;
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.settings.back_button.img_hovered.img, 700, 350);
	}
	else
	{
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.settings.back_button.img.img, 700, 350);
	}
	if (data->graphics.settings.waiting_for_key == true && data->graphics.settings.button_state_press == MOVE_BACKWARD)
	{
		mlx_string_put(data->graphics.mlx, data->graphics.win, 720, 400, 0xFFFFFFFF,
			"Press a key");
	}
	else
	{
		mlx_string_put(data->graphics.mlx, data->graphics.win, 720, 400, 0xFFFFFFFF,
			(char *)SDL_GetKeyName(SDL_GetKeyFromScancode(data->settings.key_move_backward)));
	}
	mlx_string_put(data->graphics.mlx, data->graphics.win, 400, 500, 0xFFFFFFFF,
		"Move left");
	if (is_mouse_over_button((t_vec2i){700, 450},
			(t_vec2i){data->graphics.settings.back_button.img.width,
			data->graphics.settings.back_button.img.height}, pos_mouse) == 1)
	{
		data->graphics.settings.button_state_hover = MOVE_LEFT;
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.settings.back_button.img_hovered.img, 700, 450);
	}
	else
	{
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.settings.back_button.img.img, 700, 450);
	}
	if (data->graphics.settings.waiting_for_key == true && data->graphics.settings.button_state_press == MOVE_LEFT)
	{
		mlx_string_put(data->graphics.mlx, data->graphics.win, 720, 500, 0xFFFFFFFF,
			"Press a key");
	}
	else
	{
		mlx_string_put(data->graphics.mlx, data->graphics.win, 720, 500, 0xFFFFFFFF,
			(char *)SDL_GetKeyName(SDL_GetKeyFromScancode(data->settings.key_move_left)));
	}
	mlx_string_put(data->graphics.mlx, data->graphics.win, 400, 600, 0xFFFFFFFF,
		"Move right");
	if (is_mouse_over_button((t_vec2i){700, 550},
			(t_vec2i){data->graphics.settings.back_button.img.width,
			data->graphics.settings.back_button.img.height}, pos_mouse) == 1)
	{
		data->graphics.settings.button_state_hover = MOVE_RIGHT;
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.settings.back_button.img_hovered.img, 700, 550);
	}
	else
	{
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.settings.back_button.img.img, 700, 550);
	}
	if (data->graphics.settings.waiting_for_key == true && data->graphics.settings.button_state_press == MOVE_RIGHT)
	{
		mlx_string_put(data->graphics.mlx, data->graphics.win, 720, 600, 0xFFFFFFFF,
			"Press a key");
	}
	else
	{
		mlx_string_put(data->graphics.mlx, data->graphics.win, 720, 600, 0xFFFFFFFF,
			(char *)SDL_GetKeyName(SDL_GetKeyFromScancode(data->settings.key_move_right)));
	}
	mlx_string_put(data->graphics.mlx, data->graphics.win, 400, 700, 0xFFFFFFFF,
		"Sprint");
	if (is_mouse_over_button((t_vec2i){700, 650},
			(t_vec2i){data->graphics.settings.back_button.img.width,
			data->graphics.settings.back_button.img.height}, pos_mouse) == 1)
	{
		data->graphics.settings.button_state_hover = SPRINT;
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.settings.back_button.img_hovered.img, 700, 650);
	}
	else
	{
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.settings.back_button.img.img, 700, 650);
	}
	if (data->graphics.settings.waiting_for_key == true && data->graphics.settings.button_state_press == SPRINT)
	{
		mlx_string_put(data->graphics.mlx, data->graphics.win, 720, 700, 0xFFFFFFFF,
			"Press a key");
	}
	else
	{
		mlx_string_put(data->graphics.mlx, data->graphics.win, 720, 700, 0xFFFFFFFF,
			(char *)SDL_GetKeyName(SDL_GetKeyFromScancode(data->settings.key_sprint)));
	}
	mlx_string_put(data->graphics.mlx, data->graphics.win, 400, 800, 0xFFFFFFFF,
		"Map zoom");
	if (is_mouse_over_button((t_vec2i){700, 750},
			(t_vec2i){data->graphics.settings.back_button.img.width,
			data->graphics.settings.back_button.img.height}, pos_mouse) == 1)
	{
		data->graphics.settings.button_state_hover = MAP_ZOOM;
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.settings.back_button.img_hovered.img, 700, 750);
	}
	else
	{
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.settings.back_button.img.img, 700, 750);
	}
	if (data->graphics.settings.waiting_for_key == true && data->graphics.settings.button_state_press == MAP_ZOOM)
	{
		mlx_string_put(data->graphics.mlx, data->graphics.win, 720, 800, 0xFFFFFFFF,
			"Press a key");
	}
	else
	{
		mlx_string_put(data->graphics.mlx, data->graphics.win, 720, 800, 0xFFFFFFFF,
			(char *)SDL_GetKeyName(SDL_GetKeyFromScancode(data->settings.key_map_zoom)));
	}
	mlx_string_put(data->graphics.mlx, data->graphics.win, 965, 300, 0xFFFFFFFF,
		"Floor and ceiling");
	if (is_mouse_over_button((t_vec2i){1250, 250},
			(t_vec2i){data->graphics.settings.back_button.img.width,
			data->graphics.settings.back_button.img.height}, pos_mouse) == 1)
	{
		data->graphics.settings.button_state_hover = SHOW_FLOOR_AND_CEILING;
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.settings.back_button.img_hovered.img, 1250, 250);
	}
	else
	{
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.settings.back_button.img.img, 1250, 250);
	}
	if (data->graphics.settings.waiting_for_key == true && data->graphics.settings.button_state_press == SHOW_FLOOR_AND_CEILING)
	{
		mlx_string_put(data->graphics.mlx, data->graphics.win, 1270, 300, 0xFFFFFFFF,
			"Press a key");
	}
	else
	{
		mlx_string_put(data->graphics.mlx, data->graphics.win, 1270, 300, 0xFFFFFFFF,
			(char *)SDL_GetKeyName(SDL_GetKeyFromScancode(data->settings.key_show_floor_and_ceiling)));
	}
	mlx_string_put(data->graphics.mlx, data->graphics.win, 965, 400, 0xFFFFFFFF,
		"Rotate left");
	if (is_mouse_over_button((t_vec2i){1250, 350},
			(t_vec2i){data->graphics.settings.back_button.img.width,
			data->graphics.settings.back_button.img.height}, pos_mouse) == 1)
	{
		data->graphics.settings.button_state_hover = ROTATE_LEFT;
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.settings.back_button.img_hovered.img, 1250, 350);
	}
	else
	{
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.settings.back_button.img.img, 1250, 350);
	}
	if (data->graphics.settings.waiting_for_key == true && data->graphics.settings.button_state_press == ROTATE_LEFT)
	{
		mlx_string_put(data->graphics.mlx, data->graphics.win, 1270, 400, 0xFFFFFFFF,
			"Press a key");
	}
	else
	{
		mlx_string_put(data->graphics.mlx, data->graphics.win, 1270, 400, 0xFFFFFFFF,
			(char *)SDL_GetKeyName(SDL_GetKeyFromScancode(data->settings.key_rotate_left)));
	}	
	mlx_string_put(data->graphics.mlx, data->graphics.win, 965, 500, 0xFFFFFFFF,
		"Rotate right");
	if (is_mouse_over_button((t_vec2i){1250, 450},
			(t_vec2i){data->graphics.settings.back_button.img.width,
			data->graphics.settings.back_button.img.height}, pos_mouse) == 1)
	{
		data->graphics.settings.button_state_hover = ROTATE_RIGHT;
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.settings.back_button.img_hovered.img, 1250, 450);
	}
	else
	{
		mlx_put_image_to_window(data->graphics.mlx, data->graphics.win,
			data->graphics.settings.back_button.img.img, 1250, 450);
	}
	if (data->graphics.settings.waiting_for_key == true && data->graphics.settings.button_state_press == ROTATE_RIGHT)
	{
		mlx_string_put(data->graphics.mlx, data->graphics.win, 1270, 500, 0xFFFFFFFF,
			"Press a key");
	}
	else
	{
		mlx_string_put(data->graphics.mlx, data->graphics.win, 1270, 500, 0xFFFFFFFF,
			(char *)SDL_GetKeyName(SDL_GetKeyFromScancode(data->settings.key_rotate_right)));
	}	
}