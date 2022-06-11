/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:44:26 by rburner           #+#    #+#             */
/*   Updated: 2022/06/10 19:27:55 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	step_up(t_map *map)
{
	map->map[map->player.pos_y + 1][map->player.pos_x] = 'P';
	map->map[map->player.pos_y][map->player.pos_x] = '0';
	map->player.pos_y++;
}

void	step_down(t_map *map)
{
	map->map[map->player.pos_y - 1][map->player.pos_x] = 'P';
	map->map[map->player.pos_y][map->player.pos_x] = '0';
	map->player.pos_y--;
}

void	up(t_map *map)
{
	if (map->map[map->player.pos_y + 1][map->player.pos_x] == '0')
		step_up(map);
	else if (map->map[map->player.pos_y + 1][map->player.pos_x] == 'C')
	{
		step_up(map);
		map->game_point--;
	}
	else if (map->map[map->player.pos_y + 1][map->player.pos_x] == '1')
	{
		map->map[map->player.pos_y + 1][map->player.pos_x] = '1';
		map->map[map->player.pos_y][map->player.pos_x] = 'P';
	}
	else if (map->map[map->player.pos_y + 1][map->player.pos_x] == 'N')
		end_game(map);
	else if (map->map[map->player.pos_y + 1][map->player.pos_x] == 'E'
		&& map->game_point == 0)
		end_game(map);
	map->score++;
}

void	down(t_map *map)
{
	if (map->map[map->player.pos_y - 1][map->player.pos_x] == '0')
		step_down(map);
	else if (map->map[map->player.pos_y - 1][map->player.pos_x] == 'C')
	{
		step_down(map);
		map->game_point--;
	}
	else if (map->map[map->player.pos_y - 1][map->player.pos_x] == '1')
	{
		map->map[map->player.pos_y - 1][map->player.pos_x] = '1';
		map->map[map->player.pos_y][map->player.pos_x] = 'P';
	}
	else if (map->map[map->player.pos_y - 1][map->player.pos_x] == 'N')
		end_game(map);
	else if (map->map[map->player.pos_y - 1][map->player.pos_x] == 'E'
		&& map->game_point == 0)
		end_game(map);
	map->score++;
}
