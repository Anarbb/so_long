/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:40:35 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/20 14:22:34 by aarbaoui         ###   ########.fr       */
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
	while (i < game->map->height / SPRITE_SIZE)
	{
		j = 0;
		while (j < game->map->width / SPRITE_SIZE)
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

int	move_enemy(t_game *game)
{
	int	x;
	int	y;
	
	x = game->enemy->x;
	y = game->enemy->y;
	if (check_move(game->map->matrix, x + 1, y))
		game->enemy->x++;
	if (check_move(game->map->matrix, x - 1, y))
		game->enemy->x--;
	if (check_move(game->map->matrix, x, y + 1))
		game->enemy->y++;
	if (check_move(game->map->matrix, x, y - 1))
		game->enemy->y--;
	return (0);
}