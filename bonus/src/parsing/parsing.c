/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:10:51 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/13 17:42:55 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_parsing.h"

void	set_player_dir_and_plane(char **map, int i, int j, t_player *player)
{
	if (map[i][j] == 'N')
	{
		player->dir = (t_vec2){0, -1};
		player->plane = (t_vec2){-0.66, 0};
	}
	else if (map[i][j] == 'S')
	{
		player->dir = (t_vec2){0, 1};
		player->plane = (t_vec2){0.66, 0};
	}
	else if (map[i][j] == 'W')
	{
		player->dir = (t_vec2){-1, 0};
		player->plane = (t_vec2){0, 0.66};
	}
	else if (map[i][j] == 'E')
	{
		player->dir = (t_vec2){1, 0};
		player->plane = (t_vec2){0, -0.66};
	}
	map[i][j] = '0';
	player->pos = (t_vec2){j + 0.5, i + 0.5};
	player->move_speed = 0.05;
	player->rot_speed = 0.05;
}

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
		return (print_error("Wrong number of arguments\n"));
	if (check_extension_file(av[1], ".cub") == -1)
		return (print_error("Wrong file extension\n"));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (print_error("Can't open file\n"));
	file_to_char(fd, &file);
	if (parse_texture(file, data) == -1)
		return (print_error("Can't parse texture\n"));
	if (parse_map(file, data) == -1)
		return (print_error("Can't parse map\n"));
	if (check_player(data->map.map, &data->player) == -1)
		return (print_error("Wrong player\n"));
	if (check_map_character(data->map.map) == -1)
		return (print_error("Wrong character in map\n"));
	if (check_unclosed_map(data->map.map) == -1)
		return (print_error("Unclosed map\n"));
	print_parsing(data);
	return (0);
}
