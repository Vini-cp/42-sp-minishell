/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:14:49 by chideyuk          #+#    #+#             */
/*   Updated: 2022/04/29 16:57:23 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

static int	ft_isredir(char *token)
{
	if (!ft_strcmp(token, ">>") || !ft_strcmp(token, "<")
		|| !ft_strcmp(token, "<<"))
		return (2);
	else if (!ft_strcmp(token, "|") || !ft_strcmp(token, ">"))
		return (1);
	else
		return (0);
}

int	ft_inputerror(t_token	*token)
{
	t_token	*temp;
	char	*error;
	int		ret;

	ret = 0;
	error = ft_strdup("minishell: syntax error near unexpected token ");
	temp = token;
	if (!ft_strcmp(temp->token, "|"))
		return (printf("%s`|'\n", error));
	while (temp)
	{
		if (temp->quoted == 0 && ft_isredir(temp->token) > 0)
		{
			if (!temp->next)
				ret = printf("%s`newline'\n", error);
			else if (ft_isredir(temp->next->token) > 0
				&& temp->next->quoted == 0)
				ret = printf("%s`%s'\n", error, temp->next->token);
		}
		if (ret)
			break ;
		temp = temp->next;
	}
	free(error);
	return (ret);
}
