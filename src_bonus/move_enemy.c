/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:26:45 by rburner           #+#    #+#             */
/*   Updated: 2022/06/11 04:28:20 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	left_enemy(t_map *map)
{
	if (map->map[map->enemy.pos_y][map->enemy.pos_x - 1] == '0')
	{
		map->map[map->enemy.pos_y][map->enemy.pos_x - 1] = 'N';
		map->map[map->enemy.pos_y][map->enemy.pos_x] = '0';
		map->enemy.pos_x--;
	}
	else if (map->map[map->enemy.pos_y][map->enemy.pos_x - 1] == 'C')
	{
		map->map[map->enemy.pos_y][map->enemy.pos_x - 1] = 'C';
		map->map[map->enemy.pos_y][map->enemy.pos_x] = 'N';
	}
	else if (map->map[map->enemy.pos_y][map->enemy.pos_x - 1] == '1')
	{
		map->map[map->enemy.pos_y][map->enemy.pos_x - 1] = '1';
		map->map[map->enemy.pos_y][map->enemy.pos_x] = 'N';
	}
	else if (map->map[map->enemy.pos_y][map->enemy.pos_x - 1] == 'P')
		end_game(map);
	// if (map->game.enemy == map->game.enemy1)
	// 	map->game.enemy = map->game.enemy2;
}

void	right_enemy(t_map *map)
{
	if (map->map[map->enemy.pos_y][map->enemy.pos_x + 1] == '0')
	{
		map->map[map->enemy.pos_y][map->enemy.pos_x + 1] = 'N';
		map->map[map->enemy.pos_y][map->enemy.pos_x] = '0';
		map->enemy.pos_x++;
	}
	else if (map->map[map->enemy.pos_y][map->enemy.pos_x + 1] == 'C')
	{
		map->map[map->enemy.pos_y][map->enemy.pos_x + 1] = 'C';
		map->map[map->enemy.pos_y][map->enemy.pos_x] = 'N';
	}
	else if (map->map[map->enemy.pos_y][map->enemy.pos_x + 1] == '1')
	{
		map->map[map->enemy.pos_y][map->enemy.pos_x + 1] = '1';
		map->map[map->enemy.pos_y][map->enemy.pos_x] = 'N';
	}
	else if (map->map[map->enemy.pos_y][map->enemy.pos_x + 1] == 'P')
		end_game(map);
	//map->game.enemy = map->game.enemy2;
}

void	up_enemy(t_map *map)
{
	if (map->map[map->enemy.pos_y + 1][map->enemy.pos_x] == '0')
	{
		map->map[map->enemy.pos_y + 1][map->enemy.pos_x] = 'N';
		map->map[map->enemy.pos_y][map->enemy.pos_x] = '0';
		map->enemy.pos_y++;
	}
	else if (map->map[map->enemy.pos_y + 1][map->enemy.pos_x] == 'C')
	{
		map->map[map->enemy.pos_y + 1][map->enemy.pos_x] = 'C';
		map->map[map->enemy.pos_y][map->enemy.pos_x] = 'N';
	}
	else if (map->map[map->enemy.pos_y + 1][map->enemy.pos_x] == '1')
	{
		map->map[map->enemy.pos_y + 1][map->enemy.pos_x] = '1';
		map->map[map->enemy.pos_y][map->enemy.pos_x] = 'N';
	}
	else if (map->map[map->enemy.pos_y + 1][map->enemy.pos_x] == 'P')
		end_game(map);
	//map->game.enemy = map->game.enemy1;
}

void	down_enemy(t_map *map)
{
	if (map->map[map->enemy.pos_y - 1][map->enemy.pos_x] == '0')
	{
		map->map[map->enemy.pos_y - 1][map->enemy.pos_x] = 'N';
		map->map[map->enemy.pos_y][map->enemy.pos_x] = '0';
		map->enemy.pos_y--;
	}
	else if (map->map[map->enemy.pos_y - 1][map->enemy.pos_x] == 'C')
	{
		map->map[map->enemy.pos_y - 1][map->enemy.pos_x] = 'C';
		map->map[map->enemy.pos_y][map->enemy.pos_x] = 'N';
	}
	else if (map->map[map->enemy.pos_y - 1][map->enemy.pos_x] == '1')
	{
		map->map[map->enemy.pos_y - 1][map->enemy.pos_x] = '1';
		map->map[map->enemy.pos_y][map->enemy.pos_x] = 'N';
	}
	else if (map->map[map->enemy.pos_y - 1][map->enemy.pos_x] == 'P')
		end_game(map);
	//map->game.enemy = map->game.enemy2;
}
