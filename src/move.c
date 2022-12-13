/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:52:44 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/13 16:42:22 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	move_up(t_game *game)
{
	if (game->player->go_up == 0)
		return ;
	game->map->matrix[(game->player->y)][(game->player->x)] = '0';
	game->map->matrix[(game->player->y - 1)][(game->player->x)] = 'P';
	game->player->y -= 1;
	ft_putstr_fd("up" , 1);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	draw_map(game);
}

void	move_down(t_game *game)
{
	if (game->player->go_down == 0)
		return ;
	game->map->matrix[(game->player->y)][(game->player->x)] = '0';
	game->map->matrix[(game->player->y + 1)][(game->player->x)] = 'P';
	game->player->y += 1;
	ft_putstr_fd("down" , 1);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	draw_map(game);
}

void	move_left(t_game *game)
{
	if (!game->player->go_left)
		return ;
	game->map->matrix[(game->player->y)][(game->player->x) ] = '0';
	game->map->matrix[(game->player->y)][(game->player->x - 1)] = 'P';
	game->player->x -= 1;
	ft_putstr_fd("left",1 );
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	draw_map(game);
}

void	move_right(t_game *game)
{
	if (game->player->go_right == 0)
		return ;
	game->map->matrix[(game->player->y)][(game->player->x)] = '0';
	game->map->matrix[(game->player->y)][(game->player->x + 1)] = 'P';
	game->player->x += 1;
	ft_putstr_fd("right", 1);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	draw_map(game);
}