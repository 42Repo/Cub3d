/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:15:52 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/06 16:47:08 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_parsing.h"

static int	format_map(char ***grid, t_map *map)
{
	size_t	max_len;
	char	**tmp;

	if (!grid || !*grid)
		return (-1);
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
	if (extand_map(*grid, max_len) == -1)
		return (-1);
	return (0);
}

int	parse_map(char **file, t_data *data)
{
	char	**tmp;
	bool	has_empty_line;

	has_empty_line = false;
	tmp = file + 6;
	while (**tmp == '\0')
		(tmp)++;
	while (*tmp && has_empty_line == false)
	{
		if (**tmp == '\0')
			has_empty_line = true;
		else
			ft_extand_tab(&data->map.map, ft_strdup(*tmp));
		tmp++;
	}
	ft_free_tab((void **)file);
	if (has_empty_line == true \
	|| format_map(&data->map.map, &data->map) == -1)
		return (-1);
	else
		return (0);
}

int	reset_map(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
				map[i][j] = '0';
			else if (map[i][j] == '0')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
