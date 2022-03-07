.PHONY:	clean fclean re all

LIBFT	:= libft
NAME	:= minishell
CFLAGS	:= -Wall -Wextra -Werror -o
CC	:= gcc
SRCS	:=	shell.c \
			lexer.c \
				teste.c

all	: $(NAME)

$(NAME)	: $(SRCS)
	make  -C $(LIBFT)
	$(CC) $(CFLAGS) $(NAME) $(SRCS) -Llibft -lft -lreadline

clean	:
		make clean -C $(LIBFT)
fclean	:
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re	: fclean all