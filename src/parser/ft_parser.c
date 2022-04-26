/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:34:27 by coder             #+#    #+#             */
/*   Updated: 2022/04/26 20:54:04 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

static void	analyze_parser_infos(	t_parser *parser_infos,
									t_cmd_table **cmd,
									t_token	*temp_tok,
									t_shell *mshell)
{
	if (parser_infos->first_token)
		ft_create_args(temp_tok, cmd, mshell->path);
	parser_infos->iscmdpath = ft_iscmdpath(temp_tok->token);
	parser_infos->isspecialchar = ft_special_char(temp_tok->token);
	if (parser_infos->isspecialchar == 0)
		mshell->no_cmds++;
	parser_infos->quoted = temp_tok->quoted;
	if (temp_tok->next == NULL)
		parser_infos->last_token = 1;
}

static void	handle_special_char(int s_char,
								t_cmd_table **cmd,
								t_parser *parser_infos)
{
	if (parser_infos->first_token)
		parser_infos->first_token = 0;
	if (s_char == 0)
	{
		(*cmd)->args[(*cmd)->no_args] = NULL;
		(*cmd)->next = ft_create_cmd_table();
		*cmd = (*cmd)->next;
		ft_initialize_parser_infos(parser_infos);
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
		parser_infos->input_redirection = 1;
		if (s_char == 3)
			(*cmd)->input_type = ONE_CHAR;
		else
			(*cmd)->input_type = TWO_CHARS;
	}
}

static void	handle_cmd(char *token, t_cmd_table **cmd, t_parser *parser_infos)
{
	(*cmd)->cmd = ft_strdup(token);
	if (parser_infos->iscmdpath)
		(*cmd)->cmd_path = ft_strdup(token);
	else
		(*cmd)->cmd_path = ft_commandpath(parser_infos->path, token);
	if (!(*cmd)->cmd_path)
		(*cmd)->cmd_path = ft_strdup(token);
	(*cmd)->args[(*cmd)->no_args] = ft_strdup(token);
	parser_infos->first_token = 0;
	(*cmd)->no_args++;
}

static void	analyze_token(char *token,
							t_cmd_table **cmd,
							t_parser *parser_infos)
{
	if (parser_infos->first_token && (parser_infos->isspecialchar == -1
			|| (parser_infos->isspecialchar >= 0 && parser_infos->quoted)))
		handle_cmd(token, cmd, parser_infos);
	else if (parser_infos->isspecialchar >= 0 && !parser_infos->quoted)
		handle_special_char(parser_infos->isspecialchar, cmd, parser_infos);
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
	if ((*cmd)->args && parser_infos->last_token)
		(*cmd)->args[(*cmd)->no_args] = NULL;
}

void	ft_parser(t_shell *mshell)
{
	t_token		*temp_tok;
	t_cmd_table	*cmd;
	t_parser	parser_infos;

	cmd = ft_create_cmd_table();
	ft_pathfinder(mshell);
	ft_initialize_parser_infos(&parser_infos);
	parser_infos.path = mshell->path;
	temp_tok = mshell->firsttoken;
	mshell->cmdtable = cmd;
	mshell->no_cmds = 1;
	while (temp_tok != NULL)
	{
		analyze_parser_infos(&parser_infos, &cmd, temp_tok, mshell);
		analyze_token(temp_tok->token, &cmd, &parser_infos);
		temp_tok = temp_tok->next;
	}
}
