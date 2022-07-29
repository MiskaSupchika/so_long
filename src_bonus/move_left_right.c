/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:05:06 by rburner           #+#    #+#             */
/*   Updated: 2022/06/07 15:05:44 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	step_left(t_map *map)
{
	map->map[map->player.pos_y][map->player.pos_x - 1] = 'P';
	map->map[map->player.pos_y][map->player.pos_x] = '0';
	map->player.pos_x--;
}

void	step_right(t_map *map)
{
	map->map[map->player.pos_y][map->player.pos_x + 1] = 'P';
	map->map[map->player.pos_y][map->player.pos_x] = '0';
	map->player.pos_x++;
}

void	left(t_map *map)
{
	if (map->map[map->player.pos_y][map->player.pos_x - 1] == '0')
		step_left(map);
	else if (map->map[map->player.pos_y][map->player.pos_x - 1] == 'C')
	{
		step_left(map);
		map->game_point--;
	}
	else if (map->map[map->player.pos_y][map->player.pos_x - 1] == '1')
	{
		map->map[map->player.pos_y][map->player.pos_x - 1] = '1';
		map->map[map->player.pos_y][map->player.pos_x] = 'P';
	}
	else if (map->map[map->player.pos_y][map->player.pos_x - 1] == 'N')
		end_game();
	else if (map->map[map->player.pos_y][map->player.pos_x - 1] == 'E'
		&& map->game_point == 0)
		end_game();
	map->score++;
	right_enemy(map);
}

void	right(t_map *map)
{
	if (map->map[map->player.pos_y][map->player.pos_x + 1] == '0')
		step_right(map);
	else if (map->map[map->player.pos_y][map->player.pos_x + 1] == 'C')
	{
		step_right(map);
		map->game_point--;
	}
	else if (map->map[map->player.pos_y][map->player.pos_x + 1] == '1')
	{
		map->map[map->player.pos_y][map->player.pos_x + 1] = '1';
		map->map[map->player.pos_y][map->player.pos_x] = 'P';
	}
	else if (map->map[map->player.pos_y][map->player.pos_x + 1] == 'N')
		end_game();
	else if (map->map[map->player.pos_y][map->player.pos_x + 1] == 'E'
		&& map->game_point == 0)
		end_game();
	left_enemy(map);
	map->score++;
}
