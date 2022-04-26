/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:30:15 by vcordeir          #+#    #+#             */
/*   Updated: 2022/04/26 20:53:05 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

static void	ft_execute(t_shell *mshell, char *path, char **args, char **env)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		execve(path, args, env);
		write(1, "minishell: ", 11);
		write(1, args[0], ft_strlen(args[0]));
		write(1, ": command not found\n", 20);
		ft_exit(mshell, env, 127);
	}
	else if (pid == -1)
	{
		perror("fork");
		return ;
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
		if (WIFEXITED(status))
			g_exit = WEXITSTATUS(status);
	}
}

void	ft_exec_cmd(t_shell *mshell, char **env, t_cmd_table *cmdtable)
{
	if (!cmdtable->cmd)
		return ;
	if (ft_strcmp(cmdtable->cmd, "echo") == 0)
		ft_echo(cmdtable->args);
	else if (ft_strcmp(cmdtable->cmd, "cd") == 0)
		ft_cd(mshell, cmdtable->args[1]);
	else if (ft_strcmp(cmdtable->cmd, "pwd") == 0)
		ft_pwd(cmdtable->args[1]);
	else if (ft_strcmp(cmdtable->cmd, "export") == 0)
		ft_export(cmdtable->args, mshell);
	else if (ft_strcmp(cmdtable->cmd, "unset") == 0)
		ft_unset(cmdtable->args, mshell);
	else if (ft_strcmp(cmdtable->cmd, "env") == 0)
		ft_env(cmdtable->args, mshell);
	else if (ft_strcmp(cmdtable->cmd, "exit") == 0)
		ft_exit(mshell, env, 0);
	else
		ft_execute(mshell, cmdtable->cmd_path, cmdtable->args, env);
}
