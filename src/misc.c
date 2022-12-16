/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:13:45 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/15 17:55:15 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	draw_score(t_game *game)
{
	int		x;
	int		y;
	char	*moves;

	moves = ft_itoa(game->moves);
	x = (game->map->x / 2) * SPRITE_SIZE;
	y = game->map->y * SPRITE_SIZE + 32;
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, x + 64, y, 0xFFFFFF, moves);
	free(moves);
}
