/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:35:29 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/13 17:36:14 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_parsing.h"

int	check_texture(t_sprite *sprite)
{
	if (!sprite->path_n || !sprite->path_s
		|| !sprite->path_w || !sprite->path_e
		|| !sprite->ceiling_color.a || !sprite->floor_color.a)
		return (-1);
	else if (check_extension_file(sprite->path_n, ".png") == -1
		|| check_extension_file(sprite->path_s, ".png") == -1
		|| check_extension_file(sprite->path_w, ".png") == -1
		|| check_extension_file(sprite->path_e, ".png") == -1)
		return (-1);
	return (0);
}

int	check_backgroud_color(char **line)
{
	char	**tmp;

	*line += 2;
	tmp = ft_split(*line, ',');
	if (!tmp || ft_ctablen(tmp) != 3)
	{
		ft_free_tab((void **)tmp);
		return (-1);
	}
	ft_free_tab((void **)tmp);
	return (0);
}

int	check_extension_file(char *file, char *extension)
{
	int	file_len;
	int	ext_len;

	file_len = ft_strlen(file);
	ext_len = ft_strlen(extension);
	if (file_len < ext_len
		|| ft_strncmp(file + file_len - ext_len, extension, ext_len))
		return (-1);
	return (0);
}