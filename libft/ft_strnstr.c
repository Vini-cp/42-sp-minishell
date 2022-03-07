/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:33:37 by chideyuk          #+#    #+#             */
/*   Updated: 2022/02/02 19:13:36 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	c1;
	size_t	c2;
	size_t	c3;

	c1 = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[c1] != '\0' && c1 < len)
	{
		c2 = 0;
		c3 = c1;
		while (little[c2] == big[c3] && big[c3] != '\0'
			&& little[c2] != '\0' && c3 < len)
		{
			c2++;
			c3++;
		}
		if (little[c2] == '\0')
			return ((char *)&big[c1]);
		c1++;
	}
	return (NULL);
}
