/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:40:51 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/18 22:01:36 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

static void	ft_exportprint(t_shell *mshell)
{
	t_var	*temp;

	temp = mshell->firstvar;
	while (temp)
	{
		if (temp->full && ft_strchr(temp->full, '='))
			printf("declare -x %s=\"%s\"\n", temp->key, temp->content);
		else if (temp->full)
			printf("declare -x %s\n", temp->key);
		temp = temp->next;
	}
}

static void	ft_exportvar(t_shell *mshell, char *arg)
{
	char	**split;
	t_var	*temp;
	t_var	*temp2;
	
	temp = mshell->firstvar;
	split = ft_split(arg, '=');
	while (temp && ft_strcmp(temp->key, split[0]))
	{
		temp2 = temp;
		temp = temp->next;
	}
	if (!temp)
		temp2->next = ft_createvar(arg, split);
	else
	{
		ft_unsetvar(split[0], mshell);
		temp = mshell->firstvar;
		while (temp->next)
			temp = temp->next;
		temp2->next = ft_createvar(arg, split);
	}
}

void	ft_export(char	**args, t_shell *mshell)
{
	int	counter;

	//global_exit = 0;
	counter = 1;
	if (!args[1])
		ft_exportprint(mshell);
	else
	{
		while (args[counter])
		{
			if (args[counter][0] == '=')
			{
				printf("export: `%s': not a valid identifier\n", args[counter]);
				//global_exit = 1;
			}
			else
				ft_exportvar(mshell, args[counter]);
			counter++;
		}
	}
}
