/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:11:20 by suminpar          #+#    #+#             */
/*   Updated: 2023/09/05 21:50:39 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(game->line))
	{
		if (game->line[i] == 'P')
			break ;
		i++;
	}
	if (game->line[i - game->width] == 'C')
		game->collectible++;
	if (game->line[i - game->width] == 'E' \
			&& game->collectible == game->all_col)
		clear_game(game);
	else if (game->line[i - game->width] != '1' \
			&& game->line[i - game->width] != 'E')
	{
		game->line[i] = '0';
		game->line[i - game->width] = 'P';
		game->move++;
		ft_printf("%d moves.\n", game->move);
		put_image(game);
	}
}

void	move_left(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(game->line))
	{
		if (game->line[i] == 'P')
			break ;
		i++;
	}
	if (game->line[i - 1] == 'C')
		game->collectible++;
	if (game->line[i - 1] == 'E' && game->collectible == game->all_col)
		clear_game(game);
	else if (game->line[i - 1] != '1' && game->line[i - 1] != 'E')
	{
		game->line[i] = '0';
		game->line[i - 1] = 'P';
		game->move++;
		ft_printf("%d moves.\n", game->move);
		put_image(game);
	}
}

void	move_down(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(game->line))
	{
		if (game->line[i] == 'P')
			break ;
		i++;
	}
	if (game->line[i + game->width] == 'C')
		game->collectible++;
	if (game->line[i + game->width] == 'E' \
			&& game->collectible == game->all_col)
		clear_game(game);
	else if (game->line[i + game->width] != '1' \
			&& game->line[i + game->width] != 'E')
	{
		game->line[i] = '0';
		game->line[i + game->width] = 'P';
		game->move++;
		ft_printf("%d moves.\n", game->move);
		put_image(game);
	}
}

void	move_right(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(game->line))
	{
		if (game->line[i] == 'P')
			break ;
		i++;
	}
	if (game->line[i + 1] == 'C')
		game->collectible++;
	if (game->line[i + 1] == 'E' \
			&& game->collectible == game->all_col)
		clear_game(game);
	else if (game->line[i + 1] != '1' \
			&& game->line[i + 1] != 'E')
	{
		game->line[i] = '0';
		game->line[i + 1] = 'P';
		game->move++;
		ft_printf("%d moves.\n", game->move);
		put_image(game);
	}
}
