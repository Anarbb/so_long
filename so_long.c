/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:39:16 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/24 16:09:49 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	update(t_game *game)
{
	
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	draw_map(game);
	return (0);
}

void	init_game(t_game *game)
{
	init_img(game);
	init_player(game);
	init_enemy(game);
	check_map(game);
	draw_map(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		check_path(argv[1]);
		game = ft_calloc(1, sizeof(t_game));
		game->mlx_ptr = mlx_init();
		if (!init_map(game, argv[1]))
			exit_game(game, "Error: Invalid map\n", 1);
		game->win_ptr = mlx_new_window(game->mlx_ptr, game->map->width,
				game->map->height + 64, "so_long");
		init_game(game);
		mlx_hook(game->win_ptr, 2, 0, move_player, game);
		mlx_loop_hook(game->mlx_ptr, update, game);
		mlx_loop(game->mlx_ptr);
	}
	else
		ft_putstr_fd("Error : ./so_long <map_path>\n", 1);
	return (0);
}