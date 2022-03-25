/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_document.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 03:14:41 by vcordeir          #+#    #+#             */
/*   Updated: 2022/03/25 14:31:52 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_here_document(char *input)
{
	char	*prompt;
	char	*to_compare;

	prompt = ft_strdup("> ");
	to_compare = readline(prompt);
	while (ft_strcmp(input, to_compare))
		to_compare = readline(prompt);
	free(to_compare);
	free(prompt);
}
