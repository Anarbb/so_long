/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:46:38 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/09 19:22:12 by aarbaoui         ###   ########.fr       */
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
# define ENEMY "./sprites/Ghosts/B/ghost_up1.xpm"
# define EXIT "./sprites/Other/Portal/portal.xpm"

typedef struct s_map
{
	int		fd;
	char	**map;
	char	*line;
	void	*img_ptr;
	int		img_width;
	int		img_height;
	int		width;
	int		height;
	int		counter;
	int		x;
	int		y;
}				t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
}				t_game;

typedef struct s_player
{
	int		x;
	int		y;
	int		score;
	int		lives;
	char	**sprites;
}				t_player;

typedef struct s_enemy
{
	int		x;
	int		y;
	char	**sprites;
}				t_enemy;

void	draw_map(t_map *map, t_game *game);
int		init_map(char *map_path, t_map *map);
int		create_matrix(char *map_path, t_map *map);
#endif