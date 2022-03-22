/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscommand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:09:47 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/22 02:31:17 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

int	ft_iscommand(char **paths, char *cmd)
{
	int		str_position;
	char	*path;

	str_position = 0;
	while (paths[str_position] != NULL)
	{
		path = ft_strjoin(paths[str_position], cmd);
		if (ft_iscmdpath(path))
		{
			free(path);
			return (1);
		}
		free(path);
		str_position++;
	}
	return (0);
}
