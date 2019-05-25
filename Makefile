# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpepperm <tpepperm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:37:56 by croxana           #+#    #+#              #
#    Updated: 2019/05/25 15:13:53 by tpepperm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c read.c print.c solve.c

OBJ = main.o read.o print.o solve.o

FLAG = -Wall -Wextra -Werror

INCLUDES = ./includes

LIBFT_SRC = ./libft/*.c

LIBFT_OBJ = ./libft/*.o

LIBFT = libft.a

all: $(NAME)

$(LIBFT): $(LIBFT_SRC)
			gcc -c $(FLAG) $(LIBFT_SRC) -I$(INCLUDES)
			ar rc $(LIBFT) $(LIBFT_OBJ)
			ranlib $(LIBFT)

$(NAME): $(LIBFT) $(OBJ)
		gcc $(FLAG) -I$(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT)

clean:
		rm -f *.o *.a

fclean: clean
		rm -f $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader

nor:
	norminette