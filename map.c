/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 01:45:34 by aperesso          #+#    #+#             */
/*   Updated: 2017/04/24 12:55:28 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

int		ft_sqrt(int nb)
{
	int x;

	x = 1;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (x * x < nb)
		x++;
	return (x);
}

char	**init_map(int t)
{
	char	**ft_map;
	int		i;
	int		j;

	i = -1;
	if (!(ft_map = (char **)malloc(sizeof(char *) * (t + 1))))
		return (NULL);
	while (++i < t)
	{
		if (!(ft_map[i] = (char *)malloc(sizeof(char ) * (t + 1))))
			return (NULL);
		j = -1;
		while (++j < t)
			ft_map[i][j] = '.';
		ft_map[i][j] = '\0';
	}
	return (ft_map);
}

int		display_map(char **ft_map)
{
	int	i;

	i = -1;
	while (ft_map[++i])
	{
		ft_putstr(ft_map[i]);
		ft_putstr("\n");
	}
	ft_strdel(ft_map);
	return (1);
}

int		size_map(int nb_tetri)
{
	return (ft_sqrt(nb_tetri));
}
