/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _mlx_addon.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:53:49 by asuc              #+#    #+#             */
/*   Updated: 2024/06/05 21:36:11 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MLX_ADDON_H
# define _MLX_ADDON_H

# include "../../include/include.h"
# include "struct.h"

typedef struct s_line_vars
{
	double	dx;
	double	dy;
	double	sx;
	double	sy;
	double	err;
	int		steps;
}			t_line_vars;

#endif // _MLX_ADDON_H