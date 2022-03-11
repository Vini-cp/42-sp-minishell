/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:43:56 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/11 03:51:53 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

void ft_printtokens(t_shell *mshell)
{
	t_token	*temp;

	temp = mshell->firsttoken;

	while (temp)
	{
		printf("TOKEN:%s\n", temp->token);
		temp = temp->next;
	}
	return ;
}

void ft_printtables(t_shell *mshell)
{
	t_cmd_table	*temp;

	temp = mshell->cmdtable;
	while (temp)
	{
		printf("------------------------\n");
		if (temp->cmd)
			printf("CMD: %s\n", temp->cmd);
		if (temp->args)
			printf("ARGS: %s\n", temp->args);
		if (temp->input_type > 0)
			printf("I_ARG: %s\n", temp->input_arg);
		if (temp->output_type > 0)
			printf("O_ARG: %s\n", temp->output_arg);
		printf("------------------------\n");
		temp = temp->next;
	}
}

void	ft_freeptr(char	**ptr)
{
	int 	counter;
	
	counter = 0;
	while (ptr[counter])
	{
		free(ptr[counter]);
		counter++;
	}
	free(ptr);
}