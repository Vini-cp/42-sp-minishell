/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iscommand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:09:47 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/10 18:31:51 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_check(char *path, char *arg)
{
	char	*newpath;
	int		fd;

	newpath = ft_strjoin(path, arg);
	fd = open(newpath, O_RDONLY);
	close(fd);
	free(newpath);
	return (fd);
}

int	ft_iscommand(t_shell *mshell, char *str)
{
	char	**paths;
	int		counter;
	int		found;

	paths = mshell->path;
	counter = 0;
	while (paths[counter] && !found)
	{
		found = ft_check(paths[counter], str);
		counter++;
	}
	return (found);
}
