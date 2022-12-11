/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:50:17 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/11 20:15:51 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/game.h"

int	key_hook(int keycode, t_game *game)
{

	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = ft_calloc(1, sizeof(t_game));
		game->mlx_ptr = mlx_init();
		game->map = ft_calloc(1, sizeof(t_map));
		if (!init_map(game, argv[1]))
			return (0);
		game->win_ptr = mlx_new_window(game->mlx_ptr, game->map->width, game->map->height, "so_long");
		draw_map(game);
		mlx_key_hook(game->win_ptr, key_hook, game);
		mlx_loop(game->mlx_ptr);
	}
	else
		printf("Error\n");
	return (0);
}
 