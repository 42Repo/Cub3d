/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_addon.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:14:26 by asuc              #+#    #+#             */
/*   Updated: 2024/06/05 22:05:50 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_ADDON_H
# define MLX_ADDON_H

# include "../MacroLibX/includes/mlx.h"
# include "struct.h"

void	mlx_draw_line_gradient(void *mlx, void *img, t_vec2_color a,
			t_vec2_color b);
void	mlx_draw_line(void *mlx, void *img, t_vec2_color a, t_vec2 b);
void	mlx_draw_rectangle(void *mlx, void *img, t_square square, int color);
void	mlx_draw_rectangle_full(void *mlx, void *img, t_square square,
			int color);

#endif // MLX_ADDON_H