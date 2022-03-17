/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:40:51 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/17 20:37:30 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_exportenv(t_shell mshell)
{
	t_var	temp;

	temp = mshell->firstvar;
	while (temp)
	{
		if (temp->full)
			printf("declare -x %s\n", temp->full);
		temp = temp->next;
	}
}

void	ft_exportvar(t_shell *mshell, char *arg)
{
	char	**split;
	t_var	*temp;
	
	temp = mshell->firstvar;
	split = ft_split(arg, '=');
	while (temp && ft_strcmp(temp->key, split[0]))
		temp = temp->next;
	if(!temp)
		temp = ft_createvar
}

void	ft_export(t_shell *mshell, char	**args)
{
	int	counter;

	global_exit = 0;
	counter = 1;
	if (!args[1])
		ft_exportprint(mshell);
	else if
	{
		while (args[counter])
		{
			if (args[counter][0] == '=')
			{
				printf("export: `%s': not a valid identifier\n", temp->full);
				global_exit = 1;
			}
			else
				ft_exportvar(mshell, arg[counter]);
			counter++;
		}
	}
}
