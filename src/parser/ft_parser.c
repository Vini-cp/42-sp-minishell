/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:34:27 by coder             #+#    #+#             */
/*   Updated: 2022/03/22 04:16:31 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

static void handle_special_char(int s_char, t_cmd_table **cmd, t_parser *parser_infos)
{
	if (parser_infos->first_token)
			parser_infos->first_token = 0;
	if (s_char == 0)
	{
		(*cmd)->next = ft_create_cmd_table();
		*cmd = (*cmd)->next;
		initialize_parser_infos(parser_infos);
	}
	else if (s_char == 1 || s_char == 2)
	{
		parser_infos->output_redirection = 1;
		if (s_char == 1)
			(*cmd)->output_type = ONE_CHAR;
		else
			(*cmd)->output_type = TWO_CHARS;
	}
	else
	{
		parser_infos->input_redirection= 1;
		if (s_char == 3)
			(*cmd)->input_type = ONE_CHAR;
		else
			(*cmd)->input_type = TWO_CHARS;
	}
}

static void handle_cmd(char* token, t_cmd_table **cmd, t_parser *parser_infos)
{
	if (parser_infos->iscommand)
		(*cmd)->cmd = ft_strdup(token);
	else if (parser_infos->iscmdpath)
		(*cmd)->cmd_path = ft_strdup(token);
	(*cmd)->args[(*cmd)->no_args] = ft_strdup(token);
	parser_infos->first_token = 0;
	(*cmd)->no_args++;
}

static void analyze_token(char* token, t_cmd_table **cmd, t_parser *parser_infos)
{
	if (parser_infos->first_token)
		handle_cmd(token, cmd, parser_infos);
	else if (special_char >= 0 && !parser_infos->quoted)
		handle_special_char(special_char, cmd, parser_infos);
	else if (parser_infos->input_redirection == 1)
	{
		(*cmd)->input_arg = ft_strdup(token);
		parser_infos->input_redirection = 0;
	}
	else if (parser_infos->output_redirection == 1)
	{
		(*cmd)->output_arg = ft_strdup(token);
		parser_infos->output_redirection = 0;
	}
	else
	{
		(*cmd)->args[(*cmd)->no_args] = ft_strdup(token);
		(*cmd)->no_args++;
	}
}


static void	initialize_parser_infos(t_parser *parser_infos)
{
	parser_infos->first_token = 1;
	parser_infos->input_redirection = 0;
	parser_infos->output_redirection = 0;
}

void	ft_parser(t_shell *mshell)
{
	t_token		*temp_tok;
	t_cmd_table	*cmd = ft_create_cmd_table();
	t_parser parser_infos;

	initialize_parser_infos(&parser_infos);
	temp_tok = mshell->firsttoken;
	mshell->cmdtable = cmd;
	while(temp_tok != NULL)
	{
		if (parser_infos.first_token)
			ft_create_args(temp_tok, &cmd, mshell->path);
		parser_infos.iscommand = ft_iscommand(path, token->token);
		parser_infos.iscmdpath = ft_iscmdpath(token->token);
		parser_infos.isspecialchar = ft_special_char(token->token);
		parser_infos.quoted = token->quoted;
		analyze_token(temp_tok->token, &cmd, &parser_infos);
		temp_tok = temp_tok->next;
	}
}
