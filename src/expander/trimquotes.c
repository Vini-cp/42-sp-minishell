/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimquotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:10:52 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/25 18:07:09 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/expander.h"

static char	*ft_trim(char *token, int counter)
{
	char	*s1;
	char	*s2;

	s1 = NULL;
	s2 = NULL;
	if (counter)
		s1 = ft_substr(token, 0, counter);
	if (counter + 1)
		s2 = ft_substr(token, counter + 1, ft_strlen(token));
	free(token);
	if (s1 && s2)
		return (ft_strjoinfreeboth(s1, s2));
	else if (s1 && !s2)
		return (s1);
	else if (!s1 && s2)
		return (s2);
	else
		return (NULL);
}

char	*ft_trimquotes(char *token, t_token *tk)
{
	int		counter;
	char	quote;

	counter = 0;
	while (token && token[counter])
	{
		quote = token[counter];
		if ((token[counter] == '\'' || token[counter] == '\"')
			&& ft_strchr(&token[counter + 1], quote))
		{
			tk->quoted = 1;
			token = ft_trim(token, counter);
			while (token[counter] != quote)
				counter++;
			token = ft_trim(token, counter);
		}
		else
			counter++;
	}
	return (token);
}
