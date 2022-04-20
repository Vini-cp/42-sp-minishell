/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:01:33 by vcordeir          #+#    #+#             */
/*   Updated: 2022/04/20 04:41:16 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

static void	ft_exec_one_cmd(t_shell *mshell, char **env)
{
	t_cmd_table	*cmdtable;
	int			stdin;
	int			stdout;	

	cmdtable = mshell->cmdtable;
	if (cmdtable->cmd && !(cmdtable->input_type || cmdtable->output_type))
		ft_exec_cmd(mshell, env, cmdtable);
	else
	{
		stdin = dup(0);
		stdout = dup(1);
		ft_redir(mshell, env, cmdtable, 0);
		dup2(stdin, 0);
		dup2(stdout, 1);
	}
}

static int	ft_multiaux(t_shell *mshell, char **env, t_cmd_table *cmdtable)
{
	int			fd[2];
	int			fdaux;
	t_cmd_table	*temp;

	temp = cmdtable;
	pipe(fd);
	dup2(fd[1], 1);
	ft_exec_cmd(mshell, env, temp);
	close(fd[1]);
	dup2(fd[0], 0);
	if (temp->next && temp->next->next)
	{
		fdaux = ft_multiaux(mshell, env, temp->next);
		close(fdaux);
	}
	return (fd[0]);
}

static void	ft_exec_mult_cmd(t_shell *mshell, char **env, t_cmd_table *cmdtable)
{
	int			fd[2];
	int			stdin;
	int			stdout;
	int			redir;
	t_cmd_table	*temp;

	temp = cmdtable;
	pipe(fd);
	stdin = dup(0);
	stdout = dup(1);
	redir = ft_redir(mshell, env, temp, fd[1]);
	if (redir)
		return ;
	close(fd[1]);
	dup2(fd[0], 0);
	temp = temp->next;
	if (temp->next)
		close(ft_multiaux(mshell, env, temp));
	while (temp->next)
		temp = temp->next;
	dup2(stdout, 1);
	ft_redir(mshell, env, temp, 0);
	dup2(stdout, 1);
	dup2(stdin, 0);
	close(fd[0]);
}

void	ft_executor(t_shell *mshell)
{
	char	**minienv;

	minienv = ft_getenv(mshell->firstvar);
	if (mshell->no_cmds == 1)
		ft_exec_one_cmd(mshell, minienv);
	else
		ft_exec_mult_cmd(mshell, minienv, mshell->cmdtable);
}
