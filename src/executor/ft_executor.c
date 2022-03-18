/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:01:33 by vcordeir          #+#    #+#             */
/*   Updated: 2022/03/18 02:30:52 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_exec_cmd(t_shell *mshell)
{
	t_cmd_table *cmdtable = mshell->cmdtable;

	if (ft_strcmp(cmdtable->cmd, "echo") == 0)
		return ;
	else if (ft_strcmp(cmdtable->cmd, "cd") == 0)
		ft_cd(cmdtable->args);
	else if (ft_strcmp(cmdtable->cmd, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(cmdtable->cmd, "echo") == 0)
		return ;
	else if (ft_strcmp(cmdtable->cmd, "export") == 0)
		return ;
	else if (ft_strcmp(cmdtable->cmd, "unset") == 0)
		return ;
	else if (ft_strcmp(cmdtable->cmd, "env") == 0)
		return ;
	else if (ft_strcmp(cmdtable->cmd, "exit") == 0)
		return ;
}

void	ft_executor(t_shell *mshell)
{
	if (mshell->cmd_length == 1)
		ft_exec_cmd(mshell);
}
