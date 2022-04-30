/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:30:15 by vcordeir          #+#    #+#             */
/*   Updated: 2022/04/30 03:10:06 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_treatint(int signum)
{
	g_exit = 130;
	(void)signum;
}

static void	ft_treatquit(int signum)
{
	g_exit = 131;
	(void)signum;
}

static void	(ft_execchild(t_shell *mshell, char *path, char **args, char **env))
{
	while (g_exit != 130 && g_exit != 131)
	{
		signal(SIGINT, ft_treatint);
		signal(SIGQUIT, ft_treatquit);
		execve(path, args, env);
		write(1, "minishell: ", 11);
		write(1, args[0], ft_strlen(args[0]));
		write(1, ": command not found\n", 20);
		ft_exit(mshell, env, 127);
	}
	ft_exit(mshell, env, g_exit);
}

static void	ft_execute(t_shell *mshell, char *path, char **args, char **env)
{
	int	pid;
	int	status;

	g_exit = 0;
	pid = fork();
	if (pid == 0)
		ft_execchild(mshell, path, args, env);
	else if (pid == -1)
	{
		perror("fork");
		return ;
	}
	else
	{
		signal(SIGINT, ft_treatint);
		signal(SIGQUIT, ft_treatquit);
		waitpid(pid, &status, WUNTRACED);
		if (g_exit == 131)
			printf("Quit (core dumped)");
		if (g_exit == 130 || g_exit == 131)
			printf("\n");
		else if (WIFEXITED(status))
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
