/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:53:37 by aperesso          #+#    #+#             */
/*   Updated: 2017/10/05 18:35:42 by aperesso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

char	**error(void)
{
	ft_putstr("error\n");
	return (NULL);
}

int		main(int ac, char **av)
{
	char		**s_map;
	t_triminos	*pieces;
	int			nmb_pieces;

	s_map = read_sample(ac, av);
	if (!s_map)
		return (0);
	nmb_pieces = count_tetriminos(s_map);
	if (!(pieces = add_tetriminos(s_map, nmb_pieces)))
		return (0);
	resolve(pieces, nmb_pieces);
	return (0);
}
