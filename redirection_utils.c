/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergiopax <sergiopax@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:12:11 by keshav            #+#    #+#             */
/*   Updated: 2022/02/21 09:28:28 by sergiopax        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	manage_fd(char *io, int fileno, bool delete)
{
	int	fd;

	if (delete)
		unlink(io);
	fd = open(io, O_RDWR | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
	{
		printf("Problem opening/creating file %s\n", io);
		return (fileno);
	}
	dup2(fd, fileno);
	return (fd);
}
