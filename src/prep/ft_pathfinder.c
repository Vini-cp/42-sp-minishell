/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:18:15 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/17 16:20:37 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

char	**ft_pathfinder(t_shell *mshell)
{
	int		counter;
	t_var	*temp;
	char	**split;

	temp = mshell->firstvar;
	while (temp && ft_strcmp(temp->key, "PATH"))
		temp = temp->next;
	if (!temp || temp->content == NULL)
		return (NULL);
	split = ft_split(temp->content, ':');
	counter = 0;
	while (split[counter])
	{
		split[counter] = ft_strjoinfree1(split[counter], "/");
		counter++;
	}
	return (split);
}
