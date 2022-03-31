/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:40:26 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/25 18:13:03 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_env(char **args, t_shell *mshell)
{
	t_var	*temp;

	if (args[1])
	{
		printf("env: invalid argument '%s'\n", args[1]);
		g_exit = 127;
		return ;
	}
	temp = mshell->firstvar;
	while (temp)
	{
		if (temp->full && ft_strchr(temp->full, '='))
			printf("%s\n", temp->full);
		temp = temp->next;
	}
	g_exit = 0;
}
