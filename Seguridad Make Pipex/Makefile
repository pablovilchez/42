# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 21:49:44 by pvilchez          #+#    #+#              #
#    Updated: 2023/09/14 14:20:55 by pvilchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc -c
FLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast

FILES = pipex.c pipex_utils.c
OBJECTS = $(FILES:.c=.o)
LIBFT_PATH = libft/libft.a

all: $(LIBFT_PATH) $(NAME)

$(LIBFT_PATH):
	make -C libft/

$(NAME): $(OBJECTS)
	gcc $(OBJECTS) $(LIBFT_PATH) -o $(NAME)
	@echo "aaaaaaaaaaaaaaaaaaa"

$(OBJECTS):
	$(CC) $(FLAGS) -c $(FILES)

clean:
	make -C libft/ clean
	rm -f $(OBJECTS)

fclean:
	make -C libft/ fclean
	rm -f $(OBJECTS)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re main create exe
