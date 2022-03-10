/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:07:22 by chideyuk          #+#    #+#             */
/*   Updated: 2022/03/09 15:09:56 by chideyuk         ###   ########.fr       */
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

#endif