/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:02:59 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/16 10:35:11 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_texture_line(char *line)
{
	return (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0);
}

static bool	check_texture_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_dprintf(2, "Error:\nCannot access texture file: %s\n", file);
		return (false);
	}
	close(fd);
	return (true);
}

static bool	set_texture(char **texture, char *line)
{
	if (*texture)
		return (false);
	*texture = ft_strtrim(line + 3, "\n");
	if (!*texture || !check_texture_file(*texture))
		return (false);
	return (true);
}

bool	parse_texture(char *line, t_textures *textures)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (set_texture(&textures->north, line));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (set_texture(&textures->south, line));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (set_texture(&textures->west, line));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (set_texture(&textures->east, line));
	return (false);
}
