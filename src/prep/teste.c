/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:43:56 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/22 23:12:58 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void ft_printtokens(t_shell *mshell)
{
	t_token	*temp;

	temp = mshell->firsttoken;

	while (temp)
	{
		printf("TOKEN:%s\n", temp->token);
		printf("QUOTES:%i\n", temp->quoted);
		temp = temp->next;
	}
	return ;
}

void ft_printtables(t_shell *mshell)
{
	t_cmd_table	*temp;
	int i;

	temp = mshell->cmdtable;
	while (temp)
	{
		printf("------------------------\n");
		if (temp->cmd)
			printf("CMD: %s\n", temp->cmd);
		if (temp->cmd)
			printf("PATH: %s\n", temp->cmd_path);
		if (temp->args != NULL)
		{
			i = 0;
			while(temp->args[i] != NULL)
			{
				printf("ARGS[%d]: %s\n", i, temp->args[i]);
				i++;
			}
		}
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