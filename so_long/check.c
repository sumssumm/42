/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:38:03 by suminpar          #+#    #+#             */
/*   Updated: 2023/09/05 22:05:40 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_name(char *filename)
{
	int len;

	len = ft_strlen(filename);
	if (len > 4)
	{
		if (filename[len - 1] == 'r' && filename[len - 2] == 'e' &&
			filename[len - 3] == 'b' && filename[len - 4] == '.' &&
			filename[len - 5] != '.')
			return;
		else
			error_message("Invalid map name.\n");
	}
	else
		error_message("Invalid map name.\n");
}

void check_file(t_game *game, char *filename)
{
	int fd;
	// int byte;
	char *map;

	game->height = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_message("Unable to open map.\n");
	// byte = read(fd, filename, 1);
	// if (byte != 1)
	// {
	// 	close(fd);
	// 	error_message("Empty map.\n");
	// }
	map = get_next_line(fd);
	while (map != NULL)
	{
		game->height++;
		free(map);
		map = get_next_line(fd);
	}
	close(fd);
}

void check_shape(t_game *game)
{
	size_t x;
	size_t y;

	y = 0;
	// write(1, &game->height, 1);
	while (y < game->height)
	{
		x = 0;
		while (game->map[y][x] != '\n' && game->map[y][x] != '\0')
		{
			write(1, &game->map[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		if (x != game->width)
			error_message("The map must be rectangular.\n");
		y++;
	}
}

void check_wall(t_game *game)
{
	size_t x;
	size_t y;

	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			error_message("Invalid wall.\n");
		x++;
	}
	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1') // width -1
			error_message("Invalid wall.\n");
		y++;
	}
}

void check_component(t_game *game)
{
	size_t x;
	size_t y;
	size_t exit;
	size_t pos;

	y = 0;
	exit = 0;
	pos = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'E')
				exit++;
			else if (game->map[y][x] == 'P')
				pos++;
			else if (game->map[y][x] == 'C')
				game->all_col++;
			x++;
		}
		y++;
	}
	if (exit != 1 || pos != 1)
		error_message("Invalid component.\n");
	if (game->all_col < 1)
		error_message("Invalid collectible.\n");
}
