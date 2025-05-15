/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:29:31 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/15 18:11:36 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"

# define WIDTH 320
# define HEIGHT 200

typedef    struct s_player
{
	float	x;
	float	y;
	float	look_angle;
}	t_player;

typedef    struct s_map
{
	int		width;
	int		height;
	char	**map;
}	t_map;

typedef struct s_textures
{
	char    *north;
	char    *south;
	char    *west;
	char    *east;
}	t_textures;

typedef struct s_data_map
{
	t_textures		textures;
	unsigned int	floor;
	unsigned int	ceiling;
	t_player		player;
	t_map			map;
	bool			inited;
}	t_data_map;

t_data_map	parsing(char *str);

#endif