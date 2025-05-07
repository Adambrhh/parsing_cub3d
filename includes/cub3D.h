/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarahho <abarahho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:29:31 by abarahho          #+#    #+#             */
/*   Updated: 2025/05/07 11:09:48 by abarahho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include "parsing.h"

# define WIDTH 320
# define HEIGHT 200
 
typedef	struct s_player
{
	float	x;
	float	y;
	float	look_angle;
}			t_player;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef	struct s_map
{
	int			width;
	int			height;
	int			*map;
}			t_map;

typedef struct s_cub
{
	void			*mlx;
	void			*mlx_win;
	t_img			img;
	t_map			map;
}			t_cub;


int			init_screen(t_cub *cub);
void		destroy_screen(t_cub *cub);
t_data_map	parsing(char *str);
void		free_data_map(t_data_map *data);


#endif