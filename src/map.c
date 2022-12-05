/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ven <aarbaoui@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:26:41 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/05 17:51:35 by ven              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	init_map(char *map_path, t_map *map)
{
	map->path = map_path;
	map->fd = open(map_path, O_RDONLY);
	map->h = 0;
	while (get_next_line(map->fd, &map->line))
		map->h++;
	map->h *= SPRITE_SIZE;
	close(map->fd);
	map->fd = open(map_path, O_RDONLY);
	map->w = -32;
	while (get_next_line(map->fd, &map->line))
	{
		map->w = ft_strlen(map->line) * SPRITE_SIZE - 32;
		break;
	}
}

void	draw_xpm(t_map *map, t_game *game, char *block)
{
	game->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, block, &map->garbage, &map->garbage);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_ptr, map->x * 32, map->y * 32);
}

void	draw_map(t_map *map, t_game *game)
{
	map->garbage = 0;
	map->y = 0;
	map->x = 0;
	map->counter = 0;
	while (map->line)
	{
		while (map->line[map->counter])
		{
			if (map->line[map->counter] == '1')
				draw_xpm(map, game, WALL);
			else if (map->line[map->counter] == '0')
				draw_xpm(map, game, EMPTY);
			else if (map->line[map->counter] == 'C')
				draw_xpm(map, game, COLLECTIBLE);
			else if (map->line[map->counter] == 'P')
				draw_xpm(map, game, PLAYER);
			else if (map->line[map->counter] == 'E')
				draw_xpm(map, game, EXIT);
			map->counter++;
			map->x++;
		}
		map->y++;
		map->x = 0;
		map->counter = 0;
		get_next_line(map->fd, &map->line);
	}
	close(map->fd);
}
