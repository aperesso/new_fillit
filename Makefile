# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperesso <aperesso@student.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/19 17:22:16 by aperesso          #+#    #+#              #
#*   Updated: 2017/05/11 21:26:15 by apieczyr         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME 	= fillit

HEADER 	= fillit.h

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror

SRCS 	= init.c\
		  ft_putstr.c\
		  ft_strdel.c\
		  ft_strlen.c\
		  ft_strnew.c\
		  ft_putchar.c\
		  ft_memset.c\
		  tetriminos.c\
		  solve_tetris.c\
		  map.c\
		  main.c

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): 
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

clean:
	/bin/rm -rf $(OBJECTS)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: clean
