# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 20:09:10 by pvilchez          #+#    #+#              #
#    Updated: 2023/07/11 11:31:58 by pvilchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIB = libftpushswap.a

FILES = push_swap.c push_swap_test.c lst_actions.c error_arg_check.c\
		lst_print_stacks.c lst_print_structs.c lst_fill_stats.c lst_sort_plus.c\
		lst_fill_index.c lst_sort_plus_aux.c main.c

OBJECTS = $(FILES:.c=.o)

LIBFT_PATH = libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT_PATH) $(OBJECTS)
	cp $(LIBFT_PATH) $(LIB)
	ar rcs $(LIB) $(OBJECTS)
	gcc $(FLAGS) -o $(NAME) $(LIB)

$(LIBFT_PATH):
	make -C libft/ all

clean:
	make -C libft/ clean
	rm -f $(OBJECTS)

fclean:
	make -C libft/ fclean
	rm -f $(OBJECTS)
	rm -f $(NAME)
	rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re main create exe