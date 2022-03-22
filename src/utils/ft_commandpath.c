/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commandpath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:21:27 by vcordeir          #+#    #+#             */
/*   Updated: 2022/03/22 19:54:52 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

char	*ft_commandpath(char **paths, char *cmd)
{
	int		str_position;
	char	*path;

	str_position = 0;
	while (paths[str_position])
	{
		path = ft_strjoin(paths[str_position], cmd);
		if (ft_iscmdpath(path))
			return (path);
		str_position++;
	}
	return (NULL);
}
