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

void	read_map(t_game *game, char *filename)
{
	int		fd;
	char	*map;

	fd = open(filename, O_RDONLY);
	check_file(fd, filename);
	map = get_next_line(fd);
	game->width = ft_strlen(map) - 1;
	game->height = 0;
	game->move = 0;
	game->line = ft_strdup(map);
	while (map)
	{
		game->height++;
		free(map);
		map = get_next_line(fd);
		game->line = ft_strjoin(game->line, map);
	}
	close(fd);
}

void	check_map(t_game *game)
{
	int	i;
	int	m_len;

	if (game->width * game->height != ft_strlen(game->line))
		error_message("The map must be rectangular.\n");
	i = 0;
	m_len = ft_strlen(game->line);
	while (i < m_len)
	{
		if (game->line[i] != '1' && game->line[i] != '0' \
			&& game->line[i] != 'P' && game->line[i] != 'C' \
			&& game->line[i] != 'E')
			error_message("Invalid components.\n");
		i++;
	}
	check_wall(game);
	check_component(game);
	// check_path(game);
}
