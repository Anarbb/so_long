/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:50:17 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/05 15:56:31 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/game.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;
	if (argc != 2)
		exit(0);
	game.mlx_ptr = mlx_init();
	init_map(argv[1], &map);
	game.win_ptr = mlx_new_window(game.mlx_ptr, map.w, map.h, "so_pac");
	draw_map(&map, &game);
	mlx_loop(game.mlx_ptr);
}
