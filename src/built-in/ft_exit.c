/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 02:52:09 by vcordeir          #+#    #+#             */
/*   Updated: 2022/04/21 04:28:02 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_exit(t_shell *mshell, char **env)
{
	free(mshell->input);
	ft_freetokens(mshell);
	ft_free_cmd_table(mshell);
	ft_free_mshell(mshell);
	ft_free_envvars(env);
	exit(0);
}
