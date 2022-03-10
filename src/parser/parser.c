/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:34:27 by coder             #+#    #+#             */
/*   Updated: 2022/03/10 02:20:24 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"
#include <stdio.h>

static void handle_normal(char* token, t_shell *mshell)
{
	if (ft_isalpha(token[0]))
	{
		if (mshell->start == 1)
			(mshell->cmdtable)->cmd = token;
		else if (mshell->input == 1)
		{
			(mshell->cmdtable)->input_arg = token;
			mshell->input = 0;
		}
		else if (mshell->output == 1)
		{
			(mshell->cmdtable)->output_arg = token;
			mshell->output = 0;
		}
		else
		{
			if ((mshell->cmdtable)->args == NULL)
		}
	}	
	else if (token[0] == CHAR_DOLLAR)
}

static void handle_two_chars(char* token, t_shell *mshell)
{
	if (mshell->start == 1)
		mshell->start = 0;
	if (token[0] == CHAR_GREATER && token[1] == CHAR_GREATER)

	else if (token[0] == CHAR_LESSER && token[1] == CHAR_LESSER)
		
	else if (token[0] == CHAR_DOLLAR && token[1] == CHAR_QUESTION)
}

static void handle_one_char(char* token, t_shell *mshell)
{
	if (mshell->start == 1)
		mshell->start = 0;
	if (token[0] == CHAR_GREATER)
	{
		(mshell->cmdtable)->output_type = ONE_CHAR;
		mshell->output = 1;
	}
	else if (token[0] == CHAR_LESSER)
	{
		(mshell->cmdtable)->input_type = ONE_CHAR;
		mshell->input = 1;
	}
	else if (token[0] == CHAR_PIPE)
	{
		(mshell->cmdtable) = (mshell->cmdtable)->next;
		mshell->start = 1;
	}
}

static void	check_token(char* token, t_shell *mshell)
{
	if (ft_strlen(token) > 2)
		handle_normal(token, mshell);
	else if (ft_strlen(token) == 2)
		handle_two_chars(token, mshell);
	else if (ft_strlen(token) == 1)
		handle_one_char(token, mshell);
}

void	ft_parser(t_shell *mshell)
{
	t_token		*temp_tok;
	t_cmd_table	*temp_table = ft_create_cmd_table();

	temp_tok = mshell->firsttoken;
	mshell->cmdtable = temp_table;
	mshell->start = 1;
	mshell->input = 0;
	mshell->output = 0;
	while(temp_tok != NULL)
	{
		check_token(temp_tok->token, mshell);
		printf("Tok: %s\n", temp_tok->token);
		temp_tok = temp_tok->next;
	}
}
