/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parsing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:02:04 by bgoron            #+#    #+#             */
/*   Updated: 2024/06/15 16:25:07 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PARSING_H
# define _PARSING_H

# include "../../include/include.h"

int		parse_texture(char **file, t_data *data);
char	**parse_file(char *file, t_map *map);
int		parse_map(char **file, t_data *data);

void	file_to_char(int fd, char ***file);
void	extand_map(char **map, size_t max_len);
int		reset_map(char **map);

void	print_parsing(t_data *data);

int		check_extension_file(char *file, char *extension);
int		check_map_character(char **map);
int		check_player(char **map, t_player *player);
int		check_unclosed_map(char **map);
int		check_backgroud_color(char **line);
int		check_texture(t_sprite *sprite);

size_t	ft_ctablen(char **tab);

#endif