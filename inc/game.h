/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:46:38 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/17 16:38:37 by aarbaoui         ###   ########.fr       */
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
# define PLAYER "./sprites/Pac-Man/pac_open_right.xpm"
# define ENEMY "./sprites/Ghosts/B/ghost_down1.xpm"
# define EXIT "./sprites/Other/Portal/portal.xpm"
# define ZERO "./sprites/Other/Fonts/0.xpm"
# define ONE "./sprites/Other/Fonts/1.xpm"
# define TWO "./sprites/Other/Fonts/2.xpm"
# define THREE "./sprites/Other/Fonts/3.xpm"
# define FOUR "./sprites/Other/Fonts/4.xpm"
# define FIVE "./sprites/Other/Fonts/5.xpm"
# define SIX "./sprites/Other/Fonts/6.xpm"
# define SEVEN "./sprites/Other/Fonts/7.xpm"
# define EIGHT "./sprites/Other/Fonts/8.xpm"
# define NINE "./sprites/Other/Fonts/9.xpm"


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
	int		coins;
	int		coins_counter;
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
	int		go_up;
	int		go_down;
	int		go_left;
	int		go_right;
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
	int			moves;
	
}				t_game;
// map.c
int		init_map(t_game *game, char *map_path);
void	draw_map(t_game *game);
void	draw_xpm(t_game **game, char *block, int x, int y);
int		create_matrix(char *map_path, t_game *game);
int		get_map_size(char *map_path, t_game *game);
// player.c
void	init_player(t_game *game);
void	get_players_cords(t_game *game);
int		move_player(int keynum, t_game *game);
void	check_legal(t_game *game);
// move.c
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
// misc.c
void	draw_score(t_game *game);
// check.c
void	check_map(t_game *game);
#endif