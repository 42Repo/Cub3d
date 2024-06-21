/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:24:53 by asuc              #+#    #+#             */
/*   Updated: 2024/06/21 05:24:06 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../MacroLibX/includes/mlx.h"
# include "SDL2/SDL_scancode.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define FOV 90.0

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

typedef struct s_vec2
{
	float			x;
	float			y;
}					t_vec2;

typedef struct s_vec2_int
{
	int				x;
	int				y;
}					t_vec2_int;

typedef union u_color
{
	struct
	{
		uint8_t		a;
		uint8_t		r;
		uint8_t		g;
		uint8_t		b;
	};
	uint32_t		color;
}					t_color;

typedef enum e_status
{
	PARSING_ERROR,
	PRELOAD_ERROR,
	EXIT_GAME
}					t_status;

typedef enum e_screen_state
{
	MAIN_MENU,
	GAME,
	PAUSE,
	END_GAME
}					t_screen_state;

typedef struct s_image
{
	void			*img;
	int				width;
	int				height;
}					t_image;

typedef struct s_map
{
	char			**map;
	int				rows;
	int				cols;
}					t_map;

typedef struct s_player
{
	t_vec2			pos;
	t_vec2			dir;
	t_vec2			plane;
	float			move_speed;
	float			rot_speed;
	float			pitch;
}					t_player;

typedef struct s_sprite
{
	int				width;
	int				height;
	char			*path_n;
	char			*path_s;
	char			*path_e;
	char			*path_w;
	t_image			wall_n;
	t_image			wall_s;
	t_image			wall_e;
	t_image			wall_w;
	int				*north_texture;
	int				*south_texture;
	int				*east_texture;
	int				*west_texture;
	t_color			floor_color;
	t_color			ceiling_color;
}					t_sprite;

typedef struct s_button
{
	t_image			img;
	t_vec2_int		pos;
	t_vec2_int		size;
}					t_button;

typedef struct s_menu
{
	t_image			img_background;
	t_image			img_background_button;
	t_button		play_button;
	t_button		play_button_hovered;
	bool			play_button_is_hovered;
	t_button		exit_button;
	t_button		settings_button;
}					t_menu;

typedef struct s_game
{
	void			*img_background;
}					t_game;

typedef struct s_graphics
{
	void			*mlx;
	void			*win;
	t_menu			menu;
	t_game			game;
	void			*img_mini_map;
	t_sprite		wall_sprite;
	int				key_states[256];
}					t_graphics;

typedef struct s_settings
{
	float			minimap_scale;
	t_screen_state	screen_state;
}					t_settings;

typedef struct s_data
{
	t_graphics		graphics;
	t_map			map;
	t_player		player;
	t_settings		settings;
}					t_data;

#endif // STRUCT_H