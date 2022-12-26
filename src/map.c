/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:26:41 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/12/26 16:18:41 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	init_map(t_game *game, char *map_path)
{
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map)
		return (0);
	if (!get_map_size(map_path, game))
		return (0);
	game->map->matrix = (char **)malloc(sizeof(char *)
			* game->map->height);
	if (!game->map->matrix)
		return (0);
	if (!create_matrix(map_path, game))
		return (0);
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
			game->map->width = ft_strlen(game->map->line)
				* SS - SS;
		free(game->map->line);
	}
	free(game->map->line);
	game->map->height = game->map->counter * SS;
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
		free(game->map->line);
		game->map->y++;
	}
	game->map->matrix[game->map->y] = NULL;
	free(game->map->line);
	close(game->map->fd);
	return (1);
}

void	draw_map(t_game *g)
{
	g->map->y = 0;
	while (g->map->y < g->map->height / SS)
	{
		g->map->x = 0;
		while (g->map->x < g->map->width / SS)
		{
			if (g->map->matrix[g->map->y][g->map->x] == '1')
				draw_xpm(&g, g->map->wall_img, g->map->x * SS, g->map->y * SS);
			else if (g->map->matrix[g->map->y][g->map->x] == '0')
				draw_xpm(&g, g->map->empty_img, g->map->x * SS, g->map->y * SS);
			else if (g->map->matrix[g->map->y][g->map->x] == 'C')
				draw_xpm(&g, g->map->c_img, g->map->x * SS, g->map->y * SS);
			else if (g->map->matrix[g->map->y][g->map->x] == 'E')
				draw_xpm(&g, g->map->exit_img, g->map->x * SS, g->map->y * SS);
			else if (g->map->matrix[g->map->y][g->map->x] == 'P')
				draw_xpm(&g, g->player->img, g->map->x * SS, g->map->y * SS);
			else if (g->map->matrix[g->map->y][g->map->x] == 'G')
				draw_xpm(&g, g->enemy->img, g->map->x * SS, g->map->y * SS);
			g->map->x++;
		}
		g->map->y++;
	}
	draw_score(g);
}
