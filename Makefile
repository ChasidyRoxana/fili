# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: croxana <croxana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:37:56 by croxana           #+#    #+#              #
#    Updated: 2019/06/04 12:01:10 by croxana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

OBJ = $(patsubst %.c,%.o,$(wildcard *.c))

FLAG = -Wall -Wextra -Werror

INCLUDES = ./includes

LIBFT_OBJ = $(patsubst %.c,%.o,$(wildcard ./libft/*.c))

LIBFT = libft.a

all: $(NAME)

$(LIBFT): $(LIBFT_OBJ)
			ar rc $(LIBFT) $(LIBFT_OBJ)
			ranlib $(LIBFT)

$(NAME): $(LIBFT) $(OBJ)
		gcc $(FLAG) -I$(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT)

clean:
		rm -f *.o *.a ./libft/*.o

fclean: clean
		rm -f $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader main.c read.c solve.c print.c 

nor:
	norminette main.c read.c solve.c print.c ./includes/array.h ./includes/fillit.h ./includes/libft.h