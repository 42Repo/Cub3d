/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:11:56 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/18 18:36:48 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_parsing.h"

int	check_map_character(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(" 01", map[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	set_player_dir_and_plane(char **map, int i, int j, t_player *player)
{
	if (map[i][j] == 'N')
	{
		player->dir = (t_vec2){0, -1};
		player->plane = (t_vec2){0.66, 0};
	}
	else if (map[i][j] == 'S')
	{
		player->dir = (t_vec2){0, 1};
		player->plane = (t_vec2){-0.66, 0};
	}
	else if (map[i][j] == 'E')
	{
		player->dir = (t_vec2){1, 0};
		player->plane = (t_vec2){0, 0.66};
	}
	else if (map[i][j] == 'W')
	{
		player->dir = (t_vec2){-1, 0};
		player->plane = (t_vec2){0, -0.66};
	}
	map[i][j] = '0';
	player->pos = (t_vec2){j + 0.5, i + 0.5};
	player->move_speed = 0.05;
	player->rot_speed = 0.05;
}

int	check_player(char **map, t_player *player)
{
	int	i;
	int	j;
	int	player_count;

	player_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				player_count++;
				if (player_count == 1)
					set_player_dir_and_plane(map, i, j, player);
			}
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (-1);
	return (0);
}

static void	check_valid_zero(char **map, size_t i, size_t j)
{
	if (!i || !j || i == ft_ctablen(map) - 1 || j == ft_strlen(*map) - 1)
		return ;
	if ((map[i - 1][j] == '0' || map[i - 1][j] == '1' || map[i - 1][j] == '2')
	&& (map[i + 1][j] == '0' || map[i + 1][j] == '1' || map[i + 1][j] == '2')
	&& (map[i][j - 1] == '0' || map[i][j - 1] == '1' || map[i][j - 1] == '2')
	&& (map[i][j + 1] == '0' || map[i][j + 1] == '1' || map[i][j + 1] == '2'))
		map[i][j] = '2';
}

int	check_unclosed_map(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				check_valid_zero(map, i, j);
			j++;
		}
		i++;
	}
	if (reset_map(map) == -1)
		return (-1);
	return (0);
}
