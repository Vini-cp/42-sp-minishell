/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:20:01 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/07 20:10:07 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
inicializa dados do mshell, tkcounter é o contador utilizado para criação de tokens,
open indica se há um token sendo criado(1)ou não(0), start marca o primeiro termo do token em relação a tkcounter,
firstoken é um ponteiro para o primeiro token;
*/
void	ft_start(t_shell *mshell, char **env)
{
	(void)env;//
	
	mshell->tkcounter = 0;
	mshell->open  = 0;
	mshell->start = 0;
	mshell->firsttoken = NULL;
}

/*
Função que ocorre ao receber o sinal SIGINT(ctrl-C)
*/
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
	
	prompt = ft_strdup("minishell$ ");
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
	(void)env;//

	mshell = malloc(sizeof(*mshell));
	ft_start(mshell, env);
	while (1)
	{
		ft_getinput(mshell);
		if (mshell->input)
		{
			ft_lexer(mshell);
			ft_printtokens(mshell);//
			ft_freetokens(mshell);
			free(mshell->input);
		}
		else
		{
			free(mshell->input);
			free(mshell);
			exit(0);
		}
	}
	return (0);
}