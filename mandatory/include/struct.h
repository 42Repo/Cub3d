/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:24:53 by asuc              #+#    #+#             */
/*   Updated: 2024/07/06 15:04:48 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../MacroLibX/includes/mlx.h"
# include "SDL2/SDL_scancode.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include <stdbool.h>

# define WIN_WIDTH 1700
# define WIN_HEIGHT 1080

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

typedef struct s_vec2f
{
	float		x;
	float		y;
}				t_vec2f;

typedef struct s_vec2i
{
	int			x;
	int			y;
}				t_vec2i;

typedef struct s_vec2_color
{
	float		x;
	float		y;
	int			color;
}				t_vec2_color;

typedef union u_color
{
	struct
	{
		uint8_t	a;
		uint8_t	r;
		uint8_t	g;
		uint8_t	b;
	};
	uint32_t	color;
}				t_color;

typedef struct s_square
{
	t_vec2f	x1;
	t_vec2f	x2;
	t_vec2f	x3;
	t_vec2f	x4;
}				t_square;

typedef enum e_status
{
	PARSING_ERROR,
	PRELOAD_ERROR,
	EXIT_GAME
}				t_status;

typedef enum e_wall
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}				t_wall;

typedef struct s_ray
{
	t_vec2f	pos;
	t_vec2f	dir;
	float		perp_wall_dist;
	t_vec2i	map;
	t_vec2i	step;
	t_vec2f	side_dist;
	t_vec2f	delta_dist;
	int			hit;
	int			side;
	t_wall		wall;
}				t_ray;

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
	t_vec2f	pos;
	t_vec2f	dir;
	t_vec2f	plane;
	float		move_speed;
	float		rot_speed;
}				t_player;

typedef struct s_image
{
	void		*img;
	int			width;
	int			height;
}				t_image;

typedef struct s_sprite
{
	int			width;
	int			height;
	char		*path_n;
	char		*path_s;
	char		*path_e;
	char		*path_w;
	t_image		wall_n;
	t_image		wall_s;
	t_image		wall_e;
	t_image		wall_w;
	int			*north_texture;
	int			*south_texture;
	int			*east_texture;
	int			*west_texture;
	t_color		floor_color;
	t_color		ceiling_color;
}				t_sprite;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img_background;
	t_sprite	wall_sprite;
	int			key_states[256];
}				t_mlx;

typedef struct s_data
{
	t_mlx		mlx;
	t_map		map;
	t_player	player;
}				t_data;

#endif // STRUCT_H