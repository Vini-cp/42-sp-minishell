/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:18:15 by chideyuk          #+#    #+#             */
/*   Updated: 2022/04/21 03:54:38 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_pathfinder(t_shell *mshell)
{
	int		counter;
	t_var	*temp;

	if (mshell->path)
	{
		ft_freeptr(mshell->path);
		mshell->path = NULL;
	}
	temp = mshell->firstvar;
	while (temp && ft_strcmp(temp->key, "PATH"))
		temp = temp->next;
	if (!temp || temp->content == NULL)
		return ;
	mshell->path = ft_split(temp->content, ':');
	counter = 0;
	while (mshell->path[counter])
	{
		mshell->path[counter] = ft_strjoinfree1(mshell->path[counter], "/");
		counter++;
	}
	mshell->path[counter] = NULL;
}
