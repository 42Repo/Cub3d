/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:31:01 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/08 18:30:46 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# define WIN_WIDTH 1800
# define WIN_HEIGHT 1080

# define TILE_SIZE 32
# define LCLICK 1
# define RCLICK 3
# define WUP 1
# define WDOWN 2
# define UP 82
# define DOWN 81
# define LEFT 79
# define RIGHT 80
# define ESCAP 41
# define W 26
# define A 4
# define S 22
# define D 7

# define FOV 90
# define FOV_RAD (FOV * CUB_PI / 180)

# define CUB_2_PI 6.28318530717958647692
# define CUB_PI 3.14159265358979323846

# include "mlx_addon.h"

int		parsing(int ac, char **av, t_data *data);
char	**parse_file(char *file, t_map *map);
void	extand_map(char **map, size_t max_len);
void	format_map(char ***grid, t_map *map);

void	init_data(t_data *d);
void	init_mlx(t_data *data);
void	print_background(t_data *data);
void	print_map(t_data *data);
void	add_player(t_data d);
void	add_ray(t_data d);
int		update(void *param);

int		keyhook(int key, void *param);
int		key_press(int key, void *param);
int		key_release(int key, void *param);

int		destroy(int key, void *param);
void	exit_game(t_data data);
void	reset_image(t_data d, void *image);
void	fps_counter(void);

void	add_wall(t_data d, int i, float wall_size, t_ray *ray);
void	draw_ray(t_data d, int i, t_ray *ray);
void	add_ray(t_data d);
void	render_frame(t_data *data);
int		print_error(char *error);

#endif