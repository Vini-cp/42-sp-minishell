/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:33:37 by chideyuk          #+#    #+#             */
/*   Updated: 2022/02/02 19:11:40 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*pdst;
	char	*psrc;
	size_t	counter;

	if (dst == NULL && src == NULL)
		return (dst);
	pdst = dst;
	psrc = (char *)src;
	counter = 0;
	while (counter < len)
	{
		pdst[counter] = psrc [counter];
		counter++;
	}
	return (dst);
}
