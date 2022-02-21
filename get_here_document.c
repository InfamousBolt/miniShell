/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_here_document.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergiopax <sergiopax@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:48:39 by keshav            #+#    #+#             */
/*   Updated: 2022/02/21 09:18:10 by sergiopax        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_input_file(char *token)
{
	char		*s;
	int			fd;

	unlink("./.temp");
	fd = open("./.temp", O_RDWR | O_CREAT | O_APPEND, 0666);
	while (true)
	{
		s = readline(">");
		if (s == NULL)
		{
			printf("warning: here-document ");
			printf("delimited by end-of-file (wanted '%s')\n", token);
		}
		if (s == NULL || (!ft_strncmp(s, token, ft_strlen(token))
				&& ft_strlen(token) == ft_strlen(s)))
		{
			free(s);
			break ;
		}
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
		free(s);
	}
	close(fd);
}

void	get_heredoc(char *s, char **io)
{
	char	temp[500];
	char	*ptr;

	ft_memset(temp, 0, 500);
	ptr = temp;
	*(s++) = ' ';
	*(s++) = ' ';
	while (*s == ' ')
		s++;
	if (*s == '<' || *s == '>' || *s == '\0' || *s == '\n')
	{
		return ;
	}
	while (*s && *s != ' ')
	{
		*(ptr++) = *s;
		*(s++) = ' ';
	}
	create_input_file(temp);
	free(*io);
	*io = ft_strdup("./.temp");
}
