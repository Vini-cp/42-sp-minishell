/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:36:05 by chideyuk          #+#    #+#             */
/*   Updated: 2022/04/29 21:42:21 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lexer.h"

void	ft_handlenormal(t_shell *mshell)
{
	if (!mshell->open)
	{
		mshell->open = 1;
		mshell->start = mshell->tkcounter;
	}
	mshell->tkcounter++;
}

t_token	*ft_handleredir(t_token *token, t_shell *mshell)
{
	t_token	*temp;

	temp = token;
	if (mshell->open)
			temp = ft_closetk(temp, mshell);
	if (!temp)
		temp = ft_addtk(mshell);
	mshell->start = mshell->tkcounter;
	mshell->tkcounter++;
	if (mshell->input[mshell->tkcounter]
		&& mshell->input[mshell->start] != '|'
		&& (mshell->input[mshell->start] == mshell->input[mshell->tkcounter]))
		mshell->tkcounter++;
	temp = ft_closetk(temp, mshell);
	if (!temp && mshell->input[mshell->tkcounter]
		&& !ft_isspace(mshell->input[mshell->tkcounter]))
		temp = ft_addtk(mshell);
	return (temp);
}

t_token	*ft_handlespecial(t_token *token, t_shell *mshell)
{
	t_token	*temp;

	temp = token;
	if (ft_isspace(mshell->input[mshell->tkcounter]))
	{
		if (!mshell->open)
			mshell->tkcounter++;
		else
			temp = ft_closetk(temp, mshell);
	}
	else
		temp = ft_handleredir(temp, mshell);
	return (temp);
}

void	ft_handlequotes(t_shell *mshell)
{
	int		chara;

	chara = mshell->input[mshell->tkcounter];
	if (!ft_strchr(&mshell->input[mshell->tkcounter + 1], chara))
		ft_handlenormal(mshell);
	else
	{
		ft_handlenormal(mshell);
		while (mshell->input[mshell->tkcounter] != chara)
			ft_handlenormal(mshell);
		mshell->tkcounter++;
	}
}
