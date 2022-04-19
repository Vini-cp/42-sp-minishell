/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:34:10 by chideyuk          #+#    #+#             */
/*   Updated: 2022/04/19 22:56:43 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"

void	ft_lexer(t_shell *mshell)
{
	t_token	*temp;

	while (mshell->input[mshell->tkcounter] == ' ')
		mshell->tkcounter++;
	if (!mshell->input[mshell->tkcounter])
		return ;
	temp = NULL;
	temp = ft_createtk();
	mshell->firsttoken = temp;
	while (mshell->input[mshell->tkcounter])
	{
		if (mshell->input[mshell->tkcounter] == ' '
			|| mshell->input[mshell->tkcounter] == '|'
			|| mshell->input[mshell->tkcounter] == '<'
			|| mshell->input[mshell->tkcounter] == '>')
			temp = ft_handlespecial(temp, mshell);
		else if (mshell->input[mshell->tkcounter] == SINGLE_QUOTES
			|| mshell->input[mshell->tkcounter] == DOUBLE_QUOTES)
			ft_handlequotes(mshell);
		else
			ft_handlenormal(mshell);
	}
	if (mshell->open)
		temp = ft_closetk(temp, mshell);
	mshell->tkcounter = 0;
}
