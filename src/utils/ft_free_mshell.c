/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 04:27:12 by vcordeir          #+#    #+#             */
/*   Updated: 2022/04/21 04:28:14 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_free_mshell(t_shell *mshell)
{
	ft_free_env(mshell);
	if (mshell->path)
		ft_freeptr(mshell->path);
	rl_clear_history();
	free(mshell);
}
