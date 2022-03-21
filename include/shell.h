/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:07:40 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/21 18:05:57 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/libft.h"

#define PATH_MAX 4096

extern int	global_exit;

typedef enum e_in_out_type
{
	NO_CHAR,
	ONE_CHAR,
	TWO_CHARS
} t_in_out_type;

typedef struct s_token
{
	char			*token;
	struct s_token	*next;
	int				quoted;
}					t_token;

typedef struct s_var
{
	char			*full;
	char			*key;
	char			*content;
	struct s_var	*next;
}					t_var;

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
	char				**path;
	int					tkcounter;
	int					open;
	int					start;
	int					cmd_input;
	int					cmd_output;
	int					cmd_length;
	struct s_token		*firsttoken;
	struct s_var		*firstvar;
	struct s_cmd_table	*cmdtable;
}					t_shell;

void		ft_lexer(t_shell *mshell);
void		ft_parser(t_shell *mshell);
void		ft_executor(t_shell *mshell, char **env);
void		ft_freeptr(char **ptr);
int			ft_iscommand(t_shell *mshell, char *str);
char		**ft_pathfinder(t_shell *mshell);
char		*ft_concatenate(char *left, char *right, char middle);
int			ft_special_char(char *str);
void		ft_printtokens(t_shell *mshell);
void		ft_printtables(t_shell *mshell);
void		ft_freetokens(t_shell *mshell);
void		ft_free_cmd_table(t_shell *mshell);
t_cmd_table	*ft_create_cmd_table(void);
void		ft_startenv(t_shell *mshell, char **env);
t_var		*ft_createvar(char *entry, char **split);

void		ft_pwd(void);
void		ft_cd(char* new_path);
void		ft_exit(t_shell *mshell);
void		ft_echo(char **args);
void		ft_export(char	**args, t_shell *mshell);
void		ft_unset(char **args, t_shell *mshell);
void		ft_unsetvar(char *arg, t_shell *mshell);
void		ft_freevar(t_var *var);
void		ft_env(char **args, t_shell *mshell);

#endif
