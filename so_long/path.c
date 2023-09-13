#include "so_long.h"

void	check_path(t_game *game)
{
	size_t	x;
	size_t	y;

	duplicate_map(game);
	y = 0;
	x = 0;
	printf("%zu %zu\n", x, y);
	while (y < game->height)
	{
		x = 0;
			printf("%zu %zu\n", x, y);

		while (x < game->width)
		{
				printf("%zu %zu\n", x, y);

			if (game->copy[y][x] == 'P')
				dfs(game, x, y);
			x++;
		}
		y++;
	}
	error_path(game);
}
//free
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
				error_message("Invalid path.\n");
			x++;
		}
		y++;
	}
}

void	dfs(t_game *game, size_t x, size_t y)
{
	if ((x < 0 || game->width <= x || y < 0 || game->height <= y))
		return ;
	if (game->copy[y][x] == 'E')
		return ;
	game->copy[y][x] = '1';
	dfs(game, x - 1, y);
	dfs(game, x + 1, y);
	dfs(game, x, y - 1);
	dfs(game, x, y + 1);
	game->copy[y][x] = '0';
	return ;
}

void	duplicate_map(t_game *game)
{
	size_t	i;

	i = 0;
	game->copy = malloc(sizeof(char *) * game->height);
	while (i < game->height)
	{
		game->copy[i] = ft_strdup(game->map[i]);
		printf("%s", game->copy[i]);

		i++;
	}
}
