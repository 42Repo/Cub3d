/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _settings_menu.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:32:19 by asuc              #+#    #+#             */
/*   Updated: 2024/07/01 21:51:47 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SETTINGS_MENU_H
# define _SETTINGS_MENU_H

# include "include.h"

typedef struct s_button_info
{
	t_vec2i			pos;
	t_vec2i			size;
	t_button_state	hover_state;
	t_button_state	press_state;
	char			*label;
	SDL_Scancode	key;
}					t_button_info;

void				render_settings_buttons(t_data *data, t_vec2i pos_mouse);

#endif