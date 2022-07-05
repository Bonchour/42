SRCS		= ./ft_atoi.c ./ft_isdigit.c ./ft_memmove.c ./ft_split.c ./ft_strlcpy.c ./ft_strtrim.c ./ft_bzero.c ./ft_isprint.c ./ft_memset.c ./ft_strchr.c ./ft_strlen.c ./ft_substr.c ./ft_calloc.c ./ft_itoa.c ./ft_putchar_fd.c ./ft_strdup.c ./ft_strmapi.c ./ft_tolower.c ./ft_isalnum.c ./ft_memchr.c ./ft_putendl_fd.c ./ft_striteri.c ./ft_strncmp.c ./ft_toupper.c ./ft_isalpha.c ./ft_memcmp.c ./ft_putnbr_fd.c ./ft_strjoin.c ./ft_strnstr.c ./ft_isascii.c ./ft_memcpy.c ./ft_putstr_fd.c ./ft_strlcat.c ./ft_strrchr.c ./ft_strcmp.c
BONUS		= ./ft_lstnew.c ./ft_lstadd_front.c ./ft_lstsize.c ./ft_lstlast.c ./ft_lstadd_back.c ./ft_lstdelone.c ./ft_lstclear.c ./ft_lstiter.c ./ft_lstmap.c 
OBJS		= ${SRCS:.c=.o}
BONUS_OBJS	= ${BONUS:.c=.o}
CFLAGS		= -Wall -Wextra -Werror
NAME		= libft.a
LIBSHARE	= libft.so

.c.o:
	gcc $(CFLAGS) -g -c ${SRCS}
	ar rc libft.a *.o
${NAME}: ${OBJS}
all: ${NAME}
bonus:
	gcc $(CFLAGS) -g -c ${BONUS}
	ar rc libft.a *.o
so:
	gcc -c -fPIC $(CFLAGS) $(SRCS) ${BONUS}
	gcc -nostartfiles -shared -o $(LIBSHARE) $(OBJS) ${BONUS_OBJS}
clean:
	rm -f *.o
fclean: clean
	rm -f ${NAME}
re: fclean all

.PHONY: all clean fclean .c.o re bonus
