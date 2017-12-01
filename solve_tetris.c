/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 01:12:10 by aperesso          #+#    #+#             */
/*   Updated: 2017/09/23 17:25:39 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

int		recursive(t_triminos *tetri, char **map, int max, int n)
{
	int		x;
	int		y;
	int		size;

	size = ft_strlen(map[0]);
	x = -1;
	if (n == max)
		return (1);
	y = size * size - 1;
	while (++x < y)
		if (add_tetri(map, x / size, x % size, tetri[n]))
		{
			if (recursive(tetri, map, max, n + 1))
			{
				display_map(map);
				return (1);
			}
			delete_tetri(map, tetri[n]);
		}
	return (0);
}

int		add_tetri(char **map, int y_map, int x_map, t_triminos trimino)
{
	int					i;
	int					max;
	t_coordinate		*coord;

	i = -1;
	max = 0;
	coord = trimino.pos;
	while (map[max])
		max++;
	while (++i < 4)
	{
		if (x_map + coord[i].x > max - 1 || y_map + coord[i].y > max - 1 ||
		map[coord[i].y + y_map][coord[i].x + x_map] != '.')
		{
			delete_tetri(map, trimino);
			return (0);
		}
		map[coord[i].y + y_map][coord[i].x + x_map] = trimino.letter;
	}
	return (1);
}

void	delete_tetri(char **map, t_triminos t)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = -1;
	while (map[i])
		i++;
	while (++y < i && map[y])
	{
		x = -1;
		while (++x < i && map[y][x])
			if (map[y][x] == t.letter)
				map[y][x] = '.';
	}
}

void	resolve(t_triminos *tetri, int max)
{
	int		s_map;
	int		solved;
	char	**map;

	s_map = ft_sqrt(max) - 1;
	solved = 0;
	if (max == 1)
	{
		map = init_map(4);
		add_tetri(map, 0, 0, *tetri);
		display_map(map);
	}
	else
	{
		while (!solved)
		{
			++s_map;
			solved = recursive(tetri, init_map(s_map), max, 0);
		}
	}
}
