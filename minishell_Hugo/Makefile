SRCS	= main.c utils.c ft_split.c pwd.c cd.c echo.c export.c unset.c env.c env_check.c env_utils.c exit.c error.c check.c quotes.c signal.c init.c parsing.c env_utils_2.c check_2.c
OBJS	= $(SRCS:.c=.o)
CFLAGS	= -Wextra -Wall -Werror -g3 -I.
CC		= gcc
NAME	= minishell

all: $(NAME)
$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -lreadline -Llibft -lft
re: clean all
clean:
	rm -f $(OBJS)
	make -C libft clean
fclean: clean
	rm -f $(NAME)
	make -C libft fclean
.PHONY: all clean fclean re
