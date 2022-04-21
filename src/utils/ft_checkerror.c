/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:14:49 by chideyuk          #+#    #+#             */
/*   Updated: 2022/04/21 21:31:10 by chideyuk         ###   ########.fr       */
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

	error = strdup("minishell: syntax error near unexpected token ");
	temp = token;
	while (temp)
	{
		if (temp->quoted == 0 && ft_isredir(temp->token) > 0)
		{
			if (!temp->next)
			{
				printf("%s`newline'\n", error);
				g_exit = 2;
			}
			else if (ft_isredir(temp->token) > 1 && temp->next->quoted == 0
				&& !ft_strcmp(temp->next->token, "|"))
			{
				printf("%s`%s'\n", error, temp->next->token);
				g_exit = 2;
			}
		}
		temp = temp->next;
	}
	free(error);
	return (g_exit);
}
