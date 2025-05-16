/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:28:00 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/16 14:20:53 by abarahho         ###   ########.fr       */
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
		free(data->textures.north);
	if (data->textures.south)
		free(data->textures.south);
	if (data->textures.west)
		free(data->textures.west);
	if (data->textures.east)
		free(data->textures.east);
	if (data->map.map)
		free_array(data->map.map);
}

int	main(int ac, char **av)
{
	t_data_map	data_map;

	data_map.inited = false;
	if (ac != 2)
		return (ft_dprintf(2, "./cub3D [*.cub]\n"));
	data_map = parsing(av[1]);
	if (data_map.inited)
		printf("Valid map\n");
	free_data_map(&data_map);
	return (0);
}
