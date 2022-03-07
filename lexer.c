/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:34:10 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/07 16:59:23 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_token *ft_createtk(void)
{
	t_token	*new;
	
	new = malloc(sizeof(*new));
	new->token = NULL;
	new->next = NULL;
	return (new);
}

static t_token	*ft_closetk(t_token *token, t_shell *mshell)
{
	int		counter;
	int		len;
	char	*tk;
	t_token	*temp;
	
	len = mshell->tkcounter - mshell->start;
	counter = 0;
	temp = token;
	tk = malloc(sizeof(char) * (len + 1));
	while (counter < len )
	{
		tk[counter] = mshell->input[mshell->start + counter];
		counter++;
	}
	tk[counter] = '\0';
	mshell->open = 0;
	temp->token = tk;
	if (mshell->input[mshell->tkcounter])
		temp->next = ft_createtk();
	temp = temp->next;
	return (temp);
}

static void	ft_handlenormal(t_shell *mshell)
{
	if (!mshell->open)
	{
		mshell->open = 1;
		mshell->start = mshell->tkcounter;
	}
	mshell->tkcounter++;
	return ;
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

static t_token	*ft_handlequotes(t_token *token, t_shell *mshell)
{
	int		chara;
	t_token	*temp;	

	temp = token;
	chara = mshell->input[mshell->tkcounter];
	if (!strchr(&mshell->input[mshell->tkcounter + 1], chara))
		ft_handlenormal(mshell);
	else
	{
		ft_handlenormal(mshell);
		while (mshell->input[mshell->tkcounter] != chara)
			ft_handlenormal(mshell);
		mshell->tkcounter++;
		temp = ft_closetk(temp, mshell);
	}
	return (temp);
}

void	ft_lexer(t_shell *mshell)
{
	t_token	*temp;
	
	temp = NULL;
	temp = ft_createtk();
	mshell->firsttoken = temp;
	while (mshell->input[mshell->tkcounter])
	{
		if (mshell->input[mshell->tkcounter] == ' ')
			temp = ft_handlespace(temp, mshell);
		else if (mshell->input[mshell->tkcounter] == 34
				|| mshell->input[mshell->tkcounter] == 39)
			temp = ft_handlequotes(temp, mshell);
		else
			ft_handlenormal(mshell);
	}
	if (mshell->open)
		temp = ft_closetk(temp, mshell);
	mshell->tkcounter = 0;
	return ;
}