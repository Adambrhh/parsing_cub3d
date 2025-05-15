/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:31:16 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/15 18:26:11 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	player_angle(char pos, float *look_angle)
{
	if (pos == 'N')
		*look_angle = 3.14159265358979323846 / 2;
	else if (pos == 'S')
		*look_angle = 3 * 3.14159265358979323846 / 2;
	else if (pos == 'E')
		*look_angle = 0;
	else if (pos == 'W')
		*look_angle = 3.14159265358979323846;
}

static void	find_player(t_data_map *data_map)
{
	int	x;
	int	y;

	y = 0;
	while (data_map->map.map[y])
	{
		x = 0;
		while (data_map->map.map[y][x])
		{
			if (data_map->map.map[y][x] == 'N' || data_map->map.map[y][x] == 'S'
				|| data_map->map.map[y][x] == 'W' || data_map->map.map[y][x] == 'E')
			{
				data_map->player.x = (float)x;
				data_map->player.y = (float)y;
				player_angle(data_map->map.map[y][x], &data_map->player.look_angle);
				return ;
			}
			x++;
		}
		y++;
	}
}

static int	flood_fill_recursive(t_data_map *data_map, int x, int y)
{
	if (y < 0 || y >= data_map->map.height || x < 0 || x >= (int)ft_strlen(data_map->map.map[y]))
		return (0);
	if (data_map->map.map[y][x] == '1' || data_map->map.map[y][x] == '2')
		return (1);
	data_map->map.map[y][x] = '2';
	if (!flood_fill_recursive(data_map, x, y - 1))
		return (0);
	if (!flood_fill_recursive(data_map, x, y + 1))
		return (0);
	if (!flood_fill_recursive(data_map, x - 1, y))
		return (0);
	if (!flood_fill_recursive(data_map, x + 1, y))
		return (0);
	return (1);
}

int	flood_fill(t_data_map *data_map)
{
    find_player(data_map);
    if (data_map->player.x == -1 || data_map->player.y == -1)
        return (0);
    return (flood_fill_recursive(data_map, data_map->player.x,
            data_map->player.y));
}
