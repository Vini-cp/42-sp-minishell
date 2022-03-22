/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscmdpath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 03:03:43 by vcordeir          #+#    #+#             */
/*   Updated: 2022/03/22 02:30:34 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

/*	
	On success, zero is returned.
	On error, -1 is returned,
	and errno is set appropriately.
	- F_OK tests for the existence of the file. 
*/

int	ft_iscmdpath(char *path)
{
	if (access(path, F_OK) == 0)
		return (1);
	return (0);
}
