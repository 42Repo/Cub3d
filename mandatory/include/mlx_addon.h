/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_addon.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:14:26 by asuc              #+#    #+#             */
/*   Updated: 2024/06/27 12:52:42 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_ADDON_H
# define MLX_ADDON_H

# include "../MacroLibX/includes/mlx.h"
# include "struct.h"

void	mlx_draw_line_gradient(void *mlx, void *img, t_vec2_color a,
			t_vec2_color b);
void	mlx_draw_line(void *mlx, void *img, t_vec2_color a, t_vec2f b);
void	mlx_draw_rectangle(void *mlx, void *img, t_square square, int color);
void	mlx_draw_rectangle_full(void *mlx, void *img, t_square square,
			int color);

#endif // MLX_ADDON_H