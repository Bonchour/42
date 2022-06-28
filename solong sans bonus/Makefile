# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 12:34:26 by hde-min           #+#    #+#              #
#    Updated: 2022/06/10 11:42:12 by hde-min          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c ft_test_map.c ft_test_map_4.c ft_wall.c ft_init_image.c ft_file_map.c ft_file.c ft_matrice.c ft_moove.c ft_init_struc.c ft_mouse.c ft_putnbr.c ft_check_ber.c

OBJS = ${SRCS:.c=.o}

NAME = so_long

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror


%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

${NAME}:	${OBJS}
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all:	${NAME}

clean:
	$(RM) ${OBJS}

fclean: clean
	$(RM) ${NAME}

re: fclean all

run:
	valgrind ./so_long map/1.ber

.PHONY: all clean fclean re
