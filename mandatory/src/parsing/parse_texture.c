/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:17:23 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/15 15:42:16 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_parsing.h"

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
	if (color->a || check_backgroud_color(line) == -1)
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
				return (ft_free_tab((void **)file));
		}
		else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		{
			if (get_background_color(data, &line) == -1)
				return (ft_free_tab((void **)file));
		}
		tmp++;
	}
	if (check_texture(&data->mlx.wall_sprite) == -1)
		return (ft_free_tab((void **)file));
	return (0);
}
