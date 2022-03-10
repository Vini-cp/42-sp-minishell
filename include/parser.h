/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 02:46:09 by coder             #+#    #+#             */
/*   Updated: 2022/03/10 17:27:26 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "shell.h"

typedef enum e_token_type
{
	CHAR_PIPE = '|',
	CHAR_GREATER = '>',
	CHAR_LESSER = '<',
	CHAR_DOLLAR = '$',
	CHAR_QUESTION = '?'
} t_token_type;

typedef enum e_in_out_type
{
	NO_CHAR,
	ONE_CHAR,
	TWO_CHARS
} t_in_out_type;

t_cmd_table	*ft_create_cmd_table(void);

#endif
