/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:40:38 by panda             #+#    #+#             */
/*   Updated: 2022/06/11 00:01:29 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_x(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	exit (0);
	return (1);
}

int	key_press(int key, t_map *map)
{
	if (key == 97 || key == 123 || key == 0 || key == 65361)
	{
		left(map);
		right_enemy(map);
	}
	else if (key == 100 || key == 125 || key == 2 || key == 65363)
	{
		right(map);
		left_enemy(map);
	}
	else if (key == 1 || key == 125 || key == 115 || key == 65364)
	{
		up(map);
		down_enemy(map);
	}
	else if (key == 13 || key == 126 || key == 119 || key == 65362)
	{
		down(map);
		up_enemy(map);
	}
	else if (key == 53 || key == 65307)
		exit (1);
	draw(map);
	return (0);
}

int	close_win(int key)
{
	printf("%d\n", key);
	if (key == 53 || key == 65307)
		exit (1);
	return (1);
}
