/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _mlx_addon.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:53:49 by asuc              #+#    #+#             */
/*   Updated: 2024/06/08 19:08:31 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MLX_ADDON_H
# define _MLX_ADDON_H

# include "../../include/include.h"
# include "struct.h"

typedef struct s_line_vars
{
	float	dx;
	float	dy;
	float	sx;
	float	sy;
	float	err;
	int		steps;
}			t_line_vars;

#endif // _MLX_ADDON_H