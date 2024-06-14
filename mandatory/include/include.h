/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:31:01 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/14 17:05:04 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "mlx_addon.h"

void	init_data(t_data *d);
void	init_mlx(t_data *data);
void	print_first_background(t_data *data);

int		update(void *param);
int		keyhook(int key, void *param);
int		key_press(int key, void *param);
int		key_release(int key, void *param);
void	move(t_data *data);

int		destroy(int key, void *param);
void	exit_game(t_data data);

void	render_frame(t_data *data);

int		parsing(int ac, char **av, t_data *data);

#endif