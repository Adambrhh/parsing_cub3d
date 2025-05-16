/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:50:18 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/16 14:25:18 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3D.h"

typedef enum e_error
{
	TEXT_FAIL,
	COL_FAIL,
	LINE_FAIL,
	PLAYER_FOUND,
	INCOR_CHAR,
	EMPTY_LINE,
	INCOR_MAP,
	EMPTY_FILE
}				t_error;
typedef struct s_mapbuffer
{
	char				*mapline;
	struct s_mapbuffer	*next;
}				t_mapbuffer;


void	free_array(char **str);
int		array_len(char **array);
bool	is_valid_filename(char *str);
bool	parse_texture(char *line, t_textures *textures);
bool	is_texture_line(char *line);
bool	parse_color(char *line, t_data_map *map);
bool	is_color_line(char *line);
bool	parse_map(char *line, int fd, t_data_map *map);
void	error_handling(t_error CODE, char *line);
bool	flood_fill(t_data_map *data_map);
void	free_remaining_lines(int fd);

#endif