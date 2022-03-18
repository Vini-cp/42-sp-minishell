/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:34:10 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/18 20:04:43 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"

static t_token	*ft_closetk(t_token *token, t_shell *mshell)
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
		if (mshell->input[mshell->tkcounter + space] != ' ')
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

static void	ft_handlenormal(t_shell *mshell)
{
	if (!mshell->open)
	{
		mshell->open = 1;
		mshell->start = mshell->tkcounter;
	}
	mshell->tkcounter++;
}

static t_token	*ft_handlespace(t_token *token, t_shell *mshell)
{
	t_token	*temp;

	temp = token;
	if (!mshell->open)
		mshell->tkcounter++;
	else
		temp = ft_closetk(temp, mshell);
	return (temp);
}

static void	ft_handlequotes(t_shell *mshell)
{
	int		chara;

	chara = mshell->input[mshell->tkcounter];
	if (!strchr(&mshell->input[mshell->tkcounter + 1], chara))
		ft_handlenormal(mshell);
	else
	{
		ft_handlenormal(mshell);
		while (mshell->input[mshell->tkcounter] != chara)
			ft_handlenormal(mshell);
		mshell->tkcounter++;
	}
}

void	ft_lexer(t_shell *mshell)
{
	t_token	*temp;

	while (mshell->input[mshell->tkcounter] == ' ')
		mshell->tkcounter++;
	if (!mshell->input[mshell->tkcounter])
	{
		mshell->tkcounter = 0;
		return ;
	}
	temp = NULL;
	temp = ft_createtk();
	mshell->firsttoken = temp;
	while (mshell->input[mshell->tkcounter])
	{
		if (mshell->input[mshell->tkcounter] == ' ')
			temp = ft_handlespace(temp, mshell);
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
