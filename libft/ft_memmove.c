/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:33:37 by chideyuk          #+#    #+#             */
/*   Updated: 2022/02/02 19:11:47 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pdst;
	char	*psrc;
	size_t	counter;

	if (dst == NULL && src == NULL)
		return (dst);
	pdst = dst;
	psrc = (char *)src;
	counter = 0;
	if (pdst > psrc)
	{
		while ((int)--len >= 0)
			pdst[len] = psrc[len];
	}
	else
	{
		while (counter < len)
		{
			pdst[counter] = psrc [counter];
			counter++;
		}
	}
	return (dst);
}
