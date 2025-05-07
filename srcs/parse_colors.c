/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:02:59 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/07 11:10:06 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	check_color_format(char *line)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			comma++;
		if (!ft_strchr(" ,0123456789", line[i]))
			return (false);
		i++;
	}
	return (comma == 2);
}

bool	is_color_line(char *line)
{
	return (ft_strncmp(line, "F ", 2) == 0 ||
			ft_strncmp(line, "C ", 2) == 0);
}

static bool	valid_rgb_value(int value)
{
	return (value >= 0 && value <= 255);
}

static void	parse_rgb(char *str, t_colors *color)
{
	char	**rgb;
	int		values[3];
	int		i;

	rgb = ft_split(str, ',');
	if (!rgb || array_len(rgb) != 3)
	{
		free_array(rgb);
		return ;
	}
	i = 0;
	while (i < 3)
	{
		values[i] = ft_atoi(rgb[i]);
		if (!valid_rgb_value(values[i]))
		{
			free_array(rgb);
			return ;
		}
		i++;
	}
	color->R = values[0];
	color->G = values[1];
	color->B = values[2];
	free_array(rgb);
}

static unsigned int	convert_rgb_to_uint(t_colors color)
{
	return ((color.R << 16) | (color.G << 8) | color.B);
}

void parse_color(char *line, t_data_map *map)
{
	char    *color_str;

	color_str = ft_strtrim(line + 2, " \t");
	if (!color_str || !check_color_format(color_str + 2))
		return;
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		parse_rgb(color_str, &map->floor_colors);
		if (map->floor)
		{
			free_data_map(map);
			exit (1);
		}
		map->floor = convert_rgb_to_uint(map->floor_colors);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		parse_rgb(color_str, &map->ceiling_colors);
		if (map->ceiling)
		{
			free_data_map(map);
			exit (1);
		}
		map->ceiling = convert_rgb_to_uint(map->ceiling_colors);
	}
	free(color_str);
}
