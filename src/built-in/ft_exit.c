/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 02:52:09 by vcordeir          #+#    #+#             */
/*   Updated: 2022/03/30 16:43:51 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_exit(t_shell *mshell)
{
	free(mshell->input);
	ft_freetokens(mshell);
	ft_free_cmd_table(mshell);
	ft_free_env(mshell);
	if (mshell->path)
		ft_freeptr(mshell->path);
	rl_clear_history();
	free(mshell);
	exit(0);
}
