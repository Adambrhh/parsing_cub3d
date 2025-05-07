/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:52:01 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/02 16:06:56 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	array_len(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while(array[i])
		i++;
	return (i);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

bool	is_valid_filename(char *str)
{
	int	n;

	n = ft_strlen(str);
	if (n < 5)
		return (false);
	str += n - 4;
	return (!ft_strcmp(str, ".cub"));
}

// void	free_data(t_data_map *data)
// {
	
// }

// int	validate_data(t_data_map *data)
// {
	
// }