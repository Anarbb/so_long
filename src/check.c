/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:42:26 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/17 16:38:26 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	check_rect(t_game *game)
{
	int	i;
	int	err;

	err = 0;
	i = 0;
	while (i < game->map->height / SPRITE_SIZE)
	{
		if (game->map->matrix[i][0] != '1' || game->map->matrix[i][game->map->width / SPRITE_SIZE - 1] != '1')
			err++;
		i++;
	}
	i = 0;
	while (i < game->map->width / SPRITE_SIZE)
	{
		if (game->map->matrix[0][i] != '1' || game->map->matrix[game->map->height / SPRITE_SIZE - 1][i] != '1')
			err++;
		i++;
	}
	if (err > 0)
		{
			ft_putstr_fd("Error : Map is not closed\n", 1);
			exit(0);
		}
}



void	check_map(t_game *game)
{
	check_rect(game);
	
}