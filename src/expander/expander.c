/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:33:24 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/15 17:59:09 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/expander.h"

static int	ft_treatsquote(char *token, int counter, int dquotes)
{
	if (!dquotes && strchr(&token[counter + 1], '\''))
	{	
		counter++;
		while (token[counter] != '\'')
			counter++;
	}
	counter++;
	return (counter);
}

static char	*ft_treatdollar(char *token, char **env, t_var *firstvar, int count)
{
	char	*key;
	char	*content;

	key = ft_getvarkey(token, count);
	content = ft_getvar(key, env, firstvar);
	key = ft_strjoinfree2("$", key);
	if (!content)
	{
		token = ft_remove(token, key, count);
		free(key);
	}
	else
	{
		token = ft_switch(token, key, content, count);
		free(content);
	}
	return (token);
}

static char	*ft_expand(char *token, char **env, t_var *firstvar)
{
	int		counter;
	int		dquotes;

	counter = 0;
	dquotes = 0;
	while (token[counter])
	{
		if (token[counter] == '\"')
		{
			dquotes = ft_treatdquote(token, counter, dquotes);
			counter++;
		}
		else if (token[counter] == '\'')
			counter = ft_treatsquote(token, counter, dquotes);
		else if (token[counter] == '$')
		{
			token = ft_treatdollar(token, env, firstvar, counter);
			token = ft_expand(token, env, firstvar);
			break ;
		}
		else
			counter++;
	}
	return (token);
}

void	ft_expander(t_shell *mshell, char **env)
{
	t_token	*temp;

	temp = mshell->firsttoken;
	while (temp && temp->token)
	{
		temp->token = ft_expand(temp->token, env, mshell->firstvar);
		temp->token = ft_trimquotes(temp->token);
		temp = temp->next;
	}
}
