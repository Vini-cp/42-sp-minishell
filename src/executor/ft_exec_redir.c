/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:32:56 by vcordeir          #+#    #+#             */
/*   Updated: 2022/04/14 14:03:51 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_exec_redir(t_shell *mshell, char **env, t_cmd_table *cmdtable)
{
	int	fdout;
	int flag_permission;
	int fdpipe[2];

	pipe(fdpipe);
	flag_permission = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if (access(cmdtable->output_arg, F_OK) == 0)
		fdout = open(cmdtable->output_arg, cmdtable->output_type | O_WRONLY | flag_permission);
	else
		fdout = open(cmdtable->output_arg, cmdtable->output_type | O_CREAT | O_WRONLY | flag_permission);

	dup2(fdpipe[1], fdout);
	ft_exec_cmd(mshell, env, 1, cmdtable);
	close(fdpipe[0]);
	close(fdpipe[1]);
}

// void	ft_redirstart(t_shell *mshell, char **env, t_cmd_table *cmdtable)
// {
// 	t_cmd_table	*temp;
	
// 	temp = cmdtable;
	
// }