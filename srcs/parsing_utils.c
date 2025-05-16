/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:52:01 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/16 11:37:49 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	array_len(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
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

void	free_remaining_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
}

void	error_handling(t_error CODE, char *line)
{
	if (CODE == TEXT_FAIL)
		ft_dprintf(2, "Error:\nProblem with the texture at line :%s\n", line);
	if (CODE == COL_FAIL)
		ft_dprintf(2, "Error:\nProblem with color at line :%s\n", line);
	if (CODE == LINE_FAIL)
		ft_dprintf(2, "Error:\nUnknow value at line :%s\n", line);
	if (CODE == PLAYER_FOUND)
		ft_dprintf(2, "Error:\nToo many players\n");
	if (CODE == INCOR_CHAR)
		ft_dprintf(2, "Error:\nIncorect char at line :%s\n", line);
	if (CODE == EMPTY_LINE)
		ft_dprintf(2, "Error:\nEmpty line in the map\n");
	if (CODE == INCOR_MAP)
		ft_dprintf(2, "Error:\nIncorect map\n");
	if (CODE == EMPTY_FILE)
		ft_dprintf(2, "Error:\nEmpty file\n");
}
