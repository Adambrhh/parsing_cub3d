/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:02:59 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/15 17:03:05 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	is_map_line(char *line, bool *player)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == '\0')
		return (error_handling(EMPTY_LINE, NULL), false);
	while (line[i])
	{
		if (ft_strchr("NSEW", line[i]))
		{
			if (player && *player)
				return (error_handling(PLAYER_FOUND, line), false);
			if (player)
				*player = true;
		}
		if (!ft_strchr(" 01NSEW\n", line[i]))
			return (error_handling(INCOR_CHAR, line), false);
		i++;
	}
	return (true);
}

void	buffer_map_line(t_mapbuffer **mapline, char *line)
{
	t_mapbuffer	*new;
	t_mapbuffer	*current;
	char		*trimmed;

	trimmed = ft_strtrim(line, "\n");
	new = malloc(sizeof(t_mapbuffer));
	if (!new)
		return ;
	new->mapline = trimmed;
	new->next = NULL;
	if (!*mapline)
		*mapline = new;
	else
	{
		current = *mapline;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

static void	copy_mapbuffer_to_array(t_data_map *data_map, t_mapbuffer **mapline)
{
	t_mapbuffer	*current;
	t_mapbuffer	*next;
	int			i;
	int			j;

	i = 0;
	current = *mapline;
	data_map->map.map = malloc(sizeof(char *) * (data_map->map.height + 1));
	while (current != NULL)
	{
		data_map->map.map[i] = ft_strdup(current->mapline);
		j = 0;
		while (data_map->map.map[i][j])
		{
			if (data_map->map.map[i][j] == ' ')
				data_map->map.map[i][j] = '0';
			j++;
		}
		i++;
		free(current->mapline);
		next = current->next;
		free(current);
		current = next;
	}
	data_map->map.map[i] = NULL;
}

void	parse_map(char *line, int fd, t_data_map *data_map)
{
	bool			player;
	t_mapbuffer		*mapline;
	int				line_length;

	mapline = NULL;
	player = false;
	while (line)
	{
		if (!is_map_line(line, &player))
		{
			free(line);
			return ;
		}
		buffer_map_line(&mapline, line);
		line_length = (int)(ft_strlen(line) - 1);
		if (data_map->map.width < line_length)
			data_map->map.width = line_length;
		free(line);
		line = get_next_line(fd);
	}
	data_map->map.height = ft_lstsize((t_list *)mapline);
	copy_mapbuffer_to_array(data_map, &mapline);
}
