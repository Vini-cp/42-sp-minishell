/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:33:37 by chideyuk          #+#    #+#             */
/*   Updated: 2022/02/02 19:17:17 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convert(int n, int len, char *ptr)
{
	ptr[len] = '\0';
	len--;
	if (n < 0)
	{
		*ptr = '-';
		while (ptr[len] != '-')
		{
			ptr[len] = ((n % 10) * -1) + 48;
			n = n / 10;
			len--;
		}
	}
	else
	{
		while (len >= 0)
		{
			ptr[len] = (n % 10) + 48;
			n = n / 10;
			len--;
		}
	}
	return (ptr);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	ptr[32];	
	int		len;
	int		aux;

	len = 0;
	aux = n;
	if (n <= 0)
		len++;
	while (aux != 0)
	{
		aux = aux / 10;
		len++;
	}
	ft_convert(n, len, ptr);
	ft_putstr_fd(ptr, fd);
}
