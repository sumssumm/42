/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminpar <suminpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:46:27 by suminpar          #+#    #+#             */
/*   Updated: 2023/09/05 22:05:49 by suminpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53

typedef struct s_image
{
	void	*chara;
	void	*col;
	void	*end;
	void	*tile;
	void	*wall;
}	t_image;

typedef struct s_check
{
	char	**visited;
} t_check;


typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	size_t	width;
	size_t	height;
	int		collectible;
	int		all_col;
	int		move;
	char	*line;
	char	**map;
	t_image	image;
}	t_game;

void	error_message(char *str);

void	start_game(t_game *game, char *map);
int		press_key(int key_code, t_game *game);
int		clear_game(t_game *game);
int		quit_game(t_game *game);

t_image	save_image(void *mlx_ptr);
void	map_image(t_game *game, int w, int h);
void	put_image(t_game *game);

void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);

void	check_name(char *filename);
void	check_file(int fd, char *filename);
void	check_wall(t_game *game);
void	check_component(t_game *game);
void	check_map(t_game *game);

void	read_map(t_game *game, char *mapfile);

#endif