/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:46:38 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/06 20:58:20 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# ifdef __APPLE__
#  include "../mlx/mlx.h"
# else
#  include "../mlx_linux/mlx.h"
# endif
# include "get_next_line.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define SPRITE_SIZE 32
# define WALL "./sprites/Other/Walls/wall.xpm"
# define EMPTY "./sprites/Other/Walls/black.xpm"
# define COLLECTIBLE "./sprites/Other/Pacdots/pacdot_food.xpm"
# define PLAYER "./sprites/Pac-Man/pac_open_left.xpm"
# define EXIT "./sprites/Other/Portal/portal.xpm"

typedef struct s_map
{
	int		fd;
	char	**map;
	char	*line;
	int		width;
	int		height;
	size_t	counter;
	int		x;
	int		y;
	int		garbage;
	void	*img_ptr;
	void	*img_data;
	int		bpp;
	int		size_l;
	int		endian;
	int 	img_width;
	int 	img_height;
}				t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	
}				t_game;

void	draw_map(t_map *map, t_game *game);
int		init_map(char *map_path, t_map *map);
#endif