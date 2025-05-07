/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:28:00 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/07 11:09:38 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_data_map(t_data_map *data)
{
	t_mapbuffer *current;
	t_mapbuffer *next;

	if (!data)
		return ;
	if (data->textures.north)
	{
		free(data->textures.north);
		data->textures.north = NULL;
	}
	if (data->textures.south)
	{
		free(data->textures.south);
		data->textures.south = NULL;
	}
	if (data->textures.west)
	{
		free(data->textures.west);
		data->textures.west = NULL;
	}
	if (data->textures.east)
	{
		free(data->textures.east);
		data->textures.east = NULL;
	}
	current = data->map;
	while (current)
	{
		next = current->next;
		if (current->line)
		{
			free(current->line);
			current->line = NULL;
		}
		free(current);
		current = next;
	}
	data->map = NULL;
	data->floor = 0;
	data->ceiling = 0;
	data->inited = false;
}

int	main(int ac, char **av)
{
	t_data_map	map;

	map.inited = false;
	if (ac != 2)
		return(ft_dprintf(2, "./cub3D [*.cub]\n"));
	map = parsing(av[1]);
	print_data_map(&map);
	free_data_map(&map);
	return (0);
}