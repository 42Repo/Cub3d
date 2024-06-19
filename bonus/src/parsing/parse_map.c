/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:15:52 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/19 11:50:43 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_parsing.h"

static void	format_map(char ***grid, t_map *map)
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

int	parse_map(char **file, t_data *data)
{
	char	**tmp;

	tmp = file + 6;
	while (*tmp)
	{
		ft_extand_tab(&data->map.map, ft_strdup(*tmp));
		tmp++;
	}
	ft_free_tab((void **)file);
	format_map(&data->map.map, &data->map);
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
			else if (map[i][j] == 'V')
				map[i][j] = 'D';
			else if (map[i][j] == '0')
				return (-1);
			else if (map[i][j] == 'D')
				return (-2);
			j++;
		}
		i++;
	}
	return (0);
}
