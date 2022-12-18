/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:42:26 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/18 14:08:23 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	check_rect(t_game *game)
{
	int	i;
	int	err;

	err = 0;
	i = 0;
	while (i < game->map->height / SPRITE_SIZE)
	{
		if (game->map->matrix[i][0] != '1'
			|| game->map->matrix[i][game->map->width / SPRITE_SIZE - 1] != '1')
			err++;
		i++;
	}
	i = 0;
	while (i < game->map->width / SPRITE_SIZE)
	{
		if (game->map->matrix[0][i] != '1'
			|| game->map->matrix[game->map->height / SPRITE_SIZE - 1][i] != '1')
			err++;
		i++;
	}
	if (err > 0)
	{
		ft_putstr_fd("Error : Map is not closed\n", 1);
		exit(0);
	}
}

static int	check_move(char **matrix, int x, int y)
{
	int	x_len;
	int	y_len;

	x_len = ft_strlen(matrix[0]);
	y_len = ft_arrlen(matrix);
	if ((x >= 0 && x < x_len && y >= 0 && y < y_len && matrix[y][x] != '1'))
		return (1);
	return (0);
}

static int	find_path(char **matrix, int x, int y, int coins)
{
	static int	exits;
	static int	c;

	if (matrix[y][x] == 'E')
		exits++;
	if (matrix[y][x] == 'C')
		c++;
	matrix[y][x] = '1';
	if (check_move(matrix, x - 1, y))
		find_path(matrix, x - 1, y, coins);
	if (check_move(matrix, x, y + 1))
		find_path(matrix, x, y + 1, coins);
	if (check_move(matrix, x + 1, y))
		find_path(matrix, x + 1, y, coins);
	if (check_move(matrix, x, y - 1))
		find_path(matrix, x, y - 1, coins);
	if (exits > 0 && c == coins)
		return (1);
	return (0);
}

static void	backtracking(t_game *game)
{
	char	**str;
	int		x_p;
	int		y_p;

	x_p = game->player->x;
	y_p = game->player->y;
	str = ft_arrdup(game->map->matrix);
	if (find_path(str, x_p, y_p, game->map->coins) == 0)
	{
		ft_putstr_fd("Error : Map is not valid due to not having a valid path\n", 1);
		exit(0);
	}
	ft_free_arr(str);
}

void	check_map(t_game *game)
{
	check_rect(game);
	backtracking(game);
}