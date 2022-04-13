/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:32:56 by vcordeir          #+#    #+#             */
/*   Updated: 2022/04/13 20:02:37 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_exec_redir(t_shell *mshell, char **env, t_cmd_table *cmdtable)
{
	int	pid;
	int	fd[2];
	int	out;
	char	*line;

	pipe(fd);
	pid = fork();
	if (pid != 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		ft_exec_cmd(mshell, env, 1, cmdtable);
		close(fd[1]);
		waitpid(pid, NULL, WUNTRACED);
	}
	else if (pid == 0)
	{
		close(fd[1]);
		out = get_next_line(fd[0], &line);
		ft_output_redirection(cmdtable->output_arg, cmdtable->output_type, line);
		while (out == 1)
		{
			out = get_next_line(fd[1], &line);
			ft_output_redirection(cmdtable->output_arg, TWO_CHARS, line);
		}
		close(fd[0]);
	}
}

void	ft_redirstart(t_shell *mshell, char **env, t_cmd_table *cmdtable)
{
	t_cmd_table	*temp;
	
	temp = cmdtable;
	
}