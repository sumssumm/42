/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 04:57:53 by suminpar          #+#    #+#             */
/*   Updated: 2023/09/15 04:34:27 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error\nNeed a map.\n");
		exit(1);
	}
	check_name(argv[1]);
	game = game_generate();
	if (game == NULL)
		error_message("Fail malloc.\n", game);
	start_game(game, argv[1]);
	mlx_hook(game->win_ptr, X_EVENT_KEY_PRESS, 0, &press_key, game);
	mlx_hook(game->win_ptr, X_EVENT_KEY_EXIT, 0, &quit_game, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}

void	error_message(char *str, t_game *game)
{
	int	i;

	if (game != NULL)
	{
		if (game->map != NULL)
		{
			i = -1;
			while (++i < (int)game->height)
				free(game->map[i]);
			free(game->map);
		}
		if (game->copy != NULL)
		{
			i = -1;
			while (++i < (int)game->height)
				free(game->copy[i]);
			free(game->copy);
		}
		free(game);
	}
	ft_printf("Error\n%s", str);
	exit(1);
}

t_game	*game_generate(void)
{
	t_game	*node;

	node = malloc(sizeof(t_game));
	if (node == NULL)
		return (NULL);
	node->all_col = 0;
	node->collectible = 0;
	node->copy = NULL;
	node->height = 0;
	node->map = NULL;
	node->mlx_ptr = NULL;
	node->move = 0;
	node->pos_x = 0;
	node->pos_y = 0;
	node->width = 0;
	node->win_ptr = NULL;
	return (node);
}
