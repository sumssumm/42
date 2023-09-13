/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 07:40:30 by suminpar          #+#    #+#             */
/*   Updated: 2023/09/05 22:05:57 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void read_map(t_game *game, char *file)
{
	int i;
	int fd;
	char *map;

	check_file(game, file);
	game->map = malloc(sizeof(char *) * game->height);
	if (game->map == NULL)
		error_message("Fail malloc.\n");
	fd = open(file, O_RDONLY);
	map = get_next_line(fd);
	game->width = ft_strlen(map) - 1;
	game->move = 0;
	game->collectible = 0;
	game->all_col = 0;
	i = 0;
	while (map)
	{
		game->map[i] = map;
		map = get_next_line(fd);
		i++;
	}
	close(fd);
}

void check_map(t_game *game)
{
	check_shape(game);
	check_wall(game);
	check_component(game);
	check_path(game);
}
