/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cmd_table.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 01:12:09 by coder             #+#    #+#             */
/*   Updated: 2022/03/22 03:19:16 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

t_cmd_table	*ft_create_cmd_table(void)
{
	t_cmd_table	*new;
	
	new = malloc(sizeof(t_cmd_table));
	new->cmd = NULL;
	new->cmd_path = NULL;
	no_args = 0;
	new->args = NULL;
	new->input_type = NO_CHAR;
	new->input_arg = NULL;
	new->output_type = NO_CHAR;
	new->output_arg = NULL;
	new->next = NULL;
	return (new);
}
