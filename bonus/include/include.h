/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:39:20 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/02 19:17:59 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "struct.h"

const char	*SDL_GetKeyName(int key);
int			SDL_GetKeyFromScancode(int scancode);

int			parsing(int ac, char **av, t_data *data);
int 		preload_textures(t_data *data);

void		init_data(t_data *d);
void		init_mlx(t_data *data);
void		print_first_background(t_data *data);
void		move(t_data *data);
void		mouse_move(t_data *data);

int			keyhook(int key, void *param);
int			key_press(int key, void *param);
int			key_release(int key, void *param);
int			mouse_press(int key, void *param);
int			mouse_release(int key, void *param);

int			destroy(int key, void *param)__attribute__((pure));
void		exit_game(t_data data, int status) __attribute__((noreturn));
void		fps_counter(void);

void		render_frame(t_data *data);
int			argb_to_int(t_color color);
void		render(t_data *data);
void		resize_images(t_data *data);

void		print_minimap(t_data *data);

void		render_menu(t_data *data);
void		init_menu(t_data *data);
void		update_button_states(t_data *data);

void		render_floor_and_ceiling(t_data *data);
int			update(void *param);

void		render_settings(t_data *data);
void		init_settings_menu(t_data *data);

void		screen_state_game(t_data *d);
void		screen_state_menu(t_data *d);
void		screen_state_settings(t_data *d);
void		screen_state_exit(t_data *d) __attribute__((noreturn));

#endif // INCLUDE_H