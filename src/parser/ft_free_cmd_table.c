/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:36:48 by vcordeir          #+#    #+#             */
/*   Updated: 2022/03/22 23:14:16 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_free_cmd_table(t_shell *mshell)
{
	t_cmd_table	*temp;

	temp = mshell->cmdtable;
	while (temp)
	{
		if (temp->cmd)
			free(temp->cmd);
		if (temp->cmd_path)
			free(temp->cmd_path);
		if (temp->args)
			free(temp->args);
		if (temp->input_type)
			free(temp->input_arg);
		if (temp->output_type)
			free(temp->output_arg);
		free(temp);
		temp = temp->next;
	}
}
