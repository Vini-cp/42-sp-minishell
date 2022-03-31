/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:30:15 by vcordeir          #+#    #+#             */
/*   Updated: 2022/03/31 19:30:34 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

static void	ft_execute(char* path, char** args, char** env)
{
	int pid;

	pid = fork();
	if (pid == 0)
	{
		execve(path, args, env);
		write(1, "minishell: ", 11);
		write(1, args[0], ft_strlen(args[0]));
		write(1, ": command not found\n", 20);
		exit(1);
	}
	else if (pid == -1)
	{
		perror("fork");
		return;
	}
	else
		waitpid(pid, NULL, WUNTRACED);
}

void	ft_exec_cmd(t_shell *mshell, char **env, int order)
{
	t_cmd_table *cmdtable = mshell->cmdtable;
	while (order > 1)
	{
		cmdtable = cmdtable->next;
		order--;
	}

	if (ft_strcmp(cmdtable->cmd, "echo") == 0)
		ft_echo(cmdtable->args);
	else if (ft_strcmp(cmdtable->cmd, "cd") == 0)
		ft_cd(cmdtable->args[1]);
	else if (ft_strcmp(cmdtable->cmd, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(cmdtable->cmd, "export") == 0)
		ft_export(cmdtable->args, mshell);
	else if (ft_strcmp(cmdtable->cmd, "unset") == 0)
		ft_unset(cmdtable->args, mshell);
	else if (ft_strcmp(cmdtable->cmd, "env") == 0)
		ft_env(cmdtable->args, mshell);
	else if (ft_strcmp(cmdtable->cmd, "exit") == 0)
		ft_exit(mshell);
	else
		ft_execute(cmdtable->cmd_path, cmdtable->args, env);
}
