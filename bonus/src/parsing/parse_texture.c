/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:17:23 by bgoron            #+#    #+#             */
/*   Updated: 2024/07/01 11:59:49 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_parsing.h"

static int	get_wall_texture(t_data *data, char **line)
{
	char	**path;

	if (!ft_strncmp(*line, "NO ", 3))
		path = &(data->graphics.wall_sprite.path_n);
	else if (!ft_strncmp(*line, "SO ", 3))
		path = &(data->graphics.wall_sprite.path_s);
	else if (!ft_strncmp(*line, "EA ", 3))
		path = &(data->graphics.wall_sprite.path_e);
	else if (!ft_strncmp(*line, "WE ", 3))
		path = &(data->graphics.wall_sprite.path_w);
	else if (!ft_strncmp(*line, "FL ", 3))
		path = &(data->graphics.wall_sprite.path_floor);
	else if (!ft_strncmp(*line, "CE ", 3))
		path = &(data->graphics.wall_sprite.path_ceiling);
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

static int	is_valid_rgb(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (!ft_isdigit(tmp[i][0]))
			return (-1);
		if (ft_atoi(tmp[i]) < 0 || ft_atoi(tmp[i]) > 255)
			return (-1);
		i++;
	}
	return (0);
}

static int	get_background_color(t_data *data, char **line)
{
	t_color	*color;
	char	**tmp;

	if (!ft_strncmp(*line, "F ", 2))
		color = &data->graphics.wall_sprite.floor_color;
	else if (!ft_strncmp(*line, "C ", 2))
		color = &data->graphics.wall_sprite.ceiling_color;
	else
		return (-1);
	if (color->a)
		return (-1);
	*line += 2;
	tmp = ft_split(*line, ',');
	if (!tmp || ft_ctablen(tmp) != 3 || is_valid_rgb(tmp) == -1)
		return (ft_free_tab((void **)tmp));
	(*color).a = 255;
	(*color).r = ft_atoi(tmp[0]);
	(*color).g = ft_atoi(tmp[1]);
	(*color).b = ft_atoi(tmp[2]);
	ft_free_tab((void **)tmp);
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
			|| !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3)
			|| !ft_strncmp(line, "CE ", 3) || !ft_strncmp(line, "FL ", 3))
		{
			if (get_wall_texture(data, &line) == -1)
				return (ft_free_tab((void **)file));
		}
		else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		{
			if (get_background_color(data, &line) == -1)
				return (ft_free_tab((void **)file));
		}
		tmp++;
	}
	if (check_texture(&data->graphics.wall_sprite) == -1)
		return (ft_free_tab((void **)file));
	return (0);
}
