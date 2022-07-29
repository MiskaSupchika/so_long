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
		map->key.left = 1;
		drawing(map);
	}
	else if (key == 100 || key == 125 || key == 2 || key == 65363)
	{
		map->key.right = 1;
		drawing(map);
	}
	else if (key == 1 || key == 125 || key == 115 || key == 65364)
	{
		map->key.up = 1;
		drawing(map);
	}
	else if (key == 13 || key == 126 || key == 119 || key == 65362)
	{
		map->key.down = 1;
		drawing(map);
	}
	else if (key == 53 || key == 65307)
		map->key.exit = 1;
	return (1);
}

int	key_release(int key, t_map *map)
{
	if (key == 97 || key == 123 || key == 0 || key == 65361)
	{
		map->key.left = 0;
	}
	else if (key == 100 || key == 125 || key == 2 || key == 65363)
	{
		map->key.right = 0;
	}
	else if (key == 1 || key == 125 || key == 115 || key == 65364)
	{
		map->key.up = 0;
	}
	else if (key == 13 || key == 126 || key == 119 || key == 65362)
	{
		map->key.down = 0;
	}
	return (1);
}

int	drawing(t_map *map)
{
	if (map->key.down || map->key.up || map->key.right || map->key.left
		|| map->key.exit)
	{
		if (map->key.left)
		{
			left(map);
		}
		else if (map->key.right)
		{
			right(map);
		}
		else if (map->key.up)
		{
			up(map);
		}
		else if (map->key.down)
		{
			down(map);
		}
		else if (map->key.exit)
			exit (1);
		mlx_clear_window(map->mlx, map->win);
		draw(map);
	}
	return (0);
}

int	close_win(int key)
{
	printf("%d\n", key);
	if (key == 53 || key == 65307)
		exit (1);
	return (1);
}
