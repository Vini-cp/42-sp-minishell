/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:33:37 by chideyuk          #+#    #+#             */
/*   Updated: 2022/02/02 19:13:28 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	counter;

	if (len == 0)
		return (0);
	counter = 0;
	while ((*s1 != '\0') && (*s2 != '\0')
		&& (counter < len - 1) && (*s1 == *s2))
	{
		s1++;
		s2++;
		counter++;
	}
	return (((unsigned char) *s1) - ((unsigned char) *s2));
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	counter;

	counter = 0;
	while (((*s1 != '\0') || (*s2 != '\0')) && (*s1 == *s2))
	{
		s1++;
		s2++;
		counter++;
	}
	return (((unsigned char) *s1) - ((unsigned char) *s2));
}
