/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:43:19 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/24 14:33:56 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	animate_enemy(t_game *game, int dir)
{
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
