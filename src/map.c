/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:26:41 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/10 14:41:45 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

int	init_map(char *map_path, t_map *map)
{
	map->fd = open(map_path, O_RDONLY);
	if (map->fd == -1)
		return (0);
	if (!get_next_line(map->fd, &map->line))
		return (0);
	map->width = (ft_strlen(map->line) * SPRITE_SIZE) - SPRITE_SIZE;
	free(map->line);
	map->height = SPRITE_SIZE;
	while (get_next_line(map->fd, &map->line))
	{
		map->height += SPRITE_SIZE;
		free(map->line);
	}
	map->matrix = (char **)malloc(sizeof(char *) * map->height);
	map->counter = 0;
	close(map->fd);
	if (!create_matrix(map_path, map))
		return (0);
	return (1);
}

int	create_matrix(char *map_path, t_map *map)
{
	map->fd = open(map_path, O_RDONLY);
	if (map->fd == -1)
		return (0);
	while (get_next_line(map->fd, &map->line))
	{
		map->matrix[map->counter] = ft_strdup(map->line);
		map->counter++;
		free(map->line);
	}
	close(map->fd);
	return (1);
}

void	draw_xpm(t_map *map, t_game *game, char *block)
{
	map->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, block,
			&map->img_width, &map->img_height);
	if (!map->img_ptr)
		exit(1);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, map->img_ptr,
		map->x * SPRITE_SIZE, map->y * SPRITE_SIZE);
}

void	draw_map(t_map *map, t_game *game)
{
	while (map->y < map->height / SPRITE_SIZE)
	{
		map->x = 0;
		while (map->x < map->width / SPRITE_SIZE)
		{
			if (map->matrix[map->y][map->x] == '1')
				draw_xpm(map, game, WALL);
			else if (map->matrix[map->y][map->x] == '0')
				draw_xpm(map, game, EMPTY);
			else if (map->matrix[map->y][map->x] == 'C')
				draw_xpm(map, game, COLLECTIBLE);
			else if (map->matrix[map->y][map->x] == 'E')
				draw_xpm(map, game, EXIT);
			else if (map->matrix[map->y][map->x] == 'P')
				draw_xpm(map, game, PLAYER);
			else if (map->matrix[map->y][map->x] == 'G')
				draw_xpm(map, game, ENEMY);
			else
				exit(1);
			map->x++;
		}
		map->y++;
	}
}
void	destroy_map(t_map *map)
{
	// fill map with 0
	int i = 0;
	int j = 0;
	while (map->matrix[i])
	{
		while (map->matrix[i][j])
		{
			map->matrix[i][j] = '1';
			j++;
		}
		j = 0;
		i++;
	}
}