/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 01:57:59 by suminpar          #+#    #+#             */
/*   Updated: 2023/09/18 23:15:20 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(t_game *game)
{
	size_t	x;
	size_t	y;

	duplicate_map(game);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->copy[y][x] == 'P')
			{
				find_path(game, x, y);
				break ;
			}
			x++;
		}
		y++;
	}
	error_path(game);
}

void	error_path(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->copy[y][x] == 'E' || game->copy[y][x] == 'C')
				error_message("Invalid path.\n", game);
			x++;
		}
		y++;
	}
}

void	find_path(t_game *game, size_t x, size_t y)
{
	if (x < 1 || game->width - 1 < x || y < 1 || game->height - 1 < y \
		|| (game->copy[y][x] != '0' && game->copy[y][x] != 'E' \
		&& game->copy[y][x] != 'P' && game->copy[y][x] != 'C'))
		return ;
	if (game->copy[y][x] == 'E')
	{
		game->copy[y][x] = '1';
		return ;
	}
	else
		game->copy[y][x] = '1';
	if (game->copy[y][x - 1] != '1')
		find_path(game, x - 1, y);
	if (game->copy[y][x + 1] != '1')
		find_path(game, x + 1, y);
	if (game->copy[y - 1][x] != '1')
		find_path(game, x, y - 1);
	if (game->copy[y + 1][x] != '1')
		find_path(game, x, y + 1);
}

void	duplicate_map(t_game *game)
{
	size_t	i;

	i = 0;
	game->copy = ft_calloc(game->height, sizeof(char *));
	if (game->copy == NULL)
		error_message("Fail malloc.\n", game);
	while (i < game->height)
	{
		game->copy[i] = ft_strdup(game->map[i]);
		i++;
	}
}
