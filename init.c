/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:51:23 by aperesso          #+#    #+#             */
/*   Updated: 2017/11/29 16:26:08 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

char	**read_sample(int ac, char **av)
{
	int		op;
	int		rd;
	int		pieces;
	char	buf[600];
	char	**s_map;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit required_input");
		return (NULL);
	}
	else
	{
		if ((op = open(av[1], O_RDONLY)) < 0)
			return (error());
		else
		{
			rd = read(op, buf, 599);
			buf[599] = '\0';
		}
		close(op);
	}
	if ((pieces = check_sample(buf)))
		return (s_map = sample_map(buf, pieces));
	return (NULL);
}

int		check_sample(char *buf)
{
	int		diez;
	int		point;
	int		s;
	int		i;

	diez = 0;
	point = 0;
	i = -1;
	s = ft_strlen(buf);
	while (buf[++i])
	{
		if (buf[i] == '#')
			diez++;
		else if (buf[i] == '.')
			point++;
		else if (buf[i] != '\n')
			return ((int)error());
		if (i % 21 == 19 && buf[i + 1] != '\n' && i != (int)ft_strlen(buf) - 1)
			return ((int)error());
	}
	if (diez % 4 != 0 || point != diez * 3 || s % 21 != 20)
		return ((int)error());
	return (diez / 4);
}

char	**sample_map(char *buf, int number_of_pieces)
{
	char	**mapped;
	int		i;
	int		j;

	i = -1;
	if (!(mapped = (char **)malloc(sizeof(char *) * (number_of_pieces + 1))))
		return (NULL);
	while (++i < number_of_pieces)
	{
		j = -1;
		while (*buf == '\n')
			buf++;
		mapped[i] = ft_strnew(20);
		while (++j < 20)
			mapped[i][j] = *buf++;
		mapped[i][j] = '\0';
	}
	mapped[i] = 0;
	return (mapped);
}
