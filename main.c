/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:57:56 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/15 19:29:37 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void checker()
{
	system("leaks so_long");
}
int	main(int argc, char **argv)
{
	t_game	*game;
	
	atexit(checker);
	if (argc == 2)
	{
		game = ft_calloc(1, sizeof(t_game));
		game->mlx_ptr = mlx_init();		
		fprintf(stderr,"\n%p\n", game->map);
		if (!init_map(game, argv[1]))
			return (0);
		game->win_ptr = mlx_new_window(game->mlx_ptr, game->map->width, game->map->height + 64, "so_long");
		fprintf(stderr,"\n%p\n", game->player);
		init_player(game);
		fprintf(stderr,"\n%p\n", game->player);
		exit(1);
		draw_map(game);
		mlx_key_hook(game->win_ptr, move_player, game);
		mlx_loop(game->mlx_ptr);
	}
	else
		ft_putstr_fd("Error\n", 1);
	return (0);
}
 