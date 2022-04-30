/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 02:20:08 by vcordeir          #+#    #+#             */
/*   Updated: 2022/04/29 23:13:20 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

static void	ft_updatepwd(t_shell *mshell)
{
	char	**args;
	char	*str;
	char	cwd[PATH_MAX];

	args = malloc(sizeof(char *) * 3);
	args[2] = NULL;
	str = ft_strdup("PWD=");
	getcwd(cwd, sizeof(cwd));
	if (cwd == NULL)
		perror("Unable to find current working directory");
	else
	{
		args[0] = ft_strdup("export");
		args[1] = ft_strjoinfree1(str, cwd);
		ft_export(args, mshell);
	}
	ft_freeptr(args);
}

static char	*ft_home(t_var *firstvar)
{
	t_var	*temp;
	char	*path;

	path = NULL;
	temp = firstvar;
	while (temp && ft_strcmp("HOME", temp->key))
		temp = temp->next;
	if (!temp || !temp->content)
	{
		printf("cd: HOME not set");
		g_exit = 1;
	}
	else
		path = temp->content;
	return (path);
}

void	ft_cd(t_shell *mshell, char *new_path)
{
	char	*path;

	g_exit = 0;
	if (!new_path)
		path = ft_home(mshell->firstvar);
	else
		path = new_path;
	if (path && path[0] == '-')
	{
		printf("minishell: cd: %c", path[0]);
		if (path[1])
			printf("%c", path[1]);
		printf(": invalid option\n");
		printf("cd: usage: cd [dir]\n");
		g_exit = 2;
	}
	else if (path && chdir(path))
	{
		printf("minishell: cd: %s: No such file or directory\n", path);
		g_exit = 2;
	}
	else
		ft_updatepwd(mshell);
}
