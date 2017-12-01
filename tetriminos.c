/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:12:26 by aperesso          #+#    #+#             */
/*   Updated: 2017/10/05 18:35:25 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

int				count_tetriminos(char **s_map)
{
	int				nmb_points;

	nmb_points = 0;
	while (*s_map)
	{
		nmb_points++;
		s_map++;
	}
	return (nmb_points);
}

t_coordinate	**add_points(char **s_map, int t)
{
	t_coordinate	**t_p;
	int				i;
	int				j;
	int				k;

	i = -1;
	if (!(t_p = (t_coordinate **)malloc(sizeof(t_coordinate*) * t)))
		return (NULL);
	while (++i < t)
	{
		if (!(t_p[i] = (t_coordinate *)malloc(sizeof(t_coordinate) * 4)))
			return (NULL);
		j = -1;
		k = -1;
		while (s_map[i][++j])
			if (s_map[i][j] == '#')
			{
				k++;
				t_p[i][k].x = j % 5;
				t_p[i][k].y = j / 5;
			}
		if (!(verify_tetriminos(t_p[i])))
			return ((t_coordinate **)error());
	}
	return (t_p);
}

int				verify_tetriminos(t_coordinate *t_p)
{
	int		i;
	int		j;
	int		touch;

	i = -1;
	touch = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if ((t_p[i].x + 1 == t_p[j].x && t_p[i].y == t_p[j].y)
			|| (t_p[i].x == t_p[j].x && t_p[i].y + 1 == t_p[j].y)
			|| (t_p[i].x - 1 == t_p[j].x && t_p[i].y == t_p[j].y)
			|| (t_p[i].x == t_p[j].x && t_p[i].y - 1 == t_p[j].y))
				touch++;
	}
	if (touch < 6)
		return (0);
	return (1);
}

t_triminos		*add_tetriminos(char **s_map, int t)
{
	t_triminos		*t_tri;
	t_coordinate	**t_p;
	int				i;

	i = -1;
	if ((t_p = add_points(s_map, t)))
	{
		if (!(t_tri = (t_triminos *)malloc(sizeof(t_triminos) * t)))
			return (NULL);
		while (++i < t)
		{
			t_tri[i].pos = t_p[i];
			t_tri[i].letter = 'A' + i;
		}
		return (move_top_left(t_tri, t));
	}
	return (NULL);
}

t_triminos		*move_top_left(t_triminos *tetri, int nmb_p)
{
	t_coordinate	*ft_move;
	t_coordinate	space;
	int				j;

	while (--nmb_p > -1)
	{
		j = -1;
		if (!(ft_move = (t_coordinate *)malloc(sizeof(t_coordinate) * 4)))
			return (NULL);
		ft_move = tetri[nmb_p].pos;
		space = ft_move[0];
		while (++j < 4)
		{
			space.x = (ft_move[j].x < space.x) ? ft_move[j].x : space.x;
			space.y = (ft_move[j].y < space.y) ? ft_move[j].y : space.y;
		}
		j = -1;
		while (++j < 4)
		{
			ft_move[j].x -= space.x;
			ft_move[j].y -= space.y;
		}
		tetri[nmb_p].pos = ft_move;
	}
	return (tetri);
}
