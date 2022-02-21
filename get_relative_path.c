/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_relative_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergiopax <sergiopax@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:13:12 by sergiopax         #+#    #+#             */
/*   Updated: 2022/02/21 09:22:28 by sergiopax        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	valid_path(char *s)
{
	if (*(s) == '/')
		return (true);
	if (*(s) == '~' && (*(s + 1) == ' ' || *(s + 1) == '/'))
		return (true);
	if (*(s) == '.' && (*(s + 1) == '/' || *(s + 1) == ' '))
		return (true);
	if (*(s) == '.' && *(s + 1) == '.' && (*(s + 2) == '/' || *(s + 2) == ' '))
		return (true);
	return (false);
}

char	*get_path(char *s)
{
	char	path[1000];
	char	*ptr;

	ft_memset(path, 0, 1000);
	ptr = path;
	while (*s)
	{
		if (*s == ' ' && valid_path(s + 1))
		{
			s++;
			while (*s && *s != ' ')
				*(ptr++) = *(s++);
			return (ft_strdup(path));
		}
		s++;
	}
	return (NULL);
}
