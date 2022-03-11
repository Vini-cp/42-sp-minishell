/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cmd_table.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 01:12:09 by coder             #+#    #+#             */
/*   Updated: 2022/03/11 03:15:05 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

t_cmd_table	*ft_create_cmd_table(void)
{
	t_cmd_table	*new;
	
	new = malloc(sizeof(t_cmd_table));
	new->cmd = NULL;
	new->args = NULL;
	new->input_type = NO_CHAR;
	new->input_arg = NULL;
	new->output_type = NO_CHAR;
	new->output_arg = NULL;
	new->next = NULL;
	return (new);
}
