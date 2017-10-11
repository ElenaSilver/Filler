# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 00:51:37 by eserebry          #+#    #+#              #
#    Updated: 2017/10/11 01:22:19 by eserebry         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

FLAGS = -Wall -Wextra -Werror -Ofast
CC = gcc

SRC = calc_weight.c\
	filler.c\
	find.c\
	put_piece.c\
	read_map_and_piece.c

LIBFT = libft/libft.a
FT_PRINTF = libft/ft_printf/libftprintf.a

OBJ = $(SRCS:.c=.o)
 
SRCDIR = srcs
OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))

HEADER = filler.h

RM = rm -rf

GREEN = \033[32m
RED = \033[31m

all: $(NAME)


$(NAME):$(OBJ)
		@make -C libft
		@make -C libft/ft_printf
		@$(CC) -o $(NAME) $(SRCS) $(FLAG) $(LIBFT) $(FT_PRINTF)
		@echo "$(GREEN)filler: creating object files"

clean: 
		@/bin/$(RM) $(OBJ)
		@make -C libft clean
		@make -C libft/ft_printf clean

fclean: clean
		@make -C libft fclean
		@make -C libft/ft_printf fclean
		@/bin/$(RM) $(NAME)
		@echo "$(RED)filler: deleting object files"

re: fclean all

.PHONY: all clean fclean re
.SUFFIXES: .c .o
