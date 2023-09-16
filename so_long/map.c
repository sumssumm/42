/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 07:40:30 by suminpar          #+#    #+#             */
/*   Updated: 2023/09/16 13:56:03 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_game *game, char *file)
{
	int		i;
	int		fd;
	char	*map;

	check_file(game, file);
	game->map = ft_calloc(game->height, sizeof(char *));
	if (game->map == NULL)
		error_message("Fail malloc.\n", game);
	fd = open(file, O_RDONLY);
	map = get_next_line(fd);
	game->width = ft_strlen(map) - 1;
	i = 0;
	while (map)
	{
		game->map[i] = map;
		map = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	check_map(t_game *game)
{
	size_t	x;
	size_t	y;

	check_shape(game);
	check_wall(game);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] != '1' && game->map[y][x] != '0' \
				&& game->map[y][x] != 'P' && game->map[y][x] != 'C' \
				&& game->map[y][x] != 'E')
				error_message("Not accepted components.\n", game);
			x++;
		}
		y++;
	}
	check_component(game);
	check_path(game);
}
