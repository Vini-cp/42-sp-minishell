/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:01:33 by vcordeir          #+#    #+#             */
/*   Updated: 2022/04/12 16:46:00 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

static void	ft_exec_one_cmd(t_shell *mshell, char **env)
{
	t_cmd_table *cmdtable = mshell->cmdtable;

	if (cmdtable->cmd && !(cmdtable->input_type || cmdtable->output_type))
		ft_exec_cmd(mshell, env, 1);
	else
		ft_exec_redir(mshell, env);
}

static void ft_exec_mult_cmd(t_shell *mshell, char **env)
{
	int	pid;
	int	fd[2];

	pipe(fd);
	pid = fork();
	if (pid != 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		ft_exec_cmd(mshell, env, 2);
		waitpid(pid, NULL, WUNTRACED);
	}
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		ft_exec_cmd(mshell, env, 1);
	}
}

void	ft_executor(t_shell *mshell)
{
	char	**minienv;

	minienv = ft_getenv(mshell->firstvar);
	if (mshell->no_cmds == 1)
		ft_exec_one_cmd(mshell, minienv);
	else
		ft_exec_mult_cmd(mshell, minienv);
}
