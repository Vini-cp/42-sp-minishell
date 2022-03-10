.PHONY:	clean fclean re all

LIBFT	:= libft
NAME	:= minishell
CFLAGS	:= -Wall -Wextra -Werror
LFLAGS	:= -Llibft -lft -lreadline
CC		:= gcc
SRC		:=	shell.c \
			lexer/lexer.c \
			parser/parser.c \
				teste.c

SRC_FOLDER 	:= src
OBJ_FOLDER	:= obj
SRCS 		:= $(addprefix ${SRC_FOLDER}/, ${SRC})
OBJS 		:= $(addprefix ${OBJ_FOLDER}/, ${SRCS:.c=.o})

all	: $(NAME)

$(NAME)	: $(OBJS)
	make  -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)

$(OBJ_FOLDER)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJ_FOLDER)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re	: fclean all
