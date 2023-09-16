/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:11:20 by suminpar          #+#    #+#             */
/*   Updated: 2023/09/16 12:34:17 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->pos_y - 1][game->pos_x] == 'C')
		game->collectible++;
	if (game->map[game->pos_y - 1][game->pos_x] == 'E' \
			&& game->collectible == game->all_col)
		clear_game(game);
	else if (game->map[game->pos_y - 1][game->pos_x] != '1' \
			&& game->map[game->pos_y - 1][game->pos_x] != 'E')
	{
		game->map[game->pos_y][game->pos_x] = '0';
		game->map[game->pos_y - 1][game->pos_x] = 'P';
		game->move++;
		ft_printf("%d moves.\n", game->move);
		put_image(game);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->pos_y][game->pos_x - 1] == 'C')
		game->collectible++;
	if (game->map[game->pos_y][game->pos_x - 1] == 'E' \
			&& game->collectible == game->all_col)
		clear_game(game);
	else if (game->map[game->pos_y][game->pos_x - 1] != '1' \
			&& game->map[game->pos_y][game->pos_x - 1] != 'E')
	{
		game->map[game->pos_y][game->pos_x] = '0';
		game->map[game->pos_y][game->pos_x - 1] = 'P';
		game->move++;
		ft_printf("%d moves.\n", game->move);
		put_image(game);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->pos_y + 1][game->pos_x] == 'C')
		game->collectible++;
	if (game->map[game->pos_y + 1][game->pos_x] == 'E' \
			&& game->collectible == game->all_col)
		clear_game(game);
	else if (game->map[game->pos_y + 1][game->pos_x] != '1' \
			&& game->map[game->pos_y + 1][game->pos_x] != 'E')
	{
		game->map[game->pos_y][game->pos_x] = '0';
		game->map[game->pos_y + 1][game->pos_x] = 'P';
		game->move++;
		ft_printf("%d moves.\n", game->move);
		put_image(game);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->pos_y][game->pos_x + 1] == 'C')
		game->collectible++;
	if (game->map[game->pos_y][game->pos_x + 1] == 'E' \
			&& game->collectible == game->all_col)
		clear_game(game);
	else if (game->map[game->pos_y][game->pos_x + 1] != '1' \
			&& game->map[game->pos_y][game->pos_x + 1] != 'E')
	{
		game->map[game->pos_y][game->pos_x] = '0';
		game->map[game->pos_y][game->pos_x + 1] = 'P';
		game->move++;
		ft_printf("%d moves.\n", game->move);
		put_image(game);
	}
}
