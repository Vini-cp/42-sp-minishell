/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 03:10:15 by vcordeir          #+#    #+#             */
/*   Updated: 2022/03/25 18:10:26 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include "shell.h"

int		ft_iscommand(char **paths, char *str);
int		ft_iscmdpath(char *path);
char	*ft_concatenate(char *left, char *right, char middle);
int		ft_special_char(char *str);

#endif
