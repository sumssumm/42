/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 05:20:21 by suminpar          #+#    #+#             */
/*   Updated: 2023/09/16 13:58:41 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	save_image(t_game *game)
{
	int		w;
	int		h;
	t_image	image;

	image.chara = mlx_xpm_file_to_image(game->mlx_ptr, \
										"images/chara.xpm", &w, &h);
	image.col = mlx_xpm_file_to_image(game->mlx_ptr, \
										"images/col.xpm", &w, &h);
	image.end = mlx_xpm_file_to_image(game->mlx_ptr, \
										"images/end.xpm", &w, &h);
	image.tile = mlx_xpm_file_to_image(game->mlx_ptr, \
										"images/tile.xpm", &w, &h);
	image.wall = mlx_xpm_file_to_image(game->mlx_ptr, \
										"images/wall.xpm", &w, &h);
	if (image.chara == NULL || image.col == NULL || image.end == NULL \
		|| image.tile == NULL || image.wall == NULL)
		error_message("Fail mlx_xpm_file_to_image.\n", game);
	return (image);
}

void	map_image(t_game *game, int w, int h)
{
	if (game->map[h][w] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
								game->image.wall, w * 64, h * 64);
	else if (game->map[h][w] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
								game->image.col, w * 64, h * 64);
	else if (game->map[h][w] == 'P')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
								game->image.chara, w * 64, h * 64);
		game->pos_x = w;
		game->pos_y = h;
	}
	else if (game->map[h][w] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
								game->image.end, w * 64, h * 64);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
								game->image.tile, w * 64, h * 64);
}

void	put_image(t_game *game)
{
	size_t	w;
	size_t	h;

	h = 0;
	while (h < game->height)
	{
		w = 0;
		while (w < game->width)
		{
			map_image(game, w, h);
			w++;
		}
		h++;
	}
}
