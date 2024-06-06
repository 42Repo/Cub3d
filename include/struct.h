/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:24:53 by asuc              #+#    #+#             */
/*   Updated: 2024/06/06 19:16:43 by asuc             ###   ########.fr       */
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

typedef struct s_vec2
{
	double		x;
	double		y;
}				t_vec2;

typedef struct s_vec2_color
{
	double		x;
	double		y;
	int			color;
}				t_vec2_color;

typedef struct s_square
{
	t_vec2		x1;
	t_vec2		x2;
	t_vec2		x3;
	t_vec2		x4;
}				t_square;

typedef enum e_wall
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}				t_wall;

typedef struct s_ray
{
	t_vec2		pos;
	t_vec2		dir;
	double		perp_wall_dist;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			hit;
	int			side;
}				t_ray;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			map_width;
	int			map_height;
	int			rows;
	int			cols;
}				t_map;

typedef struct s_player
{
	t_vec2		pos;
	t_vec2		dir;
	t_vec2		plane;
	double		move_speed;
	double		rot_speed;
}				t_player;

typedef struct s_sprite
{
	void		*wall_n;
	void		*wall_s;
	void		*wall_e;
	void		*wall_w;
}				t_sprite;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img_background;
	void		*img_wall;
	void		*img_map;
	void		*img_player;
	t_sprite	wall_sprite;
	size_t		ray_nb;
	double		*wall_dist;
	int			key_states[256];
}				t_mlx;

typedef struct s_data
{
	t_mlx		mlx;
	t_map		map;
	t_player	player;
}				t_data;

#endif // STRUCT_H