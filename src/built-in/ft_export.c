/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:40:51 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/18 17:50:27 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

static void	ft_exportprint(t_shell *mshell)
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

static void	ft_updatevar(t_var *var, char *arg)
{
	char	**split;
	
	split = ft_split(arg, '=');
	ft_freevar(var);
	var->full = ft_strdup(arg);
	var->key = split[0];
	if (split[1])
		var->content = split[1];
	ft_freeptr(split);
}

static void	ft_exportvar(t_shell *mshell, char *arg)
{
	char	**split;
	t_var	*temp;
	
	temp = mshell->firstvar;
	split = ft_split(arg, '=');
	while (temp && ft_strcmp(temp->key, split[0]))
		temp = temp->next;
	if (!temp)
		temp = ft_createvar(arg, split);
	else
		temp = ft_updatevar(temp, arg);
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
