/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:47:57 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/25 18:20:27 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

char	**ft_getenv(t_var *var)
{
	char	**minienv;
	t_var	*temp;
	int		counter;

	counter = 0;
	temp = var;
	while (temp)
	{
		if (ft_strchr(temp->full, '='))
			counter++;
		temp = temp->next;
	}
	minienv = malloc(sizeof(char *) * (counter + 1));
	counter = 0;
	temp = var;
	while (temp)
	{
		if (ft_strchr(temp->full, '='))
		{
			minienv[counter] = ft_strdup(temp->full);
			counter++;
		}
		temp = temp->next;
	}
	return (minienv);
}
