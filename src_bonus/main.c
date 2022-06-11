/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburner <rburner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 06:15:00 by rburner           #+#    #+#             */
/*   Updated: 2022/06/10 22:05:22 by rburner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_err(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}

void	appropriation(t_map *map)
{
	int	i;

	map->exit = 0;
	map->game_point = 0;
	map->player.player_position = 0;
	map->height = ft_strlen(map->map[0]);
	map->score = 0;
	map->enemy.enemy_position = 0;
	i = 0;
	while (map->map[i])
		i++;
	map->width = i;
}

char	*read_map(char **av)
{
	int		i;
	int		fd;
	char	*line;
	char	*all_line;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_err("file didn't open");
	all_line = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		all_line = ft_strjoin(all_line, line);
		free(line);
	}
	close(fd);
	return (all_line);
}

int	check_name_map(char *name)
{
	int	length;

	length = ft_strlen(name);
	if (length < 5)
		return (1);
	if (ft_strcmp((name + length - 4), ".ber"))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2 || check_name_map(av[1]))
		ft_err("Invalid arguments\n");
	map.map_line = read_map(av);
	map.map = ft_split(map.map_line, '\n');
	check_map(&map, av);
	return (0);
}
