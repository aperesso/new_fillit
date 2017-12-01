/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:59:17 by aperesso          #+#    #+#             */
/*   Updated: 2017/05/09 13:17:54 by apieczyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_coordinate
{
	int x;
	int y;
}					t_coordinate;
typedef struct		s_triminos
{
	t_coordinate	*pos;
	char			letter;
}					t_triminos;
char				**read_sample(int ac, char **av);
char				**error(void);
int					check_sample(char *buf);
char				**sample_map(char *buf, int number_of_pieces);
int					count_tetriminos(char **s_map);
t_coordinate		**add_points(char **s_map, int nmb_tetriminos);
int					verify_tetriminos(t_coordinate *tab);
t_triminos			*add_tetriminos(char	**s_map, int t);
char				**init_map(int t);
t_triminos			*move_top_left(t_triminos *tetri, int nmb_p);
int					display_map(char **ft_map);
int					size_map(int nb_tetri);
int					ft_sqrt(int nb);
void				resolve(t_triminos *tetri, int max);
int					recursive(t_triminos *t, char **m, int max, int n);
int					add_tetri(char **map, int y_map, int x_map,
													t_triminos trimino);
void				delete_tetri(char **map, t_triminos t);
void				ft_putstr(char *str);
void				ft_strdel(char **as);
size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);
void				ft_putchar(char c);
void				*ft_memset(void *b, int c, size_t len);

#endif
