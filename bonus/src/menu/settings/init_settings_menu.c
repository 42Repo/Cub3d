/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_settings_menu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:26:54 by asuc              #+#    #+#             */
/*   Updated: 2024/07/06 16:28:39 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_settings_menu.h"

static void	init_image(t_data *data, t_image *src, t_image *dst, t_vec2i *ratio)
{
	ratio->x = (src->width << 16) / dst->width + 1;
	ratio->y = (src->height << 16) / dst->height + 1;
	dst->img = mlx_new_image(data->graphics.mlx, dst->width, dst->height);
}

static void	resize_image(t_data *data, t_image *src, t_vec2i new_size)
{
	t_image	dst;
	t_vec2i	ratio;
	t_vec2i	pos_src;
	t_vec2i	pos_dst;

	dst.width = new_size.x;
	dst.height = new_size.y;
	init_image(data, src, &dst, &ratio);
	pos_dst.y = 0;
	while (pos_dst.y < dst.height)
	{
		pos_dst.x = 0;
		while (pos_dst.x < dst.width)
		{
			pos_src.x = (pos_dst.x * ratio.x) >> 16;
			pos_src.y = (pos_dst.y * ratio.y) >> 16;
			mlx_set_image_pixel(data->graphics.mlx, dst.img, pos_dst.x,
				pos_dst.y, mlx_get_image_pixel(data->graphics.mlx, src->img,
					pos_src.x, pos_src.y));
			pos_dst.x++;
		}
		pos_dst.y++;
	}
	mlx_destroy_image(data->graphics.mlx, src->img);
	*src = dst;
}

static void	set_menu_var(t_data *data, t_graphics *g, t_settings *s)
{
	s->img_background = g->menu.img_background;
	s->img_background.img = mlx_png_file_to_image(g->mlx, BACKGROUND_SETTING,
			&s->img_background.width, &s->img_background.height);
	resize_image(data, &s->img_background, (t_vec2i){s->img_background.width
		* 7, s->img_background.height * 7});
	s->pos_img_background.x = (int)WIN_WIDTH / 2 \
	- s->img_background.width / 2;
	s->pos_img_background.y = (int)WIN_HEIGHT / 2 \
	- s->img_background.height / 2;
	s->back_button.img.img = mlx_png_file_to_image(g->mlx, BACK_BUTTON_PRESSED,
			&s->back_button.img.width, &s->back_button.img.height);
	s->back_button.img_hovered.img = mlx_png_file_to_image(g->mlx,
			BACK_BUTTON_HOVERED, &s->back_button.img_hovered.width,
			&s->back_button.img_hovered.height);
	data->graphics.settings.button_state_hover = NOTHING;
	data->graphics.settings.waiting_for_key = false;
	data->settings.key_map_zoom = SDL_SCANCODE_LALT;
	data->settings.key_move_backward = SDL_SCANCODE_S;
	data->settings.key_move_forward = SDL_SCANCODE_W;
	data->settings.key_move_left = SDL_SCANCODE_A;
	data->settings.key_move_right = SDL_SCANCODE_D;
	data->settings.key_rotate_left = SDL_SCANCODE_Q;
	data->settings.key_rotate_right = SDL_SCANCODE_E;
	data->settings.key_sprint = SDL_SCANCODE_LCTRL;
	data->settings.key_show_floor_and_ceiling = SDL_SCANCODE_F;
}

void	init_settings_menu(t_data *data)
{
	t_graphics	*g;
	int			i;
	int			j;

	g = &data->graphics;
	g->settings.img_darken.img = mlx_new_image(g->mlx, WIN_WIDTH, WIN_HEIGHT);
	i = 0;
	while (i < (int)WIN_HEIGHT)
	{
		j = 0;
		while (j < (int)WIN_WIDTH)
		{
			mlx_set_image_pixel(g->mlx, g->settings.img_darken.img, j, i,
				(int)(uintptr_t)0xBF000000);
			j++;
		}
		i++;
	}
	set_menu_var(data, g, &g->settings);
}
