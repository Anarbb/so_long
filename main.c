/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:50:17 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/10 14:41:12 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/game.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
	}
	if (keycode == 13)
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		usleep(100000);
		draw_map(game->map, game);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		exit(0);
	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!init_map(argv[1], game->map))
		exit(0);
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map->width,
			game->map->height, "so_long");
	draw_map(game->map, game);
	mlx_hook(game->win_ptr, 2, 1L << 0, key_hook, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
