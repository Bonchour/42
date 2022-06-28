# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hde-min <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 10:40:11 by hde-min           #+#    #+#              #
#    Updated: 2022/04/21 11:37:05 by hde-min          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_print_charac.c ft_print_string.c ft_print_pt_hexa.c ft_print_deci.c ft_print_entier_dix.c ft_desimal_unsigned.c ft_hexa_min.c ft_hexa_max.c ft_pourcent.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	gcc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
