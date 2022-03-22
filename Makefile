.PHONY:	clean fclean re all

LIBFT	:= libft
NAME	:= minishell
CFLAGS	:= -Wall -Wextra -Werror
LFLAGS	:= -Llibft -lft -lreadline
CC		:= gcc
SRC		:=	shell.c \
			lexer/lexer.c \
			lexer/token.c \
			expander/expander.c \
			expander/expander_utils.c \
			expander/trimquotes.c \
			parser/ft_parser.c \
			parser/ft_create_args.c \
			parser/ft_create_cmd_table.c \
			parser/ft_free_cmd_table.c \
			built-in/ft_pwd.c \
			built-in/ft_cd.c \
			built-in/ft_exit.c \
			built-in/ft_echo.c \
			built-in/ft_env.c \
			built-in/ft_export.c \
			built-in/ft_unset.c \
			utils/ft_commandpath.c \
			utils/ft_concatenate.c \
			utils/ft_iscmdpath.c \
			utils/ft_iscommand.c \
			utils/ft_special_char.c \
			prep/ft_pathfinder.c \
			prep/ft_startenv.c \
			prep/teste.c

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