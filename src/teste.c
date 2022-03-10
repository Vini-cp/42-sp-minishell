/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:43:56 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/10 18:39:15 by chideyuk         ###   ########.fr       */
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