/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:53:22 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/11 19:59:51 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "shell.h"

void	ft_expander(t_shell *mshell, char **env);
char	*ft_getvarkey(char	*str, int counter);
char	*ft_getvar(char *key, char **env, t_var *variable);
char	*ft_switch(char *s3, char *s1, char *s2);

#endif