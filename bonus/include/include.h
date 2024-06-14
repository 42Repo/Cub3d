/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:31:01 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/14 18:24:47 by asuc             ###   ########.fr       */
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
void	exit_game(t_data data);
void	fps_counter(void);

void	render_frame(t_data *data);
int		print_error(char *error);

#endif