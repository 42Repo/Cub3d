/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:10:51 by bgoron            #+#    #+#             */
/*   Updated: 2024/05/04 22:07:16 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	extand_map(char **map, size_t max_len)
{
	char	**tmp;
	char	*tmp2;

	tmp = map;
	while (*tmp)
	{
		if (ft_strlen(*tmp) < max_len)
		{
			tmp2 = ft_calloc(sizeof(char), max_len - ft_strlen(*tmp) + 1);
			ft_memset(tmp2, ' ', max_len - ft_strlen(*tmp));
			*tmp = ft_strjoin(*tmp, tmp2, 0b11);
		}
		tmp++;
	}
}

void	format_map(char ***grid, t_map *map)
{
	size_t	max_len;
	char	**tmp;

	if (!grid || !*grid)
		return ;
	max_len = 0;
	tmp = *grid;
	while (*tmp)
	{
		if (max_len < ft_strlen(*tmp))
			max_len = ft_strlen(*tmp);
		tmp++;
	}
	map->cols = max_len;
	map->rows = tmp - *grid;
	extand_map(*grid, max_len);
}

char	**parse_file(char *file, t_map *map_data)
{
	int		fd;
	char	*line;
	char	**map;
	// int		i;

	// i = 0;
	map = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - !!ft_strlen(line)] == '\n')
			ft_extand_tab(&map, ft_substr(line, 0, ft_strlen(line) - 1));
		else
			ft_extand_tab(&map, ft_strdup(line));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	format_map(&map, map_data);
	return (map);
}

void	parsing(int ac, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0 || ac != 2)
	{
		close(fd);
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	close(fd);
}
