/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:12:02 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/10 14:19:45 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"


int	calculate_coins(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	game->coins = 0;
	while (i < game->map->height / SPRITE_SIZE)
	{
		while (j < game->map->width / SPRITE_SIZE)
		{
			if (game->map->map[i][j] == 'C')
				game->coins++;
			j++;
		}
		j = 0;
		i++;
	}
	return (game->coins);
}