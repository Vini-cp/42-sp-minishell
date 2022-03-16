/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:33:37 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/14 16:01:59 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len1;
	size_t	len2;
	size_t	counter;
	size_t	counter2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = malloc(len1 + len2 + 1);
	if (s3 == NULL)
		return (NULL);
	counter = 0;
	counter2 = 0;
	while (s1[counter2] != '\0')
		s3[counter++] = (char)s1[counter2++];
	counter2 = 0;
	while (s2[counter2] != '\0')
		s3[counter++] = (char)s2[counter2++];
	s3[counter] = '\0';
	return (s3);
}

char	*ft_strjoinfree1(char *s1, char *s2)
{
	char	*s3;

	s3 = ft_strjoin(s1, s2);
	free(s1);
	return (s3);
}

char	*ft_strjoinfree2(char *s1, char *s2)
{
	char	*s3;

	s3 = ft_strjoin(s1, s2);
	free(s2);
	return (s3);
}

char	*ft_strjoinfreeboth(char *s1, char *s2)
{
	char	*s3;

	s3 = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (s3);
}
