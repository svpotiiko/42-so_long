# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 15:27:02 by vpotiiko          #+#    #+#              #
#    Updated: 2022/11/14 18:16:42 by vpotiiko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c \
		ft_printchar.c \
		ft_printstr.c \
		ft_printptr.c \
		ft_printnum.c \
		ft_printhex.c \
		ft_printunnum.c \
		ft_printper.c \
		ft_printupphex.c

OBJ = $(SRCS:.c=.o)

$(NAME):
	cc -c -Wall -Wextra -Werror $(SRCS) -I ft_printf.h
	ar rc libftprintf.a $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
