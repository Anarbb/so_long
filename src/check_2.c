/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:54:14 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/26 15:07:05 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	check_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->matrix[i])
	{
		j = 0;
		while (game->map->matrix[i][j])
		{
			if (ft_strchr("01PCEG", game->map->matrix[i][j]) == 0
				&& game->map->matrix[i][j] != '\n')
				exit_game(game, "Error : Invalid character in map\n", 1);
			j++;
		}
		i++;
	}
}

void	sanity_checks(t_game *game)
{
	check_chars(game);
	if (game->enemy->count > 1)
		exit_game(game, "Error : Map has more than one enemy\n", 1);
	if (game->player->count > 1)
		exit_game(game, "Error : Map has more than one player\n", 1);
	if (game->player->count == 0)
		exit_game(game, "Error : Map has no player\n", 1);
	if (game->map->exits == 0)
		exit_game(game, "Error : Map has no exits or coins\n", 1);
	if (game->map->exits > 1)
		exit_game(game, "Error : Map has more than one exit\n", 1);
	if (game->map->coins == 0)
		exit_game(game, "Error : Map has no coins\n", 1);
}
