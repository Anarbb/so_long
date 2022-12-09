/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:50:17 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/09 15:52:15 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/game.h"

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
	ft_calloc(1, sizeof(t_game));
	game.win_ptr = mlx_new_window(game.mlx_ptr,
			map->width, map->height, "so_pac");
	draw_map(map, &game);
	mlx_loop(game.mlx_ptr);
}
