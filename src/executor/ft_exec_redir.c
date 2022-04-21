/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:32:56 by vcordeir          #+#    #+#             */
/*   Updated: 2022/04/21 21:50:24 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

static int	ft_outredir(char *file_path, int mode)
{
	int	fd;
	int	flag_mode;
	int	flag_permission;

	flag_permission = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if (mode == ONE_CHAR)
		flag_mode = O_TRUNC;
	else if (mode == TWO_CHARS)
		flag_mode = O_APPEND;
	if (access(file_path, F_OK) == 0)
		fd = open(file_path, flag_mode | O_WRONLY | flag_permission);
	else
		fd = open(file_path, flag_mode | O_CREAT | O_WRONLY | flag_permission);
	return (fd);
}

void	ft_inredirapp(char *stop)
{
	int		fd;
	int		fdout;
	char	*to_compare;
	char	*input;

	fdout = dup(1);
	to_compare = readline("> ");
	input = ft_strdup("");
	while (ft_strcmp(stop, to_compare))
	{
		input = ft_strjoinfreeboth(input, to_compare);
		input = ft_strjoinfree1(input, "\n");
		to_compare = readline("> ");
	}
	free(to_compare);
	fd = ft_outredir("minitempfile.txt", ONE_CHAR);
	dup2(fd, 1);
	printf("%s", input);
	close(fd);
	dup2(fdout, 1);
	free(input);
}

static int	ft_inredir(char *file_path, int mode)
{
	int		fd;

	if (mode == ONE_CHAR)
	{
		if (access(file_path, F_OK) == 0)
			fd = open(file_path, O_RDONLY);
		else
		{
			printf("%s: No such file or directory\n", file_path);
			g_exit = 1;
		}
	}
	else if (mode == TWO_CHARS)
	{
		ft_inredirapp(file_path);
		fd = open("minitempfile.txt", O_RDONLY);
	}
	return (fd);
}

void		ft_redir(t_shell *mshell, char **env, t_cmd_table *cmdtable, int fd)
{
	int	fdin;
	int	fdout;

	if (cmdtable->input_type)
	{
		fdin = ft_inredir(cmdtable->input_arg, cmdtable->input_type);
		dup2(fdin, 0);
	}
	if (fd)
		dup2(fd, 1);
	if (cmdtable->output_type)
	{
		fdout = ft_outredir(cmdtable->output_arg, cmdtable->output_type);
		dup2(fdout, 1);
	}
	ft_exec_cmd(mshell, env, cmdtable);
	if (cmdtable->input_type)
		close(fdin);
	if (cmdtable->input_type == TWO_CHARS)
		unlink("minitempfile.txt");
	if (cmdtable->output_type)
		close(fdout);
}
