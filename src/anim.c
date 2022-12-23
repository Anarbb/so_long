/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:43:19 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/23 12:47:23 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	animate_enemy(t_game *game, int dir)
{
	if (dir)
	{
		game->enemy->img = mlx_xpm_file_to_image(game->mlx_ptr,
			ft_strjoin(ENEMY, "right1"),
			&game->map->img_width, &game->map->img_height);
		update(game);
		usleep(1000);
		game->enemy->img = mlx_xpm_file_to_image(game->mlx_ptr,
			ft_strjoin(ENEMY, "right2"),
			&game->map->img_width, &game->map->img_height);
		update(game);
	}
	else
	{
		game->enemy->img = mlx_xpm_file_to_image(game->mlx_ptr,
			ft_strjoin(ENEMY, "left1"),
			&game->map->img_width, &game->map->img_height);
		update(game);
		usleep(1000);
		game->enemy->img = mlx_xpm_file_to_image(game->mlx_ptr,
			ft_strjoin(ENEMY, "left1"),
			&game->map->img_width, &game->map->img_height);
		update(game);
	}
}