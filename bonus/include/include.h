/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:39:20 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/18 16:18:06 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "mlx_addon.h"

int		parsing(int ac, char **av, t_data *data);
void	preload_textures(t_data *data);

void	init_data(t_data *d);
void	init_mlx(t_data *data);
void	print_first_background(t_data *data);
int		update(void *param);
void	move(t_data *data);
void	mouse_move(t_data *data);

int		keyhook(int key, void *param);
int		key_press(int key, void *param);
int		key_release(int key, void *param);

int		destroy(int key, void *param);
void	exit_game(t_data data, int status);
void	fps_counter(void);

void	render_frame(t_data *data);
int		argb_to_int(t_color color);
int		print_error(char *error);
void	render(t_data *data);
void	resize_images(t_data *data);

#endif // INCLUDE_H