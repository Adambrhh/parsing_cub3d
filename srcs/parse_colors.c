/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:02:59 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/15 15:45:19 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	is_color_line(char *line)
{
	return (ft_strncmp(line, "F ", 2) == 0
		|| ft_strncmp(line, "C ", 2) == 0);
}

unsigned int	convert_rgb_to_uint(unsigned int *rgb_array)
{
	return ((rgb_array[0] << 16) | (rgb_array[1] << 8) | rgb_array[2]);
}

static unsigned int	is_valid_number(char *str)
{
	int				i;
	unsigned int	num;

	i = 0;
	if (!str || str[0] == '\0')
		return (666);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (666);
		i++;
	}
	if (i > 3)
		return (666);
	num = ft_atoi(str);
	if (num > 255)
		return (666);
	return (num);
}

static bool	parse_rgb(char *str, unsigned int *rgb_array)
{
	char	**rgb;
	int		i;
	int		valid_number;	

	str = ft_strtrim(str, "\n");
	rgb = ft_split(str, ',');
	if (!rgb || array_len(rgb) != 3)
	{
		free_array(rgb);
		return (free(str), false);
	}
	i = 0;
	while (i < 3)
	{
		valid_number = is_valid_number(rgb[i]);
		if (valid_number == 666)
		{
			free_array(rgb);
			return (free(str), false);
		}
		rgb_array[i] = valid_number;
		i++;
	}
	free_array(rgb);
	return (free(str), true);
}

bool	parse_color(char *line, t_data_map *data_map)
{
	unsigned int	rgb[3];

	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (data_map->floor)
			return (false);
		if (!parse_rgb(line + 2, rgb))
			return (false);
		data_map->floor = convert_rgb_to_uint(rgb);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (data_map->ceiling)
			return (false);
		if (!parse_rgb(line + 2, rgb))
			return (false);
		data_map->ceiling = convert_rgb_to_uint(rgb);
	}
	else
		return (false);
	return (true);
}
