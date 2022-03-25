/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:08:11 by vcordeir          #+#    #+#             */
/*   Updated: 2022/03/25 18:18:53 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_output_redirection(char *file_path, int mode, char *txt)
{
	int	fd;
	int	flag;

	if (mode == ONE_CHAR)
		flag = O_WRONLY;
	else if (mode == TWO_CHARS)
		flag = O_APPEND;
	fd = open(file_path, flag | O_CREAT | S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	write(fd, txt, ft_strlen(txt));
	close(fd);
}
