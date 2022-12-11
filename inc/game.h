/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:46:38 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/11 21:41:59 by aarbaoui         ###   ########.fr       */
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
# define WALL "/Users/aarbaoui/Documents/1337/so_long/sprites/Other/Walls/wall.xpm"
# define EMPTY "/Users/aarbaoui/Documents/1337/so_long/sprites/Other/Walls/black.xpm"
# define COLLECTIBLE "/Users/aarbaoui/Documents/1337/so_long/sprites/Other/Pacdots/pacdot_food.xpm"
# define PLAYER "/Users/aarbaoui/Documents/1337/so_long/sprites/Pac-Man/pac_open_right.xpm"
# define ENEMY "/Users/aarbaoui/Documents/1337/so_long/sprites/Ghosts/B/ghost_down1.xpm"
# define EXIT "/Users/aarbaoui/Documents/1337/so_long/sprites/Other/Portal/portal.xpm"

typedef struct s_map
{
	int		fd;
	char	**matrix;
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

typedef struct s_player
{
	int		x;
	int		y;
	int		score;
	int		lives;
	void	*img;
	int		width;
	int		height;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_list	sprites;
}				t_player;

typedef struct s_enemy
{
	int		x;
	int		y;
	t_list	sprites;
}				t_enemy;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map;
	t_player	*player;
	t_enemy		*enemy;
	int			coins;
}				t_game;
// map.c
int		init_map(t_game *game, char *map_path);
void	draw_map(t_game *game);
void	draw_xpm(t_game **game, char *block);
int		create_matrix(char *map_path, t_game *game);
int		get_map_size(char *map_path, t_game *game);
// player.c
void	init_player(t_game *game);
void	get_players_cords(t_game *game);
int	move_player(int keynum, t_game *game);
#endif