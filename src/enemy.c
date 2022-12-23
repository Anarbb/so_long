/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:40:35 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/23 12:44:22 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_enemy(t_game *game)
{
	game->enemy = ft_calloc(1, sizeof(t_enemy));
	get_enemy_cords(game);
	game->enemy->img = mlx_xpm_file_to_image(game->mlx_ptr,
			ft_strjoin(ENEMY, "left1"),
			&game->map->img_width, &game->map->img_height);
}

void	get_enemy_cords(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height / SS)
	{
		j = 0;
		while (j < game->map->width / SS)
		{
			if (game->map->matrix[i][j] == 'G')
			{
				game->enemy->x = j;
				game->enemy->y = i;
				game->enemy->count++;
			}
			j++;
		}
		i++;
	}
}

static int	check_player(t_game *game)
{
	if (game->win_ptr)
	{
		if (game->map->matrix[game->enemy->y][game->enemy->x - 1] == 'P'
			|| game->map->matrix[game->enemy->y][game->enemy->x + 1] == 'P'
			|| game->map->matrix[game->enemy->y - 1][game->enemy->x] == 'P'
			|| game->map->matrix[game->enemy->y + 1][game->enemy->x] == 'P')
			exit_game(game, "You lose!\n", 0);
	}
	return (0);
}

static void	move(t_game *game, int left, int right)
{
	if (left)
	{
		animate_enemy(game, 1);
		check_player(game);
		if (game->map->matrix[game->enemy->y][game->enemy->x + 1] == 'C')
			game->map->coins_counter++;
		game->map->matrix[game->enemy->y][game->enemy->x + 1] = 'G';
		game->map->matrix[game->enemy->y][game->enemy->x] = '0';
		game->enemy->x++;
	}
	else if (right)
	{
		animate_enemy(game, 0);
		check_player(game);
		if (game->map->matrix[game->enemy->y][game->enemy->x - 1] == 'C')
			game->map->coins_counter++;
		game->map->matrix[game->enemy->y][game->enemy->x - 1] = 'G';
		game->map->matrix[game->enemy->y][game->enemy->x] = '0';
		game->enemy->x--;
	}
}

void	move_enemy(t_game *game)
{
	if (game->enemy->mov_right && game->map->matrix[game->enemy->y]
		[game->enemy->x + 1] != '1'
		&& game->map->matrix[game->enemy->y][game->enemy->x + 1] != 'E')
		move(game, 1, 0);
	else
	{
		check_player(game);
		game->enemy->mov_right = 0;
		game->enemy->mov_left = 1;
	}
	if (game->enemy->mov_left && game->map->matrix[game->enemy->y]
		[game->enemy->x - 1] != '1'
		&& game->map->matrix[game->enemy->y][game->enemy->x - 1] != 'E')
		move(game, 0, 1);
	else
	{
		check_player(game);
		game->enemy->mov_right = 1;
		game->enemy->mov_left = 0;
	}	
}
