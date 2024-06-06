/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rectangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:13:11 by asuc              #+#    #+#             */
/*   Updated: 2024/06/05 22:05:37 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx_addon.h"
#include "struct.h"

void	mlx_draw_rectangle(void *mlx, void *img, t_square square, int color)
{
	mlx_draw_line(mlx, img, (t_vec2_color){square.x1.x, square.x1.y, color},
		(t_vec2){square.x2.x, square.x2.y});
	mlx_draw_line(mlx, img, (t_vec2_color){square.x2.x, square.x2.y, color},
		(t_vec2){square.x3.x, square.x3.y});
	mlx_draw_line(mlx, img, (t_vec2_color){square.x3.x, square.x3.y, color},
		(t_vec2){square.x4.x, square.x4.y});
	mlx_draw_line(mlx, img, (t_vec2_color){square.x4.x, square.x4.y, color},
		(t_vec2){square.x1.x, square.x1.y});
}

void mlx_draw_rectangle_full(void *mlx, void *img, t_square square, int color) {
    // On suppose que les points sont donnés dans l'ordre correct pour former un rectangle
    // On va remplir le rectangle en dessinant des lignes horizontales entre les côtés
    
    // On suppose que square.x1.x <= square.x2.x <= square.x3.x <= square.x4.x
    // et square.x1.y <= square.x2.y <= square.x3.y <= square.x4.y
    
    double min_x = fmin(fmin(square.x1.x, square.x2.x), fmin(square.x3.x, square.x4.x));
    double max_x = fmax(fmax(square.x1.x, square.x2.x), fmax(square.x3.x, square.x4.x));
    double min_y = fmin(fmin(square.x1.y, square.x2.y), fmin(square.x3.y, square.x4.y));
    double max_y = fmax(fmax(square.x1.y, square.x2.y), fmax(square.x3.y, square.x4.y));
    
    for (double y = min_y; y <= max_y; y++) {
        mlx_draw_line(mlx, img, (t_vec2_color){min_x, y, color}, (t_vec2){max_x, y});
    }
}