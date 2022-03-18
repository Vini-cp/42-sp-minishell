.PHONY:	clean fclean re all

LIBFT	:= libft
NAME	:= minishell
CFLAGS	:= -Wall -Wextra -Werror
LFLAGS	:= -Llibft -lft -lreadline
CC		:= gcc
SRC		:=	shell.c \
			teste.c \
			lexer/lexer.c \
			lexer/token.c \
			expander/expander.c \
			expander/expander_utils.c \
			expander/trimquotes.c \
			parser/ft_parser.c \
			parser/ft_create_cmd_table.c \
			parser/ft_free_cmd_table.c \
			executor/ft_executor.c \
			built-in/ft_pwd.c \
			built-in/ft_cd.c \
			utils/ft_concatenate.c \
			utils/ft_iscommand.c \
			utils/ft_pathfinder.c \
			utils/ft_startenv.c \
			utils/ft_special_char.c

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

do	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)