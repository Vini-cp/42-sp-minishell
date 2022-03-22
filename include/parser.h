/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 01:01:19 by vcordeir          #+#    #+#             */
/*   Updated: 2022/03/22 01:30:02 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PARSER_H
# define PARSER_H

typedef struct s_parser
{
	int	first_token;
	int	isredirection;
	int	input_redirection;
	int	output_redirection;
	int	iscommand;
	int	iscmdpath;
	int	isspecialchar;
	int	quoted;
	int	args_length;
}		t_parser;

#endif
