/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:28:00 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/15 15:36:05 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_data_map(t_data_map *data)
{
	int	i;

	i = 0;
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
	if (data->map.map)
	{
		free_array(data->map.map);
	}
}

int	main(int ac, char **av)
{
	t_data_map	data_map;

	data_map.inited = false;
	if (ac != 2)
		return(ft_dprintf(2, "./cub3D [*.cub]\n"));
	data_map = parsing(av[1]);
	print_data_map(&data_map);
	free_data_map(&data_map);
	return (0);
}