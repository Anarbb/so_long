/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:43:19 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/27 16:02:41 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	animate_enemy(t_game *game, int dir)
{
	int	i;

	i = 0;
	while (i < 10000000)
		i++;
	if (dir)
	{
		game->enemy->img = mlx_xpm_file_to_image(game->mlx_ptr,
				ENEMY_RIGHT,
				&game->map->img_width, &game->map->img_height);
	}
	else
	{
		game->enemy->img = mlx_xpm_file_to_image(game->mlx_ptr,
				ENEMY_LEFT,
				&game->map->img_width, &game->map->img_height);
	}
}
