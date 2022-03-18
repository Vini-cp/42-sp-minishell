/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concatenate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 02:27:07 by coder             #+#    #+#             */
/*   Updated: 2022/03/18 15:02:02 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

char	*ft_concatenate(char *left, char *right, char middle)
{
	int		str_len;
	char	*str;

	if (left)
	{
		str_len = ft_strlen(left) + ft_strlen(right) + 2;
		str = malloc(str_len * sizeof(char));
		ft_strlcpy(str, left, ft_strlen(left) + 1);
		str[ft_strlen(left)] = middle;
		ft_strlcpy(str + (ft_strlen(left) + 1), right, ft_strlen(right) + 1);
	}
	else
	{
		str_len = ft_strlen(right) + 1;
		str = malloc(str_len * sizeof(char));
		ft_strlcpy(str, right, ft_strlen(right) + 1);
	}
	return (str);
}
