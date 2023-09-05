/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:38:03 by suminpar          #+#    #+#             */
/*   Updated: 2023/09/05 22:05:40 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_name(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len > 4)
	{
		if (filename[len - 1] == 'r' && filename[len - 2] == 'e' \
			&& filename[len - 3] == 'b' && filename[len - 4] == '.' \
			&& filename[len - 5] != '.')
			return ;
		else
			error_message("Invalid map name.\n");
	}
	else
		error_message("Invalid map name.\n");
}

void	check_file(int fd, char *filename)
{
	int		byte;
	char	file[1];

	if (fd <= 0)
		error_message("Unable to open map.\n");
	byte = read(fd, file, 1);
	if (byte != 1)
	{
		close(fd);
		error_message("Empty map.\n");
	}
	close(fd);
	fd = open(filename, O_RDONLY);
}

void	check_wall(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(game->line))
	{
		if (i < game->width)
		{
			if (game->line[i] != '1')
				error_message("Invalid wall.\n");
		}
		else if (i % game->width == 0 || \
				i % game->width == game->width - 1)
		{
			if (game->line[i] != '1')
				error_message("Invalid wall.\n");
		}
		else if (i > ft_strlen(game->line) - game->width)
		{
			if (game->line[i] != '1')
				error_message("Invalid wall.\n");
		}
		i++;
	}
}

void	check_component(t_game *game)
{
	size_t	i;
	int		exit;
	int		pos;

	i = 0;
	exit = 0;
	pos = 0;
	game->collectible = 0;
	game->all_col = 0;
	while (i < ft_strlen(game->line))
	{
		if (game->line[i] == 'E')
			exit++;
		else if (game->line[i] == 'P')
			pos++;
		else if (game->line[i] == 'C')
			game->all_col++;
		i++;
	}
	if (exit != 1)
		error_message("Invalid exit.\n");
	if (pos != 1)
		error_message("Invalid character.\n");
	if (game->all_col < 1)
		error_message("Invalid collectible.\n");
}

// void	check_path(t_game *game)
// {
	
// }