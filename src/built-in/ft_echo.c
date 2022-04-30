/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:16:58 by chideyuk          #+#    #+#             */
/*   Updated: 2022/04/29 23:11:20 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_echo(char	**args)
{
	char	**temp;
	int		counter;

	counter = 1;
	temp = args;
	if (temp[1] && !ft_strcmp(temp[1], "-n"))
		while (temp[counter] && !ft_strcmp(temp[counter], "-n"))
			counter++;
	while (temp[counter])
	{
		ft_putstr_fd(temp[counter], 1);
		if (temp[counter + 1])
			ft_putstr_fd(" ", 1);
		counter++;
	}
	if (!temp[1] || ft_strcmp(temp[1], "-n"))
		ft_putstr_fd("\n", 1);
	g_exit = 0;
}
