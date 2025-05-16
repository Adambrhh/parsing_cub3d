/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:52:01 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/16 14:24:44 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	is_header(t_data_map *data_map)
{
	if (data_map->floor && data_map->ceiling && data_map->textures.north
		&& data_map->textures.south && data_map->textures.west
		&& data_map->textures.east)
		return (true);
	return (false);
}

int	check_file(char *str)
{
	int			fd;

	if (!is_valid_filename(str))
	{
		(ft_dprintf(2, "Error: Invalid file extension %s\n", str));
		return (-1);
	}
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		(ft_dprintf(2, "Error: Could not open this file %s\n, str"));
		return (-1);
	}
	return (fd);
}

static void	parse_textures_and_colors(int fd, char **line, t_data_map *data_map)
{
	while (*line != NULL)
	{
		if (is_texture_line(*line))
		{
			if (!parse_texture(*line, &data_map->textures))
				return (error_handling(TEXT_FAIL, *line), free(*line));
		}
		else if (is_color_line(*line))
		{
			if (!parse_color(*line, data_map))
				return (error_handling(COL_FAIL, *line), free(*line));
		}
		else if (*line[0] == '\n')
		{
			free(*line);
			*line = get_next_line(fd);
			continue ;
		}
		else if ((*line[0] == '1' || *line[0] == ' ') && is_header(data_map))
			break ;
		else
			return (error_handling(LINE_FAIL, *line), free(*line));
		free(*line);
		*line = get_next_line(fd);
	}
}

t_data_map	parsing(char *str)
{
	t_data_map	data_map;
	int			fd;
	char		*line;

	ft_bzero(&data_map, sizeof(t_data_map));
	line = NULL;
	fd = check_file(str);
	if (fd < 0)
		return (data_map);
	line = get_next_line(fd);
	if (!line)
	{
		error_handling(EMPTY_FILE, NULL);
		return (close(fd), data_map);
	}
	parse_textures_and_colors(fd, &line, &data_map);
	if (!is_header(&data_map))
		return (free_remaining_lines(fd), close(fd), data_map);
	if (!parse_map(line, fd, &data_map))
		return (free_remaining_lines(fd), close(fd), data_map);
	if (!flood_fill(&data_map))
		return (close(fd), data_map);
	close(fd);
	data_map.inited = true;
	return (data_map);
}
