/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:34:55 by chideyuk          #+#    #+#             */
/*   Updated: 2022/04/29 16:59:35 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/expander.h"

char	*ft_getvarkey(char	*str, int counter)
{
	char	*key;
	int		len;
	int		start;

	counter++;
	start = counter;
	len = 0;
	while ((str[counter] == '_' || ft_isalnum(str[counter]))
		&& (str[counter]))
	{
		len++;
		counter++;
	}
	key = ft_substr(str, start, len);
	return (key);
}

char	*ft_getvar(char *key, t_var *variable)
{
	t_var	*tempvar;

	tempvar = variable;
	while (tempvar)
	{
		if (!ft_strcmp(tempvar->key, key))
			return (ft_strdup(tempvar->content));
		tempvar = tempvar->next;
	}
	return (NULL);
}

char	*ft_switch(char *token, char *key, char *content, int counter)
{
	char	*temp;
	char	*result;

	result = NULL;
	if (counter)
		result = ft_substr(token, 0, counter);
	counter = counter + ft_strlen(key);
	free(key);
	key = result;
	if (key)
		result = ft_strjoin(key, content);
	else
		result = ft_strdup(content);
	free(key);
	if (token[counter])
	{
		temp = ft_substr(token, counter, ft_strlen(token) - counter);
		key = result;
		result = ft_strjoinfreeboth(key, temp);
	}
	free(token);
	return (result);
}

char	*ft_remove(char *token, char *key, int counter)
{
	char	*start;
	char	*end;
	char	*result;

	if (!counter)
		result = ft_substr(token, ft_strlen(key), ft_strlen(token));
	else
	{
		start = ft_substr(token, 0, counter);
		counter = counter + ft_strlen(key);
		end = ft_substr(token, counter, ft_strlen(token) - counter);
		result = ft_strjoinfreeboth(start, end);
	}
	free (token);
	return (result);
}

int	ft_treatdquote(char *token, int counter, int dquotes)
{
	if (!dquotes && ft_strchr(&token[counter + 1], '\"'))
		return (1);
	return (0);
}
