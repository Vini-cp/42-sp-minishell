/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 01:32:33 by vcordeir          #+#    #+#             */
/*   Updated: 2022/03/27 01:32:47 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_initial_conditions(int fd, char ***line, char **stc)
{
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
	{
		free(*stc);
		return (-1);
	}
	if (!*stc)
		*stc = ft_calloc(1, sizeof(char));
	return (1);
}

static	int	copy_array(char *stc, char ***line, int out)
{
	if (out == 0)
		**line = ft_strdup(stc);
	else if (out > 0)
		**line = ft_substr(stc, 0, (ft_strchr(stc, '\n') - stc));
	return (out);
}

static	char	*new_tmp_array(char *static_array, char **line, int out)
{
	char	*tmp;

	if (out > 0)
		tmp = ft_strdup(static_array + (ft_strlen(*line) + 1));
	else
		tmp = ft_strdup(static_array + (ft_strlen(*line)));
	return (tmp);
}

int	get_next_line(int fd, char **line)
{
	int			out;
	char		s[BUFFER_SIZE + 1];
	char		*tmp;
	static char	*stc;

	out = 1;
	if (check_initial_conditions(fd, &line, &stc) == -1)
		return (-1);
	while (!ft_strchr(stc, '\n') && out > 0)
	{
		out = read(fd, s, BUFFER_SIZE);
		s[out] = '\0';
		tmp = ft_strjoin(stc, s);
		ft_memdel((void **)&stc);
		stc = tmp;
	}
	if (copy_array(stc, &line, out) == -1)
		return (-1);
	tmp = new_tmp_array(stc, line, out);
	ft_memdel((void **)&stc);
	stc = tmp;
	if (out == 0)
		return (0 * ft_memdel((void **)&stc));
	return (1);
}
