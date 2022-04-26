/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 02:52:09 by vcordeir          #+#    #+#             */
/*   Updated: 2022/04/26 20:08:54 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_exit(t_shell *mshell, char **env, int status)
{
	free(mshell->input);
	ft_freetokens(mshell);
	ft_free_cmd_table(mshell);
	ft_free_mshell(mshell);
	ft_free_envvars(env);
	exit(status);
}
