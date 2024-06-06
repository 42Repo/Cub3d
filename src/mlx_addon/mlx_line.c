/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:13:12 by asuc              #+#    #+#             */
/*   Updated: 2024/06/06 19:56:02 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx_addon.h"
#include "_mlx_addon.h"

static int	interpolate_color(int color1, int color2, double t)
{
	int	r1;
	int	g1;
	int	b1;
	int	g2;
	int	b2;

	r1 = (color1 >> 16) & 0xFF;
	g1 = (color1 >> 8) & 0xFF;
	b1 = color1 & 0xFF;
	g2 = (color2 >> 8) & 0xFF;
	b2 = color2 & 0xFF;
	return (0xFF000000 + (((int)(r1 + t * (((color2 >> 16) & 0xFF)
						- r1))) << 16) | (((int)(g1 + t * (g2
						- g1))) << 8) | ((int)(b1 + t * (b2 - b1))));
}

static void	calculate_line_vars(t_line_vars *vars, int steps, t_vec2_color *a,
		double *t)
{
	double	e2;

	e2 = vars->err;
	if (e2 > -vars->dx)
	{
		vars->err -= vars->dy;
		a->x += vars->sx;
	}
	if (e2 < vars->dy)
	{
		vars->err += vars->dx;
		a->y += vars->sy;
	}
	(*t) += 1.0 / steps;
}

static void	setup_line_vars(t_line_vars *vars, t_vec2_color a, t_vec2_color b)
{
	vars->dx = fabs(b.x - a.x);
	vars->dy = fabs(b.y - a.y);
	if (a.x < b.x)
		vars->sx = 1;
	else
		vars->sx = -1;
	if (a.y < b.y)
		vars->sy = 1;
	else
		vars->sy = -1;
	if (vars->dx > vars->dy)
		vars->err = vars->dx / 2;
	else
		vars->err = -vars->dy / 2;
}

void	mlx_draw_line_gradient(void *mlx, void *img, t_vec2_color a,
		t_vec2_color b)
{
	t_line_vars	vars;
	int			steps;
	double		t;

	t = 0.0;
	setup_line_vars(&vars, a, b);
	if (vars.dx > vars.dy)
		steps = vars.dx + 1;
	else
		steps = vars.dy + 1;
	while (1)
	{
		mlx_set_image_pixel(mlx, img, (int)a.x, (int)a.y,
			interpolate_color(a.color, b.color, t));
		if ((int)a.x == (int)b.x && (int)a.y == (int)b.y)
			break ;
		calculate_line_vars(&vars, steps, &a, &t);
	}
}

void	mlx_draw_line(void *mlx, void *img, t_vec2_color a, t_vec2 b)
{
	t_line_vars	vars;
	int			steps;
	double		t;

	t = 0.0;
	setup_line_vars(&vars, a, (t_vec2_color){b.x, b.y, 0});
	if (vars.dx > vars.dy)
		steps = vars.dx + 1;
	else
		steps = vars.dy + 1;
	while (1)
	{
		mlx_set_image_pixel(mlx, img, (int)a.x, (int)a.y, a.color);
		if ((int)a.x == (int)b.x && (int)a.y == (int)b.y)
			break ;
		calculate_line_vars(&vars, steps, &a, &t);
	}
}
