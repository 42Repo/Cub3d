/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:13:40 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/06 16:34:55 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_parsing.h"

int	extand_map(char **map, size_t max_len)
{
	char	**tmp;
	char	*tmp2;

	tmp = map;
	while (*tmp)
	{
		if (ft_strlen(*tmp) < max_len)
		{
			tmp2 = ft_calloc(sizeof(char), max_len - ft_strlen(*tmp) + 1);
			if (!tmp2)
				return (-1);
			ft_memset(tmp2, ' ', max_len - ft_strlen(*tmp));
			*tmp = ft_strjoin(*tmp, tmp2, 0x3);
		}
		tmp++;
	}
	return (0);
}

void	file_to_char(int fd, char ***file)
{
	char	*line;
	int		nb_arg;

	nb_arg = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (*line != '\n' || nb_arg >= 8)
		{
			if (ft_strchr(line, '\n'))
				ft_extand_tab(file, ft_substr(line, 0, ft_strlen(line) - 1));
			else
				ft_extand_tab(file, ft_strdup(line));
			nb_arg++;
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

void	check_valid_zero(char **map, size_t i, size_t j)
{
	if (!i || !j || i == ft_ctablen(map) - 1 || j == ft_strlen(*map) - 1)
		return ;
	if ((map[i - 1][j] == '0' || map[i - 1][j] == '1' || map[i - 1][j] == '2' \
	|| map[i - 1][j] == 'D' || map[i - 1][j] == 'V') \
	&& (map[i + 1][j] == '0' || map[i + 1][j] == '1' || map[i + 1][j] == '2' \
	|| map[i + 1][j] == 'D' || map[i + 1][j] == 'V') \
	&& (map[i][j - 1] == '0' || map[i][j - 1] == '1' || map[i][j - 1] == '2' \
	|| map[i][j - 1] == 'D' || map[i][j - 1] == 'V') \
	&& (map[i][j + 1] == '0' || map[i][j + 1] == '1' || map[i][j + 1] == '2' \
	|| map[i][j + 1] == 'D' || map[i][j + 1] == 'V'))
		map[i][j] = '2';
}

void	check_valid_door(char **map, size_t i, size_t j)
{
	int	nb_of_path;

	if (!i || !j || i == ft_ctablen(map) - 1 || j == ft_strlen(*map) - 1)
		return ;
	nb_of_path = 0;
	nb_of_path += (map[i - 1][j] == '0' || map[i - 1][j] == '2');
	nb_of_path += (map[i + 1][j] == '0' || map[i + 1][j] == '2');
	nb_of_path += (map[i][j - 1] == '0' || map[i][j - 1] == '2');
	nb_of_path += (map[i][j + 1] == '0' || map[i][j + 1] == '2');
	if (nb_of_path >= 2)
		map[i][j] = 'V';
}
