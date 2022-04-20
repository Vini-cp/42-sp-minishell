/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:14:49 by chideyuk          #+#    #+#             */
/*   Updated: 2022/04/20 21:40:10 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

static int	ft_isredir(char *token)
{
	if (!ft_strcmp(token, "|") || !ft_strcmp(token, ">") || !ft_strcmp(token, ">>")
		|| !ft_strcmp(token, "<") || !ft_strcmp(token, "<<"))
		return (1);
	return (0);
}

int	ft_inputerror(t_token	*token)
{
	t_token	*temp;

	temp = token;
	while (temp)
	{
		if (temp->quoted == 0 && ft_isredir(temp->token))
		{
			if (!temp->next)
			{
				printf("minishell: syntax error near unexpected token `newline'\n");
				return (1);
			}
			else
			{
				if (temp->next->quoted == 0 && ft_isredir(temp->next->token))
				{
					printf("minishell: syntax error near unexpected token `%s'\n", temp->next->token);
					return (1);
				}
			}
		}
		temp = temp->next;
	}
	return (0);
}
