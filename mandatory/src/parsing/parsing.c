/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:10:51 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/06 16:10:26 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_parsing.h"

int	print_error(char *error)
{
	printf("\033[1;31mError\n%s\033[0m\n", error);
	return (-1);
}

int	parsing(int ac, char **av, t_data *data)
{
	int		fd;
	char	**file;

	file = NULL;
	if (ac != 2)
		return (print_error("Wrong number of arguments"));
	if (check_extension_file(av[1], ".cub") == -1)
		return (print_error("Wrong file extension"));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (print_error("Can't open file"));
	file_to_char(fd, &file);
	if (!file)
		return (print_error("Empty file"));
	if (parse_texture(file, data) == -1)
		return (print_error("Can't parse texture"));
	if (parse_map(file, data) == -1)
		return (print_error("Can't parse map"));
	if (check_player(data->map.map, &data->player) == -1)
		return (print_error("Wrong player"));
	if (check_map_character(data->map.map) == -1)
		return (print_error("Wrong character in map"));
	if (check_unclosed_map(data->map.map) == -1)
		return (print_error("Unclosed map"));
	return (0);
}
