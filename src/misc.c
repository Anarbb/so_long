/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:13:45 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/23 11:19:59 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	draw_score(t_game *game)
{
	int		x;
	int		y;
	char	*moves;

	moves = ft_itoa(game->moves);
	x = (game->map->x / 2) * SS;
	y = game->map->y * SS + 32;
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, x + 64, y, 0xFFFFFF, moves);
	free(moves);
}

int	check_exit(t_game *game)
{
	if (game->map->coins == game->map->coins_counter)
		exit_game(game, "You win!\n", 0);
	return (0);
}

int	check_move(char **matrix, int x, int y)
{
	int	x_len;
	int	y_len;

	x_len = ft_strlen(matrix[0]);
	y_len = ft_arrlen(matrix);
	if ((x >= 0 && x < x_len && y >= 0 && y < y_len && matrix[y][x] != '1'))
		return (1);
	return (0);
}

void	draw_xpm(t_game **game, void *img, int x, int y)
{
	mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
		img, x, y);
}

void	exit_game(t_game *game, char *msg, int status)
{
	ft_putstr_fd(msg, 1);
	if (game->win_ptr && game)
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	}
	exit(status);
}
