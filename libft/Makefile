# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 21:47:23 by eserebry          #+#    #+#              #
#    Updated: 2017/10/11 00:57:09 by eserebry         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -c -I -fsanitize=address

INCLUDES =	"includes"

FUNCTION = atoi isdigit memalloc memdel memcmp memcpy memmove memset strchr \
strdup strjoin strlen strsub strnew strcat strcpy strsplit strstr get_next_line\
putendl putchar putstr strcmp

FT_FUNCTION = $(addprefix ft_, $(FUNCTION))
SRC = $(addsuffix .c, $(FT_FUNCTION))

OBJ = $(SRC:.c=.o)

RM = rm -f

GREEN = \033[32m
RED = \033[31m

all: $(NAME)

$(NAME): 
		@gcc $(FLAGS) $(SRC)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "$(GREEN)libft: creating object files"


$(COMPILED): @%.o: %.c
		@$(CC) $(FLAGS) $< -o $@ -I $(INCLUDES)

clean:
		@/bin/$(RM) $(OBJ)

fclean: clean
		@/bin/$(RM) $(NAME)
		@echo "$(RED)libft: deleting object files"

re: fclean all

.PHONY: all clean fclean re