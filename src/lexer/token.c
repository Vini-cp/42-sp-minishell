/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:41:04 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/21 19:49:34 by chideyuk         ###   ########.fr       */
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
