/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:07:40 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/09 15:09:18 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_token
{
	char			*token;
	struct s_token	*next;
	int				test;
}					t_token;

typedef struct s_shell
{
	char			*input;
	struct s_token	*firsttoken;
	int				tkcounter;
	int				open;
	int				start;
}					t_shell;

void	ft_printtokens(t_shell *mshell);
void	ft_freetokens(t_shell *mshell);

#endif