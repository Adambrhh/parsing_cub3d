/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:21:57 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/15 15:31:25 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_data_map(t_data_map *data)
{
	int	i;

	i = 0;
    if (!data)
    {
        printf("Error: NULL data pointer\n");
        return;
    }
    printf("=== Data Map ===\n");
    printf("Initialized: %s\n", data->inited ? "true" : "false");

    // Textures
    printf("\nTextures:\n");
    printf("North: %s\n", data->textures.north ? data->textures.north : "(null)");
    printf("South: %s\n", data->textures.south ? data->textures.south : "(null)");
    printf("West: %s\n", data->textures.west ? data->textures.west : "(null)");
    printf("East: %s\n", data->textures.east ? data->textures.east : "(null)");

    // Color values (unsigned int)
    printf("\nColor Values:\n");
    printf("Floor: %u\n", data->floor);
    printf("Ceiling: %u\n", data->ceiling);

    // Map
    printf("\nMap:\n");
    if (data->map.map)
    {
        while (data->map.map[i])
        {
            printf("%s\n", data->map.map[i]);
            i++;
        }
        printf("Height: %d\n", data->map.height);
		printf("Widtht: %d\n", data->map.width);
    }
    else
    {
        printf("(null)\n");
    }
}