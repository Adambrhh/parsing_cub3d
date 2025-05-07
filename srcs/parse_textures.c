/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:02:59 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/06 11:33:11 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_texture_line(char *line)
{
	return (ft_strncmp(line, "NO ", 3) == 0 ||
			ft_strncmp(line, "SO ", 3) == 0 ||
			ft_strncmp(line, "WE ", 3) == 0 ||
			ft_strncmp(line, "EA ", 3) == 0);
}

void	parse_texture(char *line, t_textures *textures)
{
	char	*path;

	path = ft_strtrim(line + 3, " \t");
	if (!path)
		return ;
	if (ft_strncmp(line, "NO ", 3) == 0)
		textures->north = ft_strdup(line + 3);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		textures->south = ft_strdup(line + 3);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		textures->west = ft_strdup(line + 3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		textures->east = ft_strdup(line + 3);
	free(path);
}
