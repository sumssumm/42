/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 05:13:51 by suminpar          #+#    #+#             */
/*   Updated: 2023/09/05 21:42:18 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game, char *map)
{
	game->mlx_ptr = mlx_init();
	game->image = save_image(game->mlx_ptr);
	read_map(game, map);
	check_map(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * 64, \
												game->height * 64, "so_long");
	put_image(game);
}

int	quit_game(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->line);
	exit(0);
}

int	press_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		quit_game(game);
	if (keycode == KEY_W)
		move_up(game);
	if (keycode == KEY_A)
		move_left(game);
	if (keycode == KEY_S)
		move_down(game);
	if (keycode == KEY_D)
		move_right(game);
	return (0);
}

int	clear_game(t_game *game)
{
	game->move++;
	ft_printf("%d moves.\n!!clear!!\n", game->move);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->line);
	exit(0);
}