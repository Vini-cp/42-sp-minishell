/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_parser_infos.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 02:25:44 by vcordeir          #+#    #+#             */
/*   Updated: 2022/04/22 02:26:21 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_initialize_parser_infos(t_parser *parser_infos)
{
	parser_infos->first_token = 1;
	parser_infos->input_redirection = 0;
	parser_infos->output_redirection = 0;
	parser_infos->last_token = 0;
}
