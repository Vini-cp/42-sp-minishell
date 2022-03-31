/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:36:48 by vcordeir          #+#    #+#             */
/*   Updated: 2022/03/30 16:56:18 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_free_cmd_table(t_shell *mshell)
{
	t_cmd_table	*temp;
	t_cmd_table	*temp2;

	temp = mshell->cmdtable;
	while (temp)
	{
		if (temp->cmd)
			free(temp->cmd);
		if (temp->cmd_path)
			free(temp->cmd_path);
		if (temp->args)
			ft_freeptr(temp->args);
		if (temp->input_type)
			free(temp->input_arg);
		if (temp->output_type)
			free(temp->output_arg);
		temp2 = temp;
		temp = temp->next;
		free(temp2);
	}
}
