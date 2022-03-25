/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:36:18 by coder             #+#    #+#             */
/*   Updated: 2022/03/25 18:21:13 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

int	ft_special_char(char *str)
{
	if (ft_strcmp(str, "|\0") == 0)
		return (0);
	if (ft_strcmp(str, ">\0") == 0)
		return (1);
	if (ft_strcmp(str, ">>\0") == 0)
		return (2);
	if (ft_strcmp(str, "<\0") == 0)
		return (3);
	if (ft_strcmp(str, "<<\0") == 0)
		return (4);
	return (-1);
}
