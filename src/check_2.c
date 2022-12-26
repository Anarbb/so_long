/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:54:14 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/26 14:55:09 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	many_checks(t_game *game)
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
	if (game->enemy->count > 1)
		exit_game(game, "Error : Map has more than one enemy\n", 1);
	if (game->player->count > 1)
		exit_game(game, "Error : Map has more than one player\n", 1);
	if (game->player->count == 0)
		exit_game(game, "Error : Map has no player\n", 1);
}