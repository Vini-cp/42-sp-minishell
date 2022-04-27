/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:20:01 by chideyuk          #+#    #+#             */
/*   Updated: 2022/04/27 02:41:39 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"
#include "../include/lexer.h"
#include "../include/expander.h"

int	g_exit;

void	ft_start(t_shell *mshell, char **env)
{
	g_exit = 0;
	mshell->firstvar = NULL;
	ft_startenv(mshell, env);
	mshell->tkcounter = 0;
	mshell->open = 0;
	mshell->start = 0;
	mshell->firsttoken = NULL;
	mshell->path = NULL;
}

void	ft_reprompt(int signum)
{
	g_exit = 130;
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
	prompt = ft_strjoinfree2("minishell:", ft_strjoin(cwd, "$ "));
	signal(SIGINT, ft_reprompt);
	signal(SIGQUIT, SIG_IGN);
	mshell->input = readline(prompt);
	if (mshell->input && ft_strlen(mshell->input))
		add_history(mshell->input);
	free(prompt);
}

static void	ft_run(t_shell *mshell)
{
	ft_lexer(mshell);
	ft_expander(mshell);
	if (mshell->firsttoken)
	{
		if (!ft_inputerror(mshell->firsttoken))
		{
			ft_parser(mshell);
			ft_executor(mshell);
			ft_free_cmd_table(mshell);
		}
		else
			g_exit = 2;
	}
	ft_freetokens(mshell);
	free(mshell->input);
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
			ft_run(mshell);
		else
		{
			ft_free_mshell(mshell);
			printf("exit\n");
			break ;
		}
	}
	return (0);
}
