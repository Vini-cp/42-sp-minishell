/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:40:26 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/18 02:47:45 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_env(t_shell *mshell, char **args)
{
	t_var	temp;

	if (args[1])
	{
		printf("env: invalid argument '%s'\n", args[1]);
		global_exit = 127;
		return ;
	}
	temp = mshell->firstvar;
	while (temp)
	{
		if (temp->full && ft_strchr(temp->full, '='))
			printf("%s\n", temp->full);
		temp = temp->next;
	}
	global_exit = 0;
}
