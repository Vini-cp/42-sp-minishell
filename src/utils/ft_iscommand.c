/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscommand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:09:47 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/25 18:20:59 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

int	ft_iscommand(char **paths, char *cmd)
{
	int		str_position;
	char	*path;

	str_position = 0;
	if (ft_strcmp(cmd, "cd\0") == 0 || ft_strcmp(cmd, "export\0") == 0
		|| ft_strcmp(cmd, "unset\0") == 0 || ft_strcmp(cmd, "exit\0") == 0)
		return (1);
	while (paths && paths[str_position] != NULL)
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
