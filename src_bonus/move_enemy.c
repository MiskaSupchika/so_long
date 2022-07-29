/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:26:45 by rburner           #+#    #+#             */
/*   Updated: 2022/07/01 00:23:14 by rburner          ###   ########.fr       */
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
		end_game();
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
		end_game();
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
		end_game();
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
		end_game();
}

void	*draw_player(t_map *map)
{
	if (map->key.left)
		return (map->game.player2->texture);
	else if (map->key.right)
		return (map->game.player3->texture);
	return (map->game.player->texture);
}
