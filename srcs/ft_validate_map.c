/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:00:19 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/09 18:06:23 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int		ft_magic_map(int x, int y, int map_height, char **map)
{
	int		n;
	int		s;
	int		w;
	int		e;

	if (y < 0 || x < 0 || y > map_height || map[y][x] == ' ' || map[y][x] == '\0')
		return 0;
	else if (map[y][x] == '1' || map[y][x] == '.')
		return 1;
	map[y][x] = '.';
	n = ft_magic_map(x, y - 1, map_height, map);
	s = ft_magic_map(x, y + 1, map_height, map);
	w = ft_magic_map(x - 1, y, map_height, map);
	e = ft_magic_map(x + 1, y, map_height, map);
	return (n && s && w && e);
}

static	int		ft_check_around(char **map, int y, int x)
{
	if (y - 1 < 0 || map[y - 1][x] == ' ' || x + 1 > (int)ft_strlen(map[y - 1]))
		return (-1);
	if (!map[y + 1]|| map[y + 1][x] == ' ' || x + 1 > (int)ft_strlen(map[y + 1]))
		return (-1);
	if (x - 1 < 0 || map[y][x - 1] == ' ')
		return (-1);
	if (!map[y][x + 1] || map[y][x + 1] == ' ')
		return (-1);
	return (0);
}

static	int		ft_check(char **map)
{
	int	count_players;
	int	i;
	int	j;

	count_players = 0;
	i = -1;
	while (map[++i])
	{
		if (map[i][0] == '\0')
			return (-1);
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
			|| map[i][j] == 'E')
				count_players++;
			else if (map[i][j] == '0' || map[i][j] == '2')
				if (ft_check_around(map, i, j) < 0)
					return (-5);
		}
	}
	if (count_players > 1 || !count_players)
		return (-5);
	return (0);
}

int				ft_validate_map(t_all **all, char **map)
{
	char 	**new_map;
	int		i;

	i = -1;
	(*all)->map_norme.height = 0;
	while (map[(*all)->map_norme.height])
		((*all)->map_norme.height)++;
	if (!(new_map = (char **)malloc(((*all)->map_norme.height + 1) * sizeof(char *))))
		return (-5);
	while (map[++i])
		if (!(new_map[i] = ft_strdup(map[i])))
			return (-5);
	new_map[i] = NULL;
	if (ft_check(map) < 0)
		return (-5);
	if (ft_magic_map((*all)->player.x - 0.5, (*all)->player.y - 0.5,
		(*all)->map_norme.height, new_map) == 0)
		return (-5);
	i = -1;
	while (new_map[++i])
		free(new_map[i]);
	free(new_map);
	return (0);
}