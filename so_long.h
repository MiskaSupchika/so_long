/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 02:48:45 by rburner           #+#    #+#             */
/*   Updated: 2022/01/12 06:04:02 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include "minilibx_linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdbool.h>

//# define LEFT 0 
//# define LEFT 123
# define LEFT 97
//# define LEFT 65361
//# define RIGHT 2
//# define RIGHT 124
# define RIGHT 100
//# define RIGHT 65363

typedef struct s_key
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	bool	exit;
}			t_key;

typedef struct s_texture
{
	void	*texture;
	int		width;
	int		height;	
}			t_texture;

typedef struct s_game
{
	t_texture	*wall;
	t_texture	*floor;
	t_texture	*colectible;
	t_texture	*exit;
	t_texture	*enemy1;
	t_texture	*enemy2;
	t_texture	*player;
	t_texture	*player2;
	t_texture	*player3;
	t_texture	*enemy;
}			t_game;

typedef struct s_enemy
{
	int	enemy_position;
	int	pos_x;
	int	pos_y;
}			t_enemy;

typedef struct s_player
{
	int	player_position;
	int	pos_x;
	int	pos_y;
}			t_player;

typedef struct s_map
{
	void		*mlx;
	void		*win;
	char		**map;
	char		*map_line;
	int			score;
	int			height;
	int			exit;
	int			width;
	int			game_point;
	t_enemy		enemy;
	t_player	player;
	t_game		game;
	t_key		key;
}			t_map;

void	left_enemy(t_map *map);
void	right_enemy(t_map *map);
void	up_enemy(t_map *map);
void	down_enemy(t_map *map);
void	move_enemy(t_map *map);
void	position_enemy(t_map *map, int i, int j);
void	animation_enemy(t_map *map);
void	*draw_player(t_map *map);

void	empty_line(char **av, t_map *map);
void	unacceptable_symbols(t_map *map);
void	check_characters(t_map *map, int i, int j);
void	walls(t_map *map, int i, int j);
void	check_map(t_map *map, char **av);
void	memory_texture(t_map *map);

int		close_x(t_map *map);
int		key_press(int key, t_map *map);
int		key_release(int key, t_map *map);
int		drawing(t_map *map);

int		close_win(int key);

void	left(t_map *map);
void	right(t_map *map);
void	up(t_map *map);
void	down(t_map *map);

void	ft_err(char *str);
void	appropriation(t_map *map);

int		draw(t_map *map);
void	init_images(t_map *map);

void	position_player(t_map *map, int i, int j);
void	position_enemy(t_map *map, int i, int j);
void	free_map(t_map *map);
int		ft_strcmp(const char *str1, const char *str2);
void	end_game(void);

#endif 