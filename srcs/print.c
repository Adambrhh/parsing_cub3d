#include "cub3D.h"

void	print_data_map(t_data_map *data)
{
	t_mapbuffer *current;
	int			row_count;

	if (!data)
	{
		printf("Error: NULL data pointer\n");
		return;
	}
	printf("=== Data Map ===\n");
	printf("Initialized: %s\n", data->inited ? "true" : "false");
	// Textures
	printf("\nTextures:\n");
	if (data->textures.north)
		printf("North: %s\n", data->textures.north);
	else
		printf("North: (null)\n");
	if (data->textures.south)
		printf("South: %s\n", data->textures.south);
	else
		printf("South: (null)\n");
	if (data->textures.west)
		printf("West: %s\n", data->textures.west);
	else
		printf("West: (null)\n");
	if (data->textures.east)
		printf("East: %s\n", data->textures.east);
	else
		printf("East: (null)\n");
	// Floor Colors
	printf("\nFloor Colors:\n");
	printf("R: %d, G: %d, B: %d\n", 
		data->floor_colors.R, 
		data->floor_colors.G, 
		data->floor_colors.B);
	// Ceiling Colors
	printf("\nCeiling Colors:\n");
	printf("R: %d, G: %d, B: %d\n", 
		data->ceiling_colors.R, 
		data->ceiling_colors.G, 
		data->ceiling_colors.B);
	// Color values (unsigned int)
	printf("\nColor Values:\n");
	printf("Floor: %u\n", data->floor);
	printf("Ceiling: %u\n", data->ceiling);
	// Map
	printf("\nMap:\n");
	if (data->map)
	{
		current = data->map;
		row_count = 0;
		while (current)
		{
			printf("%s\n", current->line);
			current = current->next;
			row_count++;
		}
		printf("Total rows: %d\n", row_count);
	}
	else
	{
		printf("(null)\n");
	}
}