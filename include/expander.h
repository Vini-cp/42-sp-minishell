/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:53:22 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/15 17:36:12 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "shell.h"

void	ft_expander(t_shell *mshell, char **env);
char	*ft_getvarkey(char	*str, int counter);
char	*ft_getvar(char *key, char **env, t_var *variable);
char	*ft_switch(char *token, char *key, char *content, int counter);
char	*ft_remove(char *token, char *key, int counter);
char	*ft_trimquotes(char *token);
int		ft_treatdquote(char *token, int counter, int dquotes);

#endif