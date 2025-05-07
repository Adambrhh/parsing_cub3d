/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:52:01 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/07 11:06:38 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_file(char *str)
{
	int			fd;

	if (!is_valid_filename(str))
	{
		(ft_dprintf(2, "Error: Invalid file extension\n"));
		return (-1);
	}
	if ((fd = open(str, O_RDONLY)) < 0)
	{
		(ft_dprintf(2, "Error: Could not open this file\n"));
		return (-1);
	}
	return (fd);
} 

t_data_map	parsing(char *str)
{
	t_data_map	map;
	int			fd;
	char		*line;

	ft_bzero(&map, sizeof(t_data_map));
	if ((fd = check_file(str)) == -1)
		return (map);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (is_texture_line(line))
			parse_texture(line, &map.textures);
		else if (is_color_line(line))
			parse_color(line, &map);
		else if (is_map_line(line))
		{
			parse_map(line, fd, &map);
			break;
		}
		free(line);
	}
	if (map.map)
	{
		while ((line = get_next_line(fd)) != NULL)
		{
			buffer_map_line(&map.map, line);
			free(line);
		}
	}
	else
	{
		while ((line = get_next_line(fd)) != NULL)
			free(line);
	}
	close(fd);
	map.inited = true;
	return (map);
}
