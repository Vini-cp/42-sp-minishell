/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:47:57 by chideyuk          #+#    #+#             */
/*   Updated: 2022/04/22 02:35:56 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

static int	get_number_of_paths(t_var *var)
{
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
	return (counter);
}

static char	**get_env_paths(t_var *var, int no_paths)
{
	char	**minienv;
	int		counter;
	t_var	*temp;

	counter = 0;
	temp = var;
	minienv = malloc(sizeof(char *) * (no_paths + 1));
	while (temp)
	{
		if (ft_strchr(temp->full, '='))
		{
			minienv[counter] = ft_strdup(temp->full);
			counter++;
		}
		temp = temp->next;
	}
	minienv[counter] = NULL;
	return (minienv);
}

char	**ft_getenv(t_var *var)
{
	char	**minienv;
	int		no_paths;

	no_paths = get_number_of_paths(var);
	minienv = get_env_paths(var, no_paths);
	return (minienv);
}
