/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:33:57 by vcordeir          #+#    #+#             */
/*   Updated: 2022/03/31 19:40:31 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

static void	analyze_token(t_parser *parser_infos)
{
	if (parser_infos->first_token || parser_infos->quoted)
	{
		parser_infos->first_token = 0;
		parser_infos->args_length++;
	}
	else if (parser_infos->isspecialchar > 0 && !parser_infos->quoted)
	{
		if (parser_infos->first_token)
			parser_infos->first_token = 0;
		parser_infos->isredirection = 1;
	}
	else if (parser_infos->isredirection)
		parser_infos->isredirection = 0;
	else
		parser_infos->args_length++;
}

static void	initialize_parser_infos(t_parser *parser_infos)
{
	parser_infos->first_token = 1;
	parser_infos->isredirection = 0;
	parser_infos->args_length = 0;
}

void	ft_create_args(t_token *token, t_cmd_table **cmd, char **path)
{
	t_parser	parser_infos;

	initialize_parser_infos(&parser_infos);
	while (token != NULL && ft_strcmp(token->token, "|\0"))
	{
		parser_infos.iscommand = ft_iscommand(path, token->token);
		parser_infos.iscmdpath = ft_iscmdpath(token->token);
		parser_infos.isspecialchar = ft_special_char(token->token);
		parser_infos.quoted = token->quoted;
		analyze_token(&parser_infos);
		token = token->next;
	}
	if (parser_infos.args_length)
		(*cmd)->args = malloc((parser_infos.args_length + 1) * sizeof(char *));
}
