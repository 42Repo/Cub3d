/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:35:28 by bgoron            #+#    #+#             */
/*   Updated: 2024/05/05 20:37:01 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	main(int ac, char **av)
{
	t_data	data;

	parsing(ac, av);
	init_data(av[1], &data);
	// print_background(&data);
	print_map(&data);
	init_mlx(&data);
	exit_game(data);
	return (EXIT_SUCCESS);
}
