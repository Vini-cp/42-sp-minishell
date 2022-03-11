/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:33:24 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/11 21:55:27 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/expander.h"

static char	*ft_expand(char *token, char **env, t_var *firstvar)
{
	char	*key;
	char	*content;
	int		counter;

	counter = 0;
	content = NULL;
	while (token[counter])
	{
		if (token[counter] == '$')
		{
			key = ft_getvarkey(token, counter);
			content = ft_getvar(key, env, firstvar);
			if (!content)
				token = ft_remove(token, key);
			else
			{
			key = ft_strjoinfree2("$", key);
			token = ft_switch(token, key, content);
			}
			token = ft_expand(token, env, firstvar);
			break ;
		}
		counter++;
	}
	return (token);
}

void	ft_expander(t_shell *mshell, char **env)
{
	t_token	*temp;

	temp = mshell->firsttoken;
	while (temp->token)
	{
		temp->token = ft_expand(temp->token, env, mshell->firstvar);
		temp = temp->next;
	}
}
