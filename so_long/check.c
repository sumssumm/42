/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:38:03 by suminpar          #+#    #+#             */
/*   Updated: 2023/09/18 23:01:21 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_name(char *filename)
{
	int		len;

	len = ft_strlen(filename);
	if (len > 4)
	{
		if (filename[len - 1] == 'r' && filename[len - 2] == 'e'
			&& filename[len - 3] == 'b' && filename[len - 4] == '.'
			&& filename[len - 5] != '.')
			return ;
		else
		{
			ft_printf("Error\nInvalid map name.\n");
			exit(1);
		}
	}
	else
	{
		ft_printf("Error\nInvalid map name.\n");
		exit(1);
	}
}

void	check_file(t_game *game, char *filename)
{
	int		fd;
	char	*map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_message("Unable to open map.\n", game);
	map = get_next_line(fd);
	if (map == NULL)
		error_message("Empty map.\n", game);
	while (map != NULL)
	{
		game->height++;
		free(map);
		map = get_next_line(fd);
	}
	close(fd);
}

void	check_shape(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (game->map[y][x] != '\n' && game->map[y][x] != '\0')
			x++;
		if (x != game->width)
			error_message("The map must be rectangular.\n", game);
		y++;
	}
}

void	check_wall(t_game *game)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			error_message("Invalid wall.\n", game);
		x++;
	}
	if (x > 40)
		error_message("Invalid size.\n", game);
	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
			error_message("Invalid wall.\n", game);
		y++;
	}
	if (y > 21)
		error_message("Invalid size.\n", game);
}

void	check_component(t_game *game)
{
	size_t	x;
	size_t	y;
	size_t	exit;
	size_t	pos;

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
	if (exit != 1 || pos != 1 || game->all_col < 1)
		error_message("Invalid component.\n", game);
}
