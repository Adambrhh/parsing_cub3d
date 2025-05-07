/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:02:59 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/06 11:42:13 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_map_line(char *line)
{
	int i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	while (line[i])
	{
		if (ft_strchr("01NSEW", line[i]))
			return true;
		if (!ft_strchr(" 01NSEW", line[i]))
			return false;
		i++;
	}
	return false;
}

void	buffer_map_line(t_mapbuffer **buffer, char *line)
{
	t_mapbuffer	*new;
	t_mapbuffer	*current;
	char		*trimmed;

	trimmed = ft_strtrim(line, " \t\n\r");
	if (!trimmed || !*trimmed)
	{
		free(trimmed);
		return;
	}
	new = malloc(sizeof(t_mapbuffer));
	if (!new)
		return ;
	new->line = ft_strtrim(line, " \t\n\r");
	new->next = NULL;
	if (!*buffer)
		*buffer = new;
	else
	{
		current = *buffer;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	free(trimmed);
}

void	parse_map(char *line, int fd, t_data_map *map)
{
	buffer_map_line(&map->map, line);
	free(line);
	while ((line = get_next_line(fd)) != NULL)
	{
		buffer_map_line(&map->map, line);
		free(line);
	}
}
