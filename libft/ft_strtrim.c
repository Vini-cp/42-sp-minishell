/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:33:37 by chideyuk          #+#    #+#             */
/*   Updated: 2022/02/02 19:13:50 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_trimaux(char const *s1, char const *set, size_t len)
{
	size_t	counter;

	if (*s1 == '\0')
		return (0);
	counter = 0;
	while (set[counter] != '\0')
	{
		if (s1[len - 1] == set[counter])
		{
			len--;
			counter = 0;
		}
		else
			counter++;
	}
	return (len);
}

char	*ft_strtrim(char const	*s1, char const	*set)
{
	char	*s2;
	size_t	len;
	size_t	counter;

	len = ft_strlen(s1);
	counter = 0;
	while (set[counter] != '\0')
	{
		if (*s1 == set[counter])
		{
			s1++;
			counter = 0;
			len--;
		}
		else
			counter++;
	}
	counter = 0;
	len = ft_trimaux(s1, set, len);
	s2 = malloc(len + 1);
	if (s2 == NULL)
		return (NULL);
	ft_memcpy(s2, s1, len);
	s2[len] = '\0';
	return (s2);
}
