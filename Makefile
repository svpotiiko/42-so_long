# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpotiiko <vpotiiko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 19:03:37 by vpotiiko          #+#    #+#              #
#    Updated: 2023/02/18 16:42:13 by vpotiiko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

OBJS = 	obj/generate.o \
		obj/ft_calloc.o \
		obj/ft_split.o \
		obj/ft_strjoin.o \
		obj/ft_bzero.o \
		obj/read_map.o \
		obj/ft_strlen.o \
		obj/render_map.o \
		obj/move.o \
		obj/so_long.o \
		obj/ft_printf.o \
		obj/ft_printchar.o \
		obj/ft_printhex.o \
		obj/ft_printnum.o \
		obj/ft_printper.o \
		obj/ft_printptr.o \
		obj/ft_printstr.o \
		obj/ft_printunnum.o \
		obj/ft_printupphex.o \
		obj/close_game.o \
		obj/return_error.o \
		obj/ft_putstr_fd.o \
		obj/surr_check.o \
		obj/path_check.o \
		obj/ft_strncmp.o \
		obj/ft_strrchr.o \
		obj/ft_isascii.o 

obj/%.o: %.c
	cc -c -Wall -Wextra -Werror $< -Imlx -o $@ -I so_long.h

obj/%.o: libft/%.c
	cc -c -Wall -Wextra -Werror $< -Imlx -o $@ -I libft/libft.h

obj/%.o: printf/%.c
	cc -c -Wall -Wextra -Werror $< -Imlx -o $@ -I printf/ft_printf.h

$(NAME): $(OBJS)
	cc -Wall -Wextra -Werror -g -fsanitize=address $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all