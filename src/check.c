/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:42:26 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/20 14:22:04 by aarbaoui         ###   ########.fr       */
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

void	check_path(char *s)
{
	char	*tmp;
	char	empty[5];
	int		i;
	int		j;

	tmp = s;
	j = 0;
	i = ft_strlen(s);
	if (i < 4)
		return ;
	tmp += i - 1;
	while (j < 4)
	{
		empty[j] = *tmp;
		j++;
		tmp--;	
	}
	empty[4] = 0;
	if (ft_strncmp(empty, "reb.", 4))
	{
		ft_putstr_fd("Error : Invalid map name.\n", 1);
		exit(0);
	}
}

void	check_map(t_game *game)
{
	if ((game->map->exits > 1 || game->player->count > 1)
		&& (game->map->exits && game->player->count))
		exit(0);
	check_rect(game);
	backtracking(game);
}
