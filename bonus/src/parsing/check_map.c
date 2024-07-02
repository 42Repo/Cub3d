/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:11:56 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/02 04:36:31 by asuc             ###   ########.fr       */
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
			if (!ft_strchr(" 01D", map[i][j]))
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
		player->dir = (t_vec2f){0.0f, -1.0f};
		player->plane = (t_vec2f){0.66f, 0.0f};
	}
	else if (map[i][j] == 'S')
	{
		player->dir = (t_vec2f){0.0f, 1.0f};
		player->plane = (t_vec2f){-0.66f, 0.0f};
	}
	else if (map[i][j] == 'E')
	{
		player->dir = (t_vec2f){1.0f, 0.0f};
		player->plane = (t_vec2f){0.0f, 0.66f};
	}
	else if (map[i][j] == 'W')
	{
		player->dir = (t_vec2f){-1.0f, 0.0f};
		player->plane = (t_vec2f){0.0f, -0.66f};
	}
	map[i][j] = '0';
	player->pos = (t_vec2f){(float)j + 0.5f, (float)i + 0.5f};
	player->move_speed = 0.05f;
	player->rot_speed = 0.05f;
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
			else if (map[i][j] == 'D')
				check_valid_door(map, i, j);
			j++;
		}
		i++;
	}
	return (reset_map(map));
}
