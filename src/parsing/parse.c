/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:10:51 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/09 02:28:25 by asuc             ###   ########.fr       */
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
	// set_border(*grid, map);
}

char	**file_to_char(int fd, char ***file)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (*line != '\n')
			ft_extand_tab(file, ft_substr(line, 0, ft_strlen(line) - 1));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (*file);
}

int	parse_texture(char **file, t_data *data)
{
	char	**tmp;
	char	*line;

	tmp = file;
	while (*tmp)
	{
		line = *tmp;
		if (!ft_strncmp(line, "NO ", 3))
		{
			if (data->mlx.wall_sprite.path_n)
				return (-1);
			line += 3;
			while (*line == ' ' || *line == '\t')
				line++;
			data->mlx.wall_sprite.path_n = ft_strdup(line);
		}
		else if (!ft_strncmp(line, "SO ", 3))
		{
			if (data->mlx.wall_sprite.path_s)
				return (-1);
			line += 3;
			while (*line == ' ' || *line == '\t')
				line++;
			data->mlx.wall_sprite.path_s = ft_strdup(line);
		}
		else if (!ft_strncmp(line, "WE ", 3))
		{
			if (data->mlx.wall_sprite.path_w)
				return (-1);
			line += 3;
			while (*line == ' ' || *line == '\t')
				line++;
			data->mlx.wall_sprite.path_w = ft_strdup(line);
		}
		else if (!ft_strncmp(line, "EA ", 3))
		{
			if (data->mlx.wall_sprite.path_e)
				return (-1);
			line += 3;
			while (*line == ' ' || *line == '\t')
				line++;
			data->mlx.wall_sprite.path_e = ft_strdup(line);
		}
		else if (!ft_strncmp(line, "F ", 2))
		{
			if (data->mlx.wall_sprite.color_floor.a)
				return (-1);
			line += 2;
			while (*line == ' ' || *line == '\t')
				line++;
			data->mlx.wall_sprite.color_floor.r = ft_atoi(line);
			while (*line != ',' && *line)
				line++;
			line++;
			data->mlx.wall_sprite.color_floor.g = ft_atoi(line);
			while (*line != ',' && *line)
				line++;
			line++;
			data->mlx.wall_sprite.color_floor.b = ft_atoi(line);
			data->mlx.wall_sprite.color_floor.a = 255;
		}
		else if (!ft_strncmp(line, "C ", 2))
		{
			if (data->mlx.wall_sprite.color_ceiling.a)
				return (-1);
			line += 2;
			while (*line == ' ' || *line == '\t')
				line++;
			data->mlx.wall_sprite.color_ceiling.r = ft_atoi(line);
			while (*line != ',' && *line)
				line++;
			line++;
			data->mlx.wall_sprite.color_ceiling.g = ft_atoi(line);
			while (*line != ',' && *line)
				line++;
			line++;
			data->mlx.wall_sprite.color_ceiling.b = ft_atoi(line);
			data->mlx.wall_sprite.color_ceiling.a = 255;
		}
		tmp++;
	}
	if (!data->mlx.wall_sprite.path_n || !data->mlx.wall_sprite.path_s
		|| !data->mlx.wall_sprite.path_w || !data->mlx.wall_sprite.path_e
		|| !data->mlx.wall_sprite.color_ceiling.a
		|| !data->mlx.wall_sprite.color_floor.a)
		return (-1);
	return (0);
}

void	print_parsing(t_data *data)
{
	char	**tmp;

	printf("NO: %s\n", data->mlx.wall_sprite.path_n);
	printf("SO: %s\n", data->mlx.wall_sprite.path_s);
	printf("WE: %s\n", data->mlx.wall_sprite.path_w);
	printf("EA: %s\n", data->mlx.wall_sprite.path_e);
	printf("F: %d, %d, %d\n", data->mlx.wall_sprite.color_floor.r,
		data->mlx.wall_sprite.color_floor.g,
		data->mlx.wall_sprite.color_floor.b);
	printf("C: %d, %d, %d\n", data->mlx.wall_sprite.color_ceiling.r,
		data->mlx.wall_sprite.color_ceiling.g,
		data->mlx.wall_sprite.color_ceiling.b);
	printf("Map:\n");
	tmp = data->map.map;
	while (*tmp)
	{
		printf("%s\n", *tmp);
		tmp++;
	}
}

int	check_map(char **map, t_map *map_data)
{
	(void)map;
	(void)map_data;
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
	format_map(&data->map.map, &data->map);
	if (check_map(data->map.map, &data->map) == -1)
		return (-1);
	return (0);
}

int	parsing(int ac, char **av, t_data *data)
{
	int		fd;
	char	**file;

	file = NULL;
	if (ac != 2)
	{
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nCan't open file\n", 2);
		return (-1);
	}
	file = file_to_char(fd, &file);
	if (parse_texture(file, data) == -1)
	{
		ft_putstr_fd("Error\nCan't parse texture\n", 2);
		return (-1);
	}
	if (parse_map(file, data) == -1)
	{
		ft_putstr_fd("Error\nCan't parse map\n", 2);
		return (-1);
	}
	print_parsing(data);
	return (0);
}
