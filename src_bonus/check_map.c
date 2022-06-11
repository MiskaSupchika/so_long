/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:42:03 by rburner           #+#    #+#             */
/*   Updated: 2022/06/10 22:05:39 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	empty_line(char **av, t_map *map)
{
	int		fd;
	char	*ln;
	int		i;

	i = 0;
	fd = open (av[1], O_RDONLY);
	while (1)
	{
		ln = get_next_line(fd);
		if (!ln)
			break ;
		i++;
		free(ln);
	}
	if (i != map->width)
		ft_err ("empty lines\n");
	close (fd);
}

void	unacceptable_symbols(t_map *map)
{	
	int		i;
	int		j;
	char	*s;

	s = "01CEPN";
	i = 0;
	while (map->map[i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (!ft_strchr(s, map->map[i][j]))
				ft_err("Unacceptable symbols");
		}
		i++;
	}
	i = 0;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != map->height)
			ft_err(" map isn't");
		i++;
	}
}

void	check_characters(t_map *map, int i, int j)
{
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
				position_player(map, i, j);
			else if (map->map[i][j] == 'C')
				map->game_point++;
			else if (map->map[i][j] == 'E')
				map->exit++;
			else if (map->map[i][j] == 'N')
				position_enemy(map, i, j);
			j++;
		}
		i++;
	}
	if (map->player.player_position != 1)
		ft_err("the player must have one position");
	if (map->game_point == 0)
		ft_err("collectible is not found");
	if (map->exit != 1)
		ft_err("there must be one exit on the map");
}

void	walls(t_map *map, int i, int j)
{
	while (map->map[0][j])
	{
		if (map->map[0][j] != '1')
			ft_err("the map must have walls");
		j++;
	}
	j = 0;
	while (map->map[map->width - 1][j])
	{
		if (map->map[map->width - 1][j] != '1')
			ft_err("the map must have walls");
		j++;
	}
	j = 0;
	while (map->map[i][j] && i < map->width - 1)
	{
		if (map->map[i][0] != '1')
			ft_err("the map must have walls");
		else if (map->map[i][map->height - 1] != '1')
			ft_err("the map must have walls");
		i++;
	}
}

void	check_map(t_map *map, char **av)
{
	appropriation(map);
	unacceptable_symbols(map);
	empty_line(av, map);
	check_characters(map, 0, 0);
	walls(map, 0, 0);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, 64 * map->width,
			64 * map->height, "so_long");
	memory_texture(map);
	init_images(map);
	draw(map);
	mlx_key_hook(map->win, key_press, map);
	mlx_hook(map->win, 17, 0, close_x, map);
	init_images(map);
	draw(map);
	mlx_loop(map->mlx);
	free_map(map);
}
