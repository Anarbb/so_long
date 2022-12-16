/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:42:26 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/16 16:32:01 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	check_rect(t_game *game)
{
	int	comp1;
	int	comp2;
	int	i;
	
	i = 0;
	while (game->map->matrix[i] && game->map->matrix[i + 1])
	{
		if (!game->map->matrix[i + 2])
			comp1 = ft_strlen(game->map->matrix[i]) - 1;
		else
			comp1 = ft_strlen(game->map->matrix[i]);
		comp2 = ft_strlen(game->map->matrix[i + 1]);
		if (comp1 != comp2)
			return (0);
		i++;
	}
	return (1);
}


int check_map(t_game *game)
{
	if (!check_rect(game))
		return (0);
	return (1);
}