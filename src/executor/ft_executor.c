/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:01:33 by vcordeir          #+#    #+#             */
/*   Updated: 2022/03/18 17:58:56 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

static char	**set_args(t_cmd_table *cmdtable)
{
	char *temp;
	char **args;

	temp = ft_strdup(cmdtable->cmd);
	if (cmdtable->args)
		temp = ft_concatenate(temp, cmdtable->args, ' ');
	args = ft_split(temp, ' ');
	return (args);
}

static void	free_args(char **args)
{
	int	str_position;

	str_position = 0;
	while(args[str_position] != NULL)
	{
		free(args[str_position]);
		str_position++;
	}
	free(args);
}

static char	*set_cmd_path(char **paths, char *cmd)
{
	int	str_position;
	char *path_to_test;

	str_position = 0;
	while (paths[str_position] != NULL)
	{
		path_to_test = ft_concatenate(paths[str_position], cmd, '/');
		if (access(path_to_test, F_OK) == 0)
			return (path_to_test);
		str_position++;
	}
	return (NULL);
}

static void	ft_exec_cmd(t_shell *mshell, char **env)
{
	t_cmd_table *cmdtable = mshell->cmdtable;
	char **args;
	char *path;

	args = set_args(cmdtable);
	if (ft_strcmp(cmdtable->cmd, "echo") == 0)
		ft_echo(args);
	else if (ft_strcmp(cmdtable->cmd, "cd") == 0)
		ft_cd(cmdtable->args);
	else if (ft_strcmp(cmdtable->cmd, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(cmdtable->cmd, "export") == 0)
		return ;
		// ft_export(mshell, args);
	else if (ft_strcmp(cmdtable->cmd, "unset") == 0)
		return ;
	else if (ft_strcmp(cmdtable->cmd, "env") == 0)
		return ;
		// ft_env(mshell, args);
	else if (ft_strcmp(cmdtable->cmd, "exit") == 0)
		ft_exit(mshell);
	else
	{
		path = set_cmd_path(mshell->path, cmdtable->cmd);
		if (path != NULL)
		{
			execve(path, args, env);
			free(path);
		}
	}
	free_args(args);
}

void	ft_executor(t_shell *mshell, char **env)
{	
	if (mshell->cmd_length == 1)
		ft_exec_cmd(mshell, env);
}
