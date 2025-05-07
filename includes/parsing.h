/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 10:50:18 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/07 11:52:52 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_mapbuffer
{
	char				*line;
	struct s_mapbuffer	*next;
}				t_mapbuffer;

typedef enum	e_error_msg
{
	ERROR_NO_T,
	ERROR_SO_T,
	ERROR_WE_T,
	ERROR_EA_T,
	ERROR_TEX_PATH,
	ERROR_F_COLOR,
	ERROR_C_COLOR,
	ERROR_ELEMENT_ORDER,
	ERROR_MAP_PLAYER,
	ERROR_MAP_CHAR,
	ERROR_MAP_EMPTY_LINE,
	ERROR_FILE_OPEN,
	ERROR_FILE_EXT,
}				t_error_msgp;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}			t_textures;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
}			t_colors;

typedef struct	s_data_map
{
	t_textures		textures;
	t_colors		floor_color;
	t_colors		ceiling_color;
	t_mapbuffer		*map;
	unsigned int	floor;
	unsigned int	ceiling;
	bool			inited;
}			t_data_map;

void	print_data_map(t_data_map *data);

void	free_array(char **str);
int		array_len(char **array);

bool	is_valid_filename(char *str);

void	parse_texture(char *line, t_textures *textures);
bool	is_texture_line(char *line);

void	parse_color(char *line, t_data_map *map);
bool	is_color_line(char *line);

void	parse_map(char *line, int fd, t_data_map *map);
bool	is_map_line(char *line);

void	buffer_map_line(t_mapbuffer **buffer, char *line);

#endif