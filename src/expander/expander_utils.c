/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:34:55 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/11 21:40:11 by chideyuk         ###   ########.fr       */
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

char	*ft_getvar(char *key, char **env, t_var *variable)
{
	char	*temp;	
	int		counter;
	t_var	*tempvar;

	counter = 0;
	temp = ft_strjoin(key, "=");
	while ((env[counter]) && (ft_strncmp(env[counter], temp, ft_strlen(temp))))
		counter++;
	free(temp);
	if (env[counter])
		return (ft_strdup(ft_strchr(env[counter], '=') + 1));
	else
	{
		tempvar = variable;
		while (tempvar)
		{
			if (!ft_strcmp(tempvar->key, key))
				return (ft_strdup(tempvar->content));
			tempvar = tempvar->next;
		}
	}
	return (NULL);
}

char	*ft_switch(char *s3, char *key, char *s2)
{
	char	*temp;
	char	*result;
	int		counter;

	result = NULL;
	counter = 0;
	while (s3[counter] && (ft_strncmp(&s3[counter], key, ft_strlen(key))))
		counter++;
	if (counter)
		result = ft_substr(s3, 0, counter);
	counter = counter + ft_strlen(key);
	free(key);
	key = result;
	if (key)
		result = ft_strjoinfree1(key, s2);
	else
		result = ft_strdup(s2);
	if (s3[counter])
	{
		temp = ft_substr(s3, counter, ft_strlen(s3) - counter);
		key = result;
		result = ft_strjoinfree1(key, temp);
	}
	return (result);
}
