/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commandpath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:21:27 by vcordeir          #+#    #+#             */
/*   Updated: 2022/03/29 17:04:27 by chideyuk         ###   ########.fr       */
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
		free (path);
		str_position++;
	}
	return (NULL);
}
