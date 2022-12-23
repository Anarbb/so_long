/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:40:35 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/22 19:25:15 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_enemy(t_game *game)
{
	game->enemy = ft_calloc(1, sizeof(t_enemy));
	get_enemy_cords(game);
	game->enemy->img = mlx_xpm_file_to_image(game->mlx_ptr, ENEMY,
			&game->map->img_width, &game->map->img_height);
}

void	get_enemy_cords(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height / SS)
	{
		j = 0;
		while (j < game->map->width / SS)
		{
			if (game->map->matrix[i][j] == 'G')
			{
				game->enemy->x = j;
				game->enemy->y = i;
			}
			j++;
		}
		i++;
	}
}

void	move_enemy(t_game *game)
{
	if (game->map->matrix[game->enemy->y][game->enemy->x - 1] == 'P'
		|| game->map->matrix[game->enemy->y][game->enemy->x + 1] == 'P')
		exit(0);
	if (game->enemy->mov_right && game->map->matrix[game->enemy->y]
		[game->enemy->x + 1] != '1')
	{
		game->map->matrix[game->enemy->y][game->enemy->x] = '0';
		game->map->matrix[game->enemy->y][game->enemy->x + 1] = 'G';
		game->enemy->x++;
	}
	else
	{
		game->enemy->mov_right = 0;
		game->enemy->mov_left = 1;
	}
	if (game->enemy->mov_left && game->map->matrix[game->enemy->y]
		[game->enemy->x - 1] != '1')
	{
		game->map->matrix[game->enemy->y][game->enemy->x] = '0';
		game->map->matrix[game->enemy->y][game->enemy->x - 1] = 'G';
		game->enemy->x--;
	}
	else
	{
		game->enemy->mov_right = 1;
		game->enemy->mov_left = 0;
	}	
}
