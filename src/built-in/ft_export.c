/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:40:51 by chideyuk          #+#    #+#             */
/*   Updated: 2022/04/29 23:01:44 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

static int	ft_varisvalid(char	*arg)
{
	int	counter;

	counter = 0;
	while (arg[counter] && arg[counter] != '=')
	{
		if (!ft_isalnum(arg[counter]) && arg[counter] != '_')
		{
			printf("export: `%s': not a valid identifier\n", arg);
			g_exit = 1;
			return (0);
		}
		counter++;
	}
	return (1);
}

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
		temp->next = ft_createvar(arg, split);
	}
}

void	ft_export(char	**args, t_shell *mshell)
{
	int	counter;

	g_exit = 0;
	counter = 1;
	if (!args[1])
		ft_exportprint(mshell);
	while (args[counter])
	{
		if (args[counter][0] == '=')
		{
			printf("export: `%s': not a valid identifier\n", args[counter]);
			g_exit = 1;
		}
		else
		{
			if (ft_varisvalid(args[counter]))
				ft_exportvar(mshell, args[counter]);
		}
		counter++;
	}
}
