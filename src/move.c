/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:02:55 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/22 15:40:56 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	move_up(t_game *game)
{
	move_enemy(game);
	if (!game->player->go_up)
		return ;
	printf("p_x = %d, p_y = %d | e_x = %d, e_y = %d\n", game->player->x, game->player->y, game->enemy->x, game->enemy->y);
	if (game->player->x == game->enemy->x
		&& game->player->y == game->enemy->y)
	{
		ft_putstr_fd("You Lose", 1);
		exit(0);
	}
	game->player->img = game->player->img_up;
	if (game->map->matrix[(game->player->y - 1)][(game->player->x)] == 'E')
		if (!check_exit(game))
			return ;
	if (game->map->matrix[(game->player->y - 1)][(game->player->x)] == 'C')
		game->map->coins_counter += 1;
	game->map->matrix[(game->player->y)][(game->player->x)] = '0';
	game->map->matrix[(game->player->y - 1)][(game->player->x)] = 'P';
	game->player->y -= 1;
	game->moves++;
}

void	move_down(t_game *game)
{
	move_enemy(game);
	if (!game->player->go_down)
		return ;
	printf("p_x = %d, p_y = %d | e_x = %d, e_y = %d\n", game->player->x, game->player->y, game->enemy->x, game->enemy->y);
	if (game->player->x == game->enemy->x
		&& game->player->y == game->enemy->y)
	{
		ft_putstr_fd("You Lose", 1);
		exit(0);
	}
	game->player->img = game->player->img_down;
	if (game->map->matrix[(game->player->y + 1)][(game->player->x)] == 'E')
		if (!check_exit(game))
			return ;
	if (game->map->matrix[(game->player->y + 1)][(game->player->x)] == 'C')
		game->map->coins_counter += 1;
	game->map->matrix[(game->player->y)][(game->player->x)] = '0';
	game->map->matrix[(game->player->y + 1)][(game->player->x)] = 'P';
	game->player->y += 1;
	game->moves++;
}

void	move_left(t_game *game)
{
	move_enemy(game);
	if (!game->player->go_left)
		return ;
	printf("p_x = %d, p_y = %d | e_x = %d, e_y = %d\n", game->player->x, game->player->y, game->enemy->x, game->enemy->y);
	if (game->player->x - 1 == game->enemy->x
		&& game->player->y == game->enemy->y)
	{
		ft_putstr_fd("You Lose", 1);
		exit(0);
	}
	game->player->img = game->player->img_left;
	if (game->map->matrix[(game->player->y)][(game->player->x - 1)] == 'E')
		if (!check_exit(game))
			return ;
	if (game->map->matrix[(game->player->y)][(game->player->x - 1)] == 'C')
		game->map->coins_counter += 1;
	game->map->matrix[(game->player->y)][(game->player->x)] = '0';
	game->map->matrix[(game->player->y)][(game->player->x - 1)] = 'P';
	game->player->x -= 1;
	game->moves++;
}

void	move_right(t_game *game)
{
	move_enemy(game);
	if (!game->player->go_right)
		return ;
	printf("p_x = %d, p_y = %d | e_x = %d, e_y = %d\n", game->player->x, game->player->y, game->enemy->x, game->enemy->y);
	if (game->player->x == game->enemy->x
		&& game->player->y == game->enemy->y)
	{
		ft_putstr_fd("You Lose", 1);
		exit(0);
	}
	game->player->img = game->player->img_right;
	if (game->map->matrix[(game->player->y)][(game->player->x + 1)] == 'E')
		if (!check_exit(game))
			return ;
	if (game->map->matrix[(game->player->y)][(game->player->x + 1)] == 'C')
		game->map->coins_counter += 1;
	game->map->matrix[(game->player->y)][(game->player->x)] = '0';
	game->map->matrix[(game->player->y)][(game->player->x + 1)] = 'P';
	game->player->x += 1;
	game->moves++;
}
