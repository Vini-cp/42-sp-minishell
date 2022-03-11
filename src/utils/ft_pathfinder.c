/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:18:15 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/10 22:27:31 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

char	**ft_pathfinder(char **env)
{
	int		counter;
	char	*temp;
	char	**split;

	counter = 0;
	while ((env[counter]) && (ft_strncmp(env[counter], "PATH=", 5)))
		counter++;
	if (!env[counter])
		return (NULL);
	temp = ft_strdup(ft_strchr(env[counter], '=') + 1);
	split = ft_split(temp, ':');
	counter = 0;
	free(temp);
	while (split[counter])
	{
		temp = split[counter];
		split[counter] = ft_strjoin(temp, "/");
		counter++;
	}
	return (split);
}
