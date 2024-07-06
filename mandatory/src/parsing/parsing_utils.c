/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:13:40 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/06 16:08:01 by bgoron           ###   ########.fr       */
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
			*tmp = ft_strjoin(*tmp, tmp2, 0b11);
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
