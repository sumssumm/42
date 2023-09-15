/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 05:13:51 by suminpar          #+#    #+#             */
/*   Updated: 2023/09/15 03:46:27 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game, char *file)
{
	read_map(game, file);
	check_map(game);
	game->mlx_ptr = mlx_init();
	game->image = save_image(game->mlx_ptr);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * 64, \
									game->height * 64, "so_long");
	put_image(game);
}

int	quit_game(t_game *game)
{
	size_t	i;

	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		free(game->copy[i]);
		i++;
	}
	free(game->map);
	free(game->copy);
	free(game);
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

void	clear_game(t_game *game)
{
	size_t	i;

	game->move++;
	ft_printf("%d moves.\n!!clear!!\n", game->move);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		free(game->copy[i]);
		i++;
	}
	free(game->map);
	free(game->copy);
	free(game);
	exit(0);
}
