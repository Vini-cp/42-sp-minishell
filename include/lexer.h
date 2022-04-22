/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:07:22 by chideyuk          #+#    #+#             */
/*   Updated: 2022/04/22 23:57:38 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "shell.h"

# define SINGLE_QUOTES '\''
# define DOUBLE_QUOTES '\"'

void	ft_lexer(t_shell *mshell);
t_token	*ft_createtk(void);
void	ft_freetokens(t_shell *mshell);
void	ft_handlenormal(t_shell *mshell);
t_token	*ft_handlespecial(t_token *token, t_shell *mshell);
void	ft_handlequotes(t_shell *mshell);
t_token	*ft_closetk(t_token *token, t_shell *mshell);
t_token	*ft_handleredir(t_token *token, t_shell *mshell);
t_token	*ft_addtk(t_shell *mshell);

#endif