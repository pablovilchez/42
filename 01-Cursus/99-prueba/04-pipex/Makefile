# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 21:49:44 by pvilchez          #+#    #+#              #
#    Updated: 2023/09/13 22:00:59 by pvilchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FILES = pipex.c pipex_utils.c

OBJECTS = $(FILES:.c=.o)

LIBFT_PATH = libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)
	gcc $(FLAGS) -o pipex_lib.h $(NAME)

$(NAME): $(LIBFT_PATH) $(OBJECTS)
	cp $(LIBFT_PATH) $(NAME)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(FILES)
	gcc $(FLAGS) -c $(FILES)

$(LIBFT_PATH):
	make -C libft/ all

clean:
	make -C libft/ clean
	rm -f $(OBJECTS)

fclean:
	make -C libft/ fclean
	rm -f $(OBJECTS)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re main create exe