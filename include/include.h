/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:31:01 by bgoron            #+#    #+#             */
/*   Updated: 2024/05/05 04:17:51 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# define TILE_SIZE 64
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

# define CUB_2_PI 6.28318530717958647692
# define CUB_PI 3.14159265358979323846
# define CUB_PI_2 1.57079632679489661923
# define CUB_PI_3 1.04719755119659774615
# define CUB_PI_4 0.78539816339744830962
# define CUB_PI_5 0.62831853071795864769
# define CUB_PI_6 0.52359877559829887308
# define CUB_PI_7 0.44879895051282760589
# define CUB_PI_8 0.39269908169872415481

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "SDL2/SDL_scancode.h"
# include "mlx.h"
# include <time.h>

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			rows;
	int			cols;
}				t_map;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	double		angle;
	double		speed;
}				t_player;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img_background;
	void		*img_wall;
	void		*img_map;
	void		*img_player;
	size_t		ray_nb;
	double		*wall_dist;
	char		input_map[65536];
}				t_mlx;

typedef struct s_data
{
	t_mlx		mlx;
	t_map		map;
	t_player	player;
}				t_data;

void	parsing(int ac, char **av);
char	**parse_file(char *file, t_map *map);
void	extand_map(char **map, size_t max_len);
void	format_map(char ***grid, t_map *map);

void	init_data(char *file, t_data *d);
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

#endif
