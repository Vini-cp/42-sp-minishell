/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:24:02 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/18 21:55:54 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_freevar(t_var *var)
{
	free(var->full);
	free(var->key);
	free(var->content);
	var->full = NULL;
	var->key = NULL;
	var->content = NULL;
}

void	ft_unsetvar(char *arg, t_shell *mshell)
{
	t_var	*temp;
	t_var	*temp2;

	temp = mshell->firstvar;
	while (temp && ft_strcmp(arg, temp->key))
	{
		temp2 = temp;
		temp = temp->next;
	}
	if (temp)
	{
		ft_freevar(temp);
		if (temp2)
			temp2->next = temp->next;
		temp->next = NULL;
		free(temp);
		temp = NULL;
	}
}

void	ft_unset(char **args, t_shell *mshell)
{
	int	counter;

	counter = 1;
	//global_exit = 0;
	while(args[counter])
	{
		if	(ft_strchr(args[counter], '='))
		{
			printf("unset: `%s': not a valid identifier\n", args[counter]);
			//global_exit = 1;
		}
		else
			ft_unsetvar(args[counter], mshell);
		counter++;
	}
}
