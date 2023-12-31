# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvilchez <pvilchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 13:11:53 by pvilchez          #+#    #+#              #
#    Updated: 2023/09/21 10:28:37 by pvilchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc -c
LIB = ar rcs
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -rf

OBJ_PATH = obj
SRC_PATH = src
INC_PATH = include

HEADERS = -I ./include

SRC_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c\
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c\
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c\
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\
		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
		ft_lstlast.c ft_lstnew.c ft_lstsize.c\
		ft_itoa_long.c ft_printf.c ft_print_hex_cap.c ft_print_hex_long.c\
		ft_print_hex.c ft_print_int.c ft_print_str.c ft_print_unsig_int.c\
		ft_print_void.c\
		ft_get_next_line.c ft_get_next_line_utils.c\
		ft_free_lst.c

SRC := $(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

ORANGE = \033[1;38;5;208m
RESET = \033[0m
U_LINE = \033[4m
YELLOW = \033[1;38;5;226m

all: $(NAME)

$(NAME): $(OBJ)
	@$(LIB) $(NAME) $(OBJ)
	@echo "\n$(ORANGE)$(U_LINE)$(NAME): Compiled$(RESET) \n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@echo "$(YELLOW)$(NAME) Compiling:$(RESET) $(notdir $<)"

clean:
	$(REMOVE) $(OBJ_PATH)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re