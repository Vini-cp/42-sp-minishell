/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concatenate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 02:27:07 by coder             #+#    #+#             */
/*   Updated: 2022/03/10 21:24:00 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_concatenate(char const *left, char const *right)
{
	int		str_len;
	char	*str_conc;

	if (!left)
		str_len = ft_strlen(right) + 1;
	else
		str_len = ft_strlen(left) + ft_strlen(right) + 2;
	str_conc = malloc(str_len * sizeof(char));
	if (left)
		ft_strlcpy(str_conc, left, ft_strlen(left) + 1);
	str_conc[ft_strlen(left)] = ' ';
	ft_strlcpy(str_conc + (ft_strlen(left) + 1), right, ft_strlen(right) + 1);
	return (str_conc);
}
