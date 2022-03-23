/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:20:01 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/23 03:11:15 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"
#include "../include/lexer.h"
#include "../include/expander.h"

int	global_exit;

void	ft_start(t_shell *mshell, char **env)
{
	global_exit = 0;
	mshell->firstvar = NULL;
	ft_startenv(mshell, env);
	mshell->path = ft_pathfinder(mshell);
	mshell->tkcounter = 0;
	mshell->open  = 0;
	mshell->start = 0;
	mshell->firsttoken = NULL;
}

void	ft_reprompt(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_getinput(t_shell *mshell)
{
	char	*prompt;
	char	cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	prompt = ft_strjoin("minishell:", ft_strjoin(cwd, "$ "));
	signal(SIGINT, ft_reprompt);
	signal(SIGQUIT, SIG_IGN);
	mshell->input = readline(prompt);
	if (mshell->input && ft_strlen(mshell->input))
		add_history(mshell->input);
	free(prompt);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*mshell;
	(void)argc;
	(void)argv;
	
	mshell = malloc(sizeof(*mshell));
	ft_start(mshell, env);
	while (1)
	{
		ft_getinput(mshell);
		if (mshell->input)
		{
			ft_lexer(mshell);
			ft_expander(mshell);
			if (mshell->firsttoken)
			{
				// ft_printtokens(mshell);
				ft_parser(mshell);
				// ft_printtables(mshell);
				ft_executor(mshell, env);
				ft_free_cmd_table(mshell);
			}
			ft_freetokens(mshell);
			free(mshell->input);
		}
		else
			ft_exit(mshell);
	}
	return (0);
}
