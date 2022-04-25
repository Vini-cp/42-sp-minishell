/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 02:09:00 by vcordeir          #+#    #+#             */
/*   Updated: 2022/04/25 22:18:44 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_pwd(char *arg)
{
	char	cwd[PATH_MAX];

	g_exit = 0;
	if (arg && arg[0] == '-' && arg[1])
	{
		printf("minishell: pwd: %c", arg[0]);
		if (arg[1])
			printf("%c", arg[1]);
		printf(": invalid option\n");
		printf("pwd: usage: pwd\n");
		g_exit = 2;
		return ;
	}
	getcwd(cwd, sizeof(cwd));
	if (cwd != NULL)
		printf("%s\n", cwd);
	else
		perror("Unable to find current working directory");
}
