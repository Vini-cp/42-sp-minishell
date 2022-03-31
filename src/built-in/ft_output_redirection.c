/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 00:08:11 by vcordeir          #+#    #+#             */
/*   Updated: 2022/03/28 14:27:24 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shell.h"

void	ft_output_redirection(char *file_path, int mode, char *txt)
{
	int	fd;
	int	flag_mode;
	int flag_permission;
	
	flag_permission = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if (mode == ONE_CHAR)
		flag_mode = O_TRUNC;
	else if (mode == TWO_CHARS)
		flag_mode = O_APPEND;

	if (access(file_path, F_OK) == 0)
		fd = open(file_path, flag_mode | O_WRONLY | flag_permission);
	else
		fd = open(file_path, flag_mode | O_CREAT | O_WRONLY | flag_permission);
	write(fd, txt, strlen(txt));
	write(fd, "\n", 1);
	close(fd);
}
