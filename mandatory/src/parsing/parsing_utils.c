/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:13:40 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/28 12:51:21 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_parsing.h"

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

void	file_to_char(int fd, char ***file)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (*line != '\n')
		{
			if (ft_strchr(line, '\n'))
				ft_extand_tab(file, ft_substr(line, 0, ft_strlen(line) - 1));
			else
				ft_extand_tab(file, ft_strdup(line));
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

size_t	ft_ctablen(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	print_parsing(t_data *data)
{
	char	**tmp;

	tmp = data->map.map;
	printf("NO: %s\n", data->mlx.wall_sprite.path_n);
	printf("SO: %s\n", data->mlx.wall_sprite.path_s);
	printf("WE: %s\n", data->mlx.wall_sprite.path_w);
	printf("EA: %s\n", data->mlx.wall_sprite.path_e);
	printf("F: %d, %d, %d\n", \
	data->mlx.wall_sprite.floor_color.r, \
	data->mlx.wall_sprite.floor_color.g, \
	data->mlx.wall_sprite.floor_color.b);
	printf("C: %d, %d, %d\n", \
	data->mlx.wall_sprite.ceiling_color.r, \
	data->mlx.wall_sprite.ceiling_color.g, \
	data->mlx.wall_sprite.ceiling_color.b);
	printf("Map:\n");
	while (*tmp)
	{
		printf("%s\n", *tmp);
		tmp++;
	}
}
