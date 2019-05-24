# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: croxana <croxana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:37:56 by croxana           #+#    #+#              #
#    Updated: 2019/05/24 12:06:13 by croxana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c read.c print.c

FLAG = -Wall -Wextra -Werror

GNL = get_next_line.c get_next_line.h ft_memmove.c ft_strchr.c ft_strcdup.c \
	ft_strjoin.c ft_strlen.c ft_strnew.c solve.c ft_memset.c

all: $(NAME)

$(NAME): $(SRC)
		gcc $(FLAG) $(SRC) fillit.h $(GNL)

clean:
		rm -f 

fclean: clean
		rm -f $(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader

nor:
	norminette