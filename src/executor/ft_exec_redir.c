/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:32:56 by vcordeir          #+#    #+#             */
/*   Updated: 2022/03/31 19:33:47 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_exec_redir(t_shell *mshell, char **env)
{
	t_cmd_table *cmdtable = mshell->cmdtable;
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
		ft_exec_cmd(mshell, env, 1);
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
