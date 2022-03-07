/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:33:37 by chideyuk          #+#    #+#             */
/*   Updated: 2022/02/02 19:13:20 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*smod;
	unsigned int	counter;
	unsigned int	len;

	len = ft_strlen(s);
	smod = malloc(len + 1);
	if (smod == NULL)
		return (NULL);
	counter = 0;
	while (counter < len)
	{
		smod[counter] = f(counter, s[counter]);
		counter++;
	}
	smod[counter] = '\0';
	return (smod);
}
