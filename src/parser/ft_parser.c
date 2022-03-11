/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:34:27 by coder             #+#    #+#             */
/*   Updated: 2022/03/11 15:46:50 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"
#include <stdio.h>

static void handle_special_char(int s_char, t_cmd_table **cmd, t_shell *mshell)
{
	if (s_char == 0)
	{
		(*cmd)->next = ft_create_cmd_table();
		*cmd = (*cmd)->next;
		mshell->start = 1;
	}
	else if (s_char == 1 || s_char == 2)
	{
		mshell->cmd_output = 1;
		if (s_char == 1)
			(*cmd)->output_type = ONE_CHAR;
		else
			(*cmd)->output_type = TWO_CHARS;
	}
	else
	{
		mshell->cmd_input = 1;
		if (s_char == 3)
			(*cmd)->input_type = ONE_CHAR;
		else
			(*cmd)->input_type = TWO_CHARS;
	}
}

static void analyze_token(char* token, t_cmd_table **cmd, t_shell *mshell)
{
	int special_char;

	special_char = ft_special_char(token);
	if (mshell->start == 1 && ft_iscommand(mshell, token))
		(*cmd)->cmd = token;
	else if (special_char >= 0)
		handle_special_char(special_char, cmd, mshell);
	else if (mshell->cmd_input == 1)
	{
		(*cmd)->input_arg = token;
		mshell->cmd_input = 0;
	}
	else if (mshell->cmd_output == 1)
	{
		(*cmd)->output_arg = token;
		mshell->cmd_output = 0;
	}
	else
		(*cmd)->args = ft_concatenate((*cmd)->args, token);
	if (special_char != 0)
		mshell->start = 0;
}

void	ft_parser(t_shell *mshell)
{
	t_token		*temp_tok;
	t_cmd_table	*cmd = ft_create_cmd_table();

	temp_tok = mshell->firsttoken;
	mshell->cmdtable = cmd;
	mshell->start = 1;
	mshell->cmd_input = 0;
	mshell->cmd_output = 0;
	while(temp_tok != NULL)
	{
		analyze_token(temp_tok->token, &cmd, mshell);
		temp_tok = temp_tok->next;
	}
}
