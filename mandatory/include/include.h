/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:31:01 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/16 17:36:16 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "mlx_addon.h"

void	init_data(t_data *d);
void	init_mlx(t_data *data);
void	print_first_background(t_data *data);
int		preload_textures(t_data *data);

int		update(void *param);
int		keyhook(int key, void *param);
int		key_press(int key, void *param);
int		key_release(int key, void *param);
void	move(t_data *data);

int		destroy(int key, void *param);
void	exit_game(t_data data, int status);

void	render_frame(t_data *data);

int		parsing(int ac, char **av, t_data *data);
int		print_error(char *error);

#endif // INCLUDE_H