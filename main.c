/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:57:56 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/16 16:09:31 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = ft_calloc(1, sizeof(t_game));
		game->mlx_ptr = mlx_init();		
		if (!init_map(game, argv[1]))
			return (0);
		if (!check_map(game))
			exit(0);
		game->win_ptr = mlx_new_window(game->mlx_ptr, game->map->width, game->map->height + 64, "so_long");
		init_player(game);
		draw_map(game);
		mlx_key_hook(game->win_ptr, move_player, game);
		mlx_loop(game->mlx_ptr);
	}
	else
		ft_putstr_fd("Error\n", 1);
	return (0);
}
 