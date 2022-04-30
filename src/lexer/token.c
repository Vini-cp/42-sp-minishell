/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:41:04 by chideyuk          #+#    #+#             */
/*   Updated: 2022/04/29 21:46:31 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"

t_token	*ft_createtk(void)
{
	t_token	*new;

	new = malloc(sizeof(*new));
	new->token = NULL;
	new->next = NULL;
	new->quoted = 0;
	return (new);
}

t_token	*ft_addtk(t_shell *mshell)
{
	t_token	*temp;

	temp = mshell->firsttoken;
	while (temp->next)
		temp = temp->next;
	temp->next = ft_createtk();
	temp = temp->next;
	return (temp);
}

void	ft_freetokens(t_shell *mshell)
{
	t_token	*temp;
	t_token	*temp2;

	temp = mshell->firsttoken;
	while (temp)
	{
		free(temp->token);
		temp->token = NULL;
		temp2 = temp;
		temp = temp->next;
		free(temp2);
		temp2 = NULL;
	}
	mshell->firsttoken = NULL;
}

t_token	*ft_closetk(t_token *token, t_shell *mshell)
{
	size_t		len;
	char		*tk;
	t_token		*temp;
	int			space;

	space = 1;
	len = mshell->tkcounter - mshell->start;
	tk = ft_substr(mshell->input, mshell->start, len);
	temp = token;
	mshell->open = 0;
	temp->token = tk;
	while (mshell->input[mshell->tkcounter]
		&& mshell->input[mshell->tkcounter + space])
	{
		if (!ft_isspace(mshell->input[mshell->tkcounter + space]))
		{
			space = 0;
			break ;
		}
		space++;
	}
	if (!space && mshell->input[mshell->tkcounter]
		&& mshell->input[mshell->tkcounter + 1])
			temp->next = ft_createtk();
	return (temp->next);
}
