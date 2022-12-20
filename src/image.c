/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:22:00 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/19 16:43:31 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_img(t_game *game)
{
	game->map->wall_img = mlx_xpm_file_to_image(game->mlx_ptr, WALL,
			&game->map->img_width, &game->map->img_height);
	game->map->empty_img = mlx_xpm_file_to_image(game->mlx_ptr, EMPTY,
			&game->map->img_width, &game->map->img_height);
	game->map->collectible_img = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTIBLE, &game->map->img_width, &game->map->img_height);
	game->map->exit_img = mlx_xpm_file_to_image(game->mlx_ptr, EXIT,
			&game->map->img_width, &game->map->img_height);
}
