/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rectangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:13:11 by asuc              #+#    #+#             */
/*   Updated: 2024/06/27 12:53:49 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx_addon.h"
#include "struct.h"

void	mlx_draw_rectangle(void *mlx, void *img, t_square square, int color)
{
	mlx_draw_line(mlx, img, (t_vec2_color){square.x1.x, square.x1.y, color},
		(t_vec2f){square.x2.x, square.x2.y});
	mlx_draw_line(mlx, img, (t_vec2_color){square.x2.x, square.x2.y, color},
		(t_vec2f){square.x3.x, square.x3.y});
	mlx_draw_line(mlx, img, (t_vec2_color){square.x3.x, square.x3.y, color},
		(t_vec2f){square.x4.x, square.x4.y});
	mlx_draw_line(mlx, img, (t_vec2_color){square.x4.x, square.x4.y, color},
		(t_vec2f){square.x1.x, square.x1.y});
}

void	mlx_draw_rectangle_full(void *mlx, void *img, t_square square,
		int color) // TODO : Implement this function
{
	(void)mlx;
	(void)img;
	(void)square;
	(void)color;
}
