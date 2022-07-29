/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:51:55 by rburner           #+#    #+#             */
/*   Updated: 2022/06/11 04:27:54 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_images(t_map *map)
{
	map->game.wall->texture = mlx_xpm_file_to_image(map->mlx,
			"./texture/wall.xpm", &map->game.wall->width,
			&map->game.wall->height);
	map->game.floor->texture = mlx_xpm_file_to_image(map->mlx,
			"./texture/black_floor.xpm", &map->game.floor->width,
			&map->game.floor->height);
	map->game.colectible->texture = mlx_xpm_file_to_image(map->mlx,
			"./texture/candy.xpm", &map->game.colectible->width,
			&map->game.colectible->height);
	map->game.player->texture = mlx_xpm_file_to_image(map->mlx,
			"./texture/player.xpm", &map->game.player->width,
			&map->game.player->height);
	map->game.exit->texture = mlx_xpm_file_to_image(map->mlx,
			"./texture/portal.xpm", &map->game.exit->width,
			&map->game.exit->height);
	map->game.enemy->texture = mlx_xpm_file_to_image(map->mlx,
			"./texture/fball.xpm", &map->game.enemy->width,
			&map->game.enemy->height);
	if (!map->game.wall->texture || !map->game.floor->texture
		|| !map->game.player->texture || !map->game.enemy->texture
		|| !map->game.colectible->texture || !map->game.exit->texture)
		ft_err("file not found");
}

void	animation_enemy(t_map *map)
{
	map->game.player2->texture = mlx_xpm_file_to_image(map->mlx,
			"./texture/play2.xpm", &map->game.enemy->width,
			&map->game.enemy->height);
	map->game.player3->texture = mlx_xpm_file_to_image(map->mlx,
			"./texture/play1.xpm", &map->game.enemy->width,
			&map->game.enemy->height);
	if (!map->game.player2->texture || !map->game.player3->texture)
		ft_err("file not found");
}

void	memory_texture(t_map *map)
{
	map->game.wall = malloc(sizeof(t_texture));
	map->game.floor = malloc(sizeof(t_texture));
	map->game.player = malloc(sizeof(t_texture));
	map->game.colectible = malloc(sizeof(t_texture));
	map->game.exit = malloc(sizeof(t_texture));
	map->game.enemy = malloc(sizeof(t_texture));
	map->game.player2 = malloc(sizeof(t_texture));
	map->game.player3 = malloc(sizeof(t_texture));
	if (!map->game.wall || !map->game.floor || !map->game.player
		|| !map->game.colectible || !map->game.exit || !map->game.enemy
		|| !map->game.player2 || !map->game.player3)
		ft_err("memory not found");
}

void	draw_texture(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->game.wall->texture,
			j * map->game.wall->height, i * map->game.wall->width);
	else if (map->map[i][j] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->game.floor->texture,
			j * map->game.floor->height, i * map->game.floor->width);
	else if (map->map[i][j] == 'P')
		mlx_put_image_to_window(map->mlx, map->win, draw_player(map),
			j * map->game.player->height, i * map->game.player->width);
	else if (map->map[i][j] == 'C')
		mlx_put_image_to_window(map->mlx, map->win,
			map->game.colectible->texture, j * map->game.colectible->height,
			i * map->game.colectible->width);
	else if (map->map[i][j] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->game.exit->texture,
			j * map->game.exit->height, i * map->game.exit->width);
	else if (map->map[i][j] == 'N')
		mlx_put_image_to_window(map->mlx, map->win, map->game.enemy->texture,
			j * map->game.enemy->height, i * map->game.enemy->width);
}

int	draw(t_map *map)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	mlx_clear_window (map->mlx, map->win);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			draw_texture(map, i, j);
			j++;
		}
	i++;
	}
	s = ft_itoa (map->score);
	mlx_string_put(map->mlx, map->win, 10, 10, 0xff00, "Score:");
	mlx_string_put(map->mlx, map->win, 75, 10, 0xff00, s);
	free(s);
	return (0);
}
