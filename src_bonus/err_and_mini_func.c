/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_and_mini_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:29:13 by rburner           #+#    #+#             */
/*   Updated: 2022/07/01 00:23:55 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	position_player(t_map *map, int i, int j)
{
	map->player.player_position++;
	map->player.pos_x = j;
	map->player.pos_y = i;
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (map->map[++i])
		free(map->map[i]);
	free(map->map);
	free(map);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	position_enemy(t_map *map, int i, int j)
{
	map->enemy.enemy_position++;
	map->enemy.pos_x = j;
	map->enemy.pos_y = i;
}

void	end_game(void)
{
	write(1, "Game is over\n", 14);
	exit (0);
}
