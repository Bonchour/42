# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 12:34:26 by hde-min           #+#    #+#              #
#    Updated: 2022/06/14 16:24:57 by hde-min          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long_bonus.c ft_test_map_bonus.c ft_test_map_4_bonus.c ft_wall_bonus.c ft_init_image_bonus.c ft_file_map_bonus.c ft_file_bonus.c ft_matrice_bonus.c ft_moove_bonus.c ft_init_struc_bonus.c ft_mouse_bonus.c ft_event_bonus.c ft_see_score_bonus.c ft_init_image_2_bonus.c ft_event_2_bonus.c ft_check_ber_bonus.c

OBJS = ${SRCS:.c=.o}

NAME = so_long

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g3


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
