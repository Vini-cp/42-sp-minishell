/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:41:04 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/09 15:06:09 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"

t_token	*ft_createtk(void)
{
	t_token	*new;

	new = malloc(sizeof(*new));
	new->token = NULL;
	new->next = NULL;
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
		temp2 = temp;
		temp = temp->next;
		free(temp2);
	}
}
