/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:10:51 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/12 16:59:55 by bgoron           ###   ########.fr       */
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

void	set_border(char **map, t_map *map_data)
{
	char	**tmp;

	tmp = map;
	while (*tmp)
	{
		(*tmp)[0] = '1';
		(*tmp)[map_data->cols - 1] = '1';
		tmp++;
	}
	ft_memset(*map, '1', map_data->cols);
	ft_memset(*(map + map_data->rows - 1), '1', map_data->cols);
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

char	**file_to_char(int fd, char ***file)
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
	return (*file);
}

int	get_wall_texture(t_data *data, char **line)
{
	char	**path;

	if (!ft_strncmp(*line, "NO ", 3))
		path = &(data->mlx.wall_sprite.path_n);
	else if (!ft_strncmp(*line, "SO ", 3))
		path = &(data->mlx.wall_sprite.path_s);
	else if (!ft_strncmp(*line, "WE ", 3))
		path = &(data->mlx.wall_sprite.path_w);
	else if (!ft_strncmp(*line, "EA ", 3))
		path = &(data->mlx.wall_sprite.path_e);
	else
		return (-1);
	if (*path)
		return (-1);
	*line += 3;
	while (**line == ' ' || **line == '\t')
		(*line)++;
	*path = ft_strdup(*line);
	return (0);
}

int	get_background_color(t_data *data, char **line)
{
	t_color	*color;

	if (!ft_strncmp(*line, "F ", 2))
		color = &data->mlx.wall_sprite.floor_color;
	else if (!ft_strncmp(*line, "C ", 2))
		color = &data->mlx.wall_sprite.ceiling_color;
	else
		return (-1);
	if (color->a)
		return (-1);
	*line += 2;
	while (**line == ' ' || **line == '\t')
		(*line)++;
	color->r = ft_atoi(*line);
	while (**line != ',' && **line)
		(*line)++;
	(*line)++;
	color->g = ft_atoi(*line);
	while (**line != ',' && **line)
		(*line)++;
	(*line)++;
	color->b = ft_atoi(*line);
	color->a = 255;
	return (0);
}

int	check_empty_texture(t_sprite *sprite)
{
	if (!sprite->path_n || !sprite->path_s
		|| !sprite->path_w || !sprite->path_e
		|| !sprite->ceiling_color.a || !sprite->floor_color.a)
		return (-1);
	return (0);
}

int	parse_texture(char **file, t_data *data)
{
	char	**tmp;
	char	*line;

	tmp = file;
	while (*tmp)
	{
		line = *tmp;
		if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3)
			|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
		{
			if (get_wall_texture(data, &line) == -1)
				return (-1);
		}
		else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		{
			if (get_background_color(data, &line) == -1)
				return (-1);
		}
		tmp++;
	}
	if (check_empty_texture(&data->mlx.wall_sprite) == -1)
		return (-1);
	return (0);
}

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
	player->pos = (t_vec2){j, i};
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

void	flood_fill(char **map, size_t i, size_t j)
{
	if (!i || !j || i == ft_ctablen(map) - 1 || j == ft_strlen(*map) - 1)
		return ;
	if ((map[i - 1][j] == '0' || map[i - 1][j] == '1' || map[i - 1][j] == '2')
	&& (map[i + 1][j] == '0' || map[i + 1][j] == '1' || map[i + 1][j] == '2')
	&& (map[i][j - 1] == '0' || map[i][j - 1] == '1' || map[i][j - 1] == '2')
	&& (map[i][j + 1] == '0' || map[i][j + 1] == '1' || map[i][j + 1] == '2'))
		map[i][j] = '2';
	if (map[i - 1][j] == '0')
		flood_fill(map, i - 1, j);
	if (map[i + 1][j] == '0')
		flood_fill(map, i + 1, j);
	if (map[i][j - 1] == '0')
		flood_fill(map, i, j - 1);
	if (map[i][j + 1] == '0')
		flood_fill(map, i, j + 1);
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
				flood_fill(map, i, j);
			j++;
		}
		i++;
	}
	if (reset_map(map) == -1)
		return (-1);
	return (0);
}

int	parsing(int ac, char **av, t_data *data)
{
	int		fd;
	char	**file;

	file = NULL;
	if (ac != 2)
		return (print_error("Wrong number of arguments\n"));
	if (ft_strlen(av[1]) < 4 && ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
		return (print_error("Wrong file extension\n"));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (print_error("Can't open file\n"));
	file = file_to_char(fd, &file);
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
	// print_parsing(data);
	return (0);
}
