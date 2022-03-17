/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:20:08 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/17 16:31:24 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

static t_var	*ft_createvar(char *entry)
{
	char	**split;
	t_var	*var;

	var = malloc(sizeof(*var));
	split = ft_split(entry, '=');
	var->full = ft_strdup(entry);
	var->key = ft_strdup(split[0]);
	var->content = ft_strdup(split[1]);
	var->next = NULL;
	ft_freeptr(split);
	return (var);
}

void	ft_startenv(t_shell *mshell, char **env)
{
	t_var	*temp;
	int		counter;

	counter = 1;
	temp = NULL;
	temp = ft_createvar(env[0]);
	mshell->firstvar = temp;
	while (env[counter])
	{
		temp->next = ft_createvar(env[counter]);
		temp = temp->next;
		counter++;
	}
}
