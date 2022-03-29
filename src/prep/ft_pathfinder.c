/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:18:15 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/29 18:23:36 by chideyuk         ###   ########.fr       */
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
}
