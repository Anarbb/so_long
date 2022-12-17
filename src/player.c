/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:40:29 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/17 17:42:59 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_player(t_game *game)
{
	game->player = ft_calloc(1, sizeof(t_player));
	get_players_cords(game);
	game->player->img = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER, &game->player->width, &game->player->height);
}

void	get_players_cords(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height / SPRITE_SIZE)
	{
		j = 0;
		while (j < game->map->width / SPRITE_SIZE)
		{
			if (game->map->matrix[i][j] == 'P')
			{
				game->player->x = j;
				game->player->y = i;
			}
			if (game->map->matrix[i][j] == 'C')
			{
				game->map->coins++;
			}
			j++;
		}
		i++;
	}
}

void	check_legal(t_game *game)
{
	if (game->map->matrix[(game->player->y - 1)][(game->player->x)] == '1')
		game->player->go_up = 0;
	else
		game->player->go_up = 1;
	if (game->map->matrix[(game->player->y + 1)][(game->player->x)] == '1')
		game->player->go_down = 0;
	else
		game->player->go_down = 1;
	if (game->map->matrix[(game->player->y)][(game->player->x - 1)] == '1')
		game->player->go_left = 0;
	else
		game->player->go_left = 1;
	if (game->map->matrix[(game->player->y)][(game->player->x + 1)] == '1')
		game->player->go_right = 0;
	else
		game->player->go_right = 1;
}

int	move_player(int keynum, t_game *game)
{
	check_legal(game);
	if (keynum == 13 || keynum == 119)
		move_up(game);
	if (keynum == 1 || keynum == 115)
		move_down(game);
	if (keynum == 0 || keynum == 97)
		move_left(game);
	if (keynum == 2 || keynum == 100)
		move_right(game);
	return (0);
}
