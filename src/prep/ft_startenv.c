/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:20:08 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/29 16:55:15 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

t_var	*ft_createvar(char *entry, char **split)
{
	t_var	*var;

	var = malloc(sizeof(*var));
	var->full = ft_strdup(entry);
	if (!split[1])
	{
		var->key = ft_strdup(split[0]);
		var->content = ft_strdup("");
	}
	else
	{
		var->key = ft_strdup(split[0]);
		var->content = ft_strdup(split[1]);
	}
	var->next = NULL;
	ft_freeptr(split);
	return (var);
}

void	ft_startenv(t_shell *mshell, char **env)
{
	t_var	*temp;
	int		counter;
	char	**split;

	counter = 1;
	temp = NULL;
	split = ft_split(env[0], '=');
	temp = ft_createvar(env[0], split);
	mshell->firstvar = temp;
	while (env[counter])
	{
		split = ft_split(env[counter], '=');
		temp->next = ft_createvar(env[counter], split);
		temp = temp->next;
		counter++;
	}
}

void	ft_free_env(t_shell *mshell)
{
	t_var	*temp;
	t_var	*temp2;

	temp = mshell->firstvar;
	while (temp)
	{
		free(temp->full);
		temp->full = NULL;
		free(temp->key);
		temp->key = NULL;
		if (temp->content)
		{
			free(temp->content);
			temp->content = NULL;
		}
		temp2 = temp;
		temp = temp->next;
		free(temp2);
		temp2 = NULL;
	}
	mshell->firstvar = NULL;
}
