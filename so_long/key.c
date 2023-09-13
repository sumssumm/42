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
	printf("up: %d %d\n", game->pos_x, game->pos_y);
	if (game->map[game->pos_y - 1][game->pos_x] == 'C')
		game->collectible++;
	if (game->map[game->pos_y - 1][game->pos_x] == 'E' 
			&& game->collectible == game->all_col)
		clear_game(game);
	else if (game->map[game->pos_y - 1][game->pos_x] != '1' 
			&& game->map[game->pos_y - 1][game->pos_x]  != 'E')
	{
		game->map[game->pos_y][game->pos_x] = '0';
		game->map[game->pos_y - 1][game->pos_x]  = 'P';
		game->move++;
		ft_printf("%d moves.\n", game->move);
		printf("%d %d\n", game->all_col, game->collectible);
		put_image(game);
	}
}

void	move_left(t_game *game)
{
	printf("L: %d %d\n", game->pos_x, game->pos_y);

	if (game->map[game->pos_y][game->pos_x - 1] == 'C')
		game->collectible++;
	if (game->map[game->pos_y][game->pos_x - 1] == 'E' 
			&& game->collectible == game->all_col)
		clear_game(game);
	else if (game->map[game->pos_y][game->pos_x - 1] != '1' 
			&& game->map[game->pos_y][game->pos_x - 1]  != 'E')
	{
		game->map[game->pos_y][game->pos_x] = '0';
		game->map[game->pos_y][game->pos_x - 1]  = 'P';
		game->move++;
		ft_printf("%d moves.\n", game->move);
		printf("%d %d\n", game->all_col, game->collectible);

		put_image(game);
	}
}

void	move_down(t_game *game)
{
	printf("D: %d %d\n", game->pos_x, game->pos_y);

	if (game->map[game->pos_y + 1][game->pos_x] == 'C')
		game->collectible++;
	if (game->map[game->pos_y + 1][game->pos_x] == 'E' 
			&& game->collectible == game->all_col)
		clear_game(game);
	else if (game->map[game->pos_y + 1][game->pos_x] != '1' 
			&& game->map[game->pos_y + 1][game->pos_x]  != 'E')
	{
		game->map[game->pos_y][game->pos_x] = '0';
		game->map[game->pos_y + 1][game->pos_x]  = 'P';
		game->move++;
		ft_printf("%d moves.\n", game->move);
		printf("%d %d\n", game->all_col, game->collectible);
		put_image(game);
	}
}

void	move_right(t_game *game)
{
	printf("R: %d %d\n", game->pos_x, game->pos_y);
	 
	if (game->map[game->pos_y][game->pos_x + 1] == 'C')
		game->collectible++;
	if (game->map[game->pos_y][game->pos_x + 1] == 'E' 
			&& game->collectible == game->all_col)
		clear_game(game);
	else if (game->map[game->pos_y][game->pos_x + 1] != '1' 
			&& game->map[game->pos_y][game->pos_x + 1] != 'E')
	{
		game->map[game->pos_y][game->pos_x] = '0';
		game->map[game->pos_y][game->pos_x + 1]  = 'P';
		game->move++;
		ft_printf("%d moves.\n", game->move);
		printf("%d %d\n", game->all_col, game->collectible);

		put_image(game);
	}
}
