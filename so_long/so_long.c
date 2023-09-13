/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 04:57:53 by suminpar          #+#    #+#             */
/*   Updated: 2023/09/05 21:34:19 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_game *game;

	if (argc != 2)
		error_message("Need a map.\n");
	check_name(argv[1]);
	game = malloc(sizeof(t_game));
	if (game == NULL)
		error_message("Fail malloc.\n");
	start_game(game, argv[1]);
	mlx_hook(game->win_ptr, X_EVENT_KEY_PRESS, 0, &press_key, game);
	mlx_hook(game->win_ptr, X_EVENT_KEY_EXIT, 0, &quit_game, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}

void error_message(char *str)
{
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	exit(1);
}
