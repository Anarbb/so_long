/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:26:41 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/11 21:26:51 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

int	init_map(t_game *game, char *map_path)
{
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
		return (0);
	if (!get_map_size(map_path, game))
		return (0);
	game->map->matrix = (char **)malloc(sizeof(char *) * game->map->height);
	if (!game->map->matrix)
		return (0);
	if (!create_matrix(map_path, game))
		return (0);
	game->map->matrix[game->map->height] = NULL;
	return (1);
}

int	get_map_size(char *map_path, t_game *game)
{
	game->map->fd = open(map_path, O_RDONLY);
	if (game->map->fd == -1)
		return (0);
	while (get_next_line(game->map->fd, &game->map->line))
	{
		game->map->counter++;
		if (game->map->width == 0)
			game->map->width = ft_strlen(game->map->line) * SPRITE_SIZE - SPRITE_SIZE;
		free(game->map->line);
	}
	game->map->height = game->map->counter * SPRITE_SIZE;
	close(game->map->fd);
	return (1);
}

int	create_matrix(char *map_path, t_game *game)
{
	game->map->fd = open(map_path, O_RDONLY);
	if (game->map->fd == -1)
		return (0);
	while (get_next_line(game->map->fd, &game->map->line))
	{
		game->map->matrix[game->map->y] = ft_strdup(game->map->line);
		if (!game->map->matrix[game->map->y])
			return (0);
		free(game->map->line);
		game->map->y++;
	}
	close(game->map->fd);
	return (1);
}

void	draw_xpm(t_game **game, char *block)
{
	(*game)->map->img_ptr = mlx_xpm_file_to_image((*game)->mlx_ptr, block, &(*game)->map->img_width, &(*game)->map->img_height);
	mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->map->img_ptr, (*game)->map->x * SPRITE_SIZE, (*game)->map->y * SPRITE_SIZE);
}

void	draw_map(t_game *game)
{
	game->map->y = 0;
	while (game->map->y < game->map->height / SPRITE_SIZE)
	{
		game->map->x = 0;
		while (game->map->x < game->map->width / SPRITE_SIZE)
		{
			if (game->map->matrix[game->map->y][game->map->x] == '1')
				draw_xpm(&game, WALL);
			else if (game->map->matrix[game->map->y][game->map->x] == '0')
				draw_xpm(&game, EMPTY);
			else if (game->map->matrix[game->map->y][game->map->x] == 'C')
				draw_xpm(&game, COLLECTIBLE);
			else if (game->map->matrix[game->map->y][game->map->x] == 'G')
				draw_xpm(&game, ENEMY);
			else if (game->map->matrix[game->map->y][game->map->x] == 'E')
				draw_xpm(&game, EXIT);
			else if (game->map->matrix[game->map->y][game->map->x] == 'P')
				draw_xpm(&game, PLAYER);
			game->map->x++;
		}
		game->map->y++;
	}
}
