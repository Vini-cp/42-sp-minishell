#ifndef SHELL_H
# define SHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "parser.h"

typedef struct	s_token
{
	char			*token;
	struct s_token	*next;
	int				test;
}					t_token;

typedef struct	s_cmd_table
{
	char				*cmd;
	char				*args;
	int					input_type;
	char				*input_arg;
	int					output_type;
	char				*output_arg;
	struct s_cmd_table	*next;
}				t_cmd_table;

typedef struct	s_shell
{
	char				*input;
	char				**PATH;
	int					tkcounter;
	int					open;
	int					start;
	int					input;
	int					output;
	struct s_token		*firsttoken;
	struct s_cmd_table	*cmdtable;
}					t_shell;

void	ft_lexer(t_shell *mshell);
void	ft_parser(t_shell *mshell);


void ft_printtokens(t_shell *mshell);
void ft_freetokens(t_shell *mshell);

#endif