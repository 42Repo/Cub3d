/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:01:19 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/02 06:04:29 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_raycasting.h"

static inline void	calculate_line_height_and_draw_points(t_ray *ray,
		t_ray_params *params)
{
	params->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	params->draw_start = (int)((WIN_HEIGHT - (float)params->line_height) / 2.0f
			+ (float)params->line_offset);
	if (params->draw_start < 0)
		params->draw_start = 0;
	params->draw_end = (int)((float)params->line_height / 2.0f + WIN_HEIGHT
			/ 2.0f + (float)params->line_offset);
	if (params->draw_end >= WIN_HEIGHT)
		params->draw_end = WIN_HEIGHT - 1;
}

static inline void	draw_texture(t_data *data, int x, t_ray_params *params)
{
	int	i;
	int	tex_y;
	int	color;

	i = params->draw_start;
	params->tex_pos = ((float)params->draw_start - (float)params->line_offset
			- WIN_HEIGHT / 2.0f + (float)params->line_height / 2.0f)
		* params->step;
	while (i < params->draw_end)
	{
		tex_y = ((int)params->tex_pos & (params->texture_height - 1));
		params->tex_pos += params->step;
		color = params->texture[tex_y * params->texture_width + params->tex_x];
		mlx_pixel_put(data->graphics.mlx, data->graphics.win, x, i, color);
		i++;
	}
}

static inline void	cast_ray(t_data *data, int x)
{
	t_ray_params	params;
	float			camera_x;

	camera_x = (2.0f * (float)x / (float)WIN_WIDTH - 1.0f)
		* tanf(data->settings.fov * (M_PI_F / 180.0f) / 2.0f);
	init_ray(&params.ray, &data->player, camera_x);
	calculate_step_and_side_dist(&params.ray);
	perform_dda(&params.ray, &data->map, &data->player);
	if (params.ray.hit == 2)
		return ;
	params.texture = select_texture(&params, &data->graphics.wall_sprite);
	params.line_offset = (int)(-data->player.pitch * WIN_HEIGHT);
	calculate_line_height_and_draw_points(&params.ray, &params);
	calculate_wall_x_and_tex_x(&params.ray, &params);
	params.step = (float)(1.0 * params.texture_height / params.line_height);
	draw_texture(data, x, &params);
}

void	render_frame(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIN_WIDTH)
	{
		cast_ray(data, i);
		i++;
	}
}
