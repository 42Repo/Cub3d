/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _menu.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 20:10:38 by asuc              #+#    #+#             */
/*   Updated: 2024/06/29 21:36:20 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MENU_H
# define _MENU_H

# include "include.h"

void	set_menu_image(t_data *data, t_menu *m, t_vec2f scale_factor);
void	resize_image(t_data *data, t_image *src, t_vec2i new_size);
int		is_mouse_over_button(t_button *button, int mouse_x, int mouse_y);

#endif // _MENU_H