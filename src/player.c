/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ven <aarbaoui@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:40:29 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/12 12:06:00 by ven              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_player(t_game *game)
{
	game->player = ft_calloc(1, sizeof(t_player));
	get_players_cords(game);
	game->player->img = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER, &game->player->width, &game->player->height);
	game->player->addr = mlx_get_data_addr(game->player->img, &game->player->bits_per_pixel, &game->player->line_length, &game->player->endian);
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
			j++;
		}
		i++;
	}
}

int	move_player(int keynum, t_game *game)
{
	if (keynum == 13 || keynum == 119)
	{
		game->map->matrix[(game->player->y)][(game->player->x)] = '0';
		game->map->matrix[(game->player->y - 1)][(game->player->x)] = 'P';
		game->player->y -= 1;
		ft_putstr_fd("up" , 1);
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		draw_map(game);
	}
	if (keynum == 1 || keynum == 115)
	{
		game->map->matrix[(game->player->y)][(game->player->x)] = '0';
		game->map->matrix[(game->player->y + 1)][(game->player->x)] = 'P';
		game->player->y += 1;
		ft_putstr_fd("down" , 1);
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		draw_map(game);
	}
	if (keynum == 0 || keynum == 97)
	{
		game->map->matrix[(game->player->y)][(game->player->x) ] = '0';
		game->map->matrix[(game->player->y)][(game->player->x - 1)] = 'P';
		game->player->x -= 1;
		ft_putstr_fd("left",1 );
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		draw_map(game);
	}
	if (keynum == 2 || keynum == 100)
	{
		game->map->matrix[(game->player->y)][(game->player->x)] = '0';
		game->map->matrix[(game->player->y)][(game->player->x + 1)] = 'P';
		game->player->x += 1;
		ft_putstr_fd("right", 1);
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		draw_map(game);
	}
	return (0);
}