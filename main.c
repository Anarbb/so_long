/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:50:17 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/09 16:08:28 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/game.h"

int key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		exit(0);
	if(keycode == 13)
	{
		game->map->y -= 1;
		draw_map(game->map, game);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	game;

	if (argc != 2)
		exit(0);
	map = ft_calloc(sizeof(t_map), 1);
	if (init_map(argv[1], map) == -1)
		exit(0);
	game.mlx_ptr = mlx_init();
	game.map = map;
	ft_calloc(1, sizeof(t_game));
	game.win_ptr = mlx_new_window(game.mlx_ptr,
			map->width, map->height, "so_pac");
	draw_map(map, &game);
	mlx_key_hook(game.win_ptr, key_hook, &game);
	mlx_loop(game.mlx_ptr);
}
