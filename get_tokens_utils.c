/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergiopax <sergiopax@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:14:22 by sergiopax         #+#    #+#             */
/*   Updated: 2022/02/21 09:23:14 by sergiopax        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_pipes(char *s)
{
	int	i;
	int	j;
	int	pipes;

	pipes = 0;
	i = 0;
	while (*(s + i))
	{
		if ((*(s + i) == 34 || *(s + i) == 39)
			&& closed_quotes(s + i, *(s + i)))
		{
			j = i;
			i++;
			while (*(s + i) != *(s + j))
				i++;
		}
		if (*(s + i) == '|')
		{
			while (*(s + i + 1) == '|')
				i++;
			pipes++;
		}
		i++;
	}
	return (pipes);
}

void	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;

	i = 0;
	while (*(src + i) && i + 1 < dstsize)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
}

bool	in_charset(int c)
{
	int	i;

	i = 0;
	while (*(C_CHAR_SET + i))
	{
		if (c == *(C_CHAR_SET + i))
			return (true);
		i++;
	}
	if (ft_isalnum(c))
		return (true);
	return (false);
}

bool	valid_char(char c)
{
	if (c && c != ' ' && c != '|' && c != '>' && c != '<')
		return (true);
	return (false);
}

void	create_array(char **array, char *command, int size)
{
	*array = (char *)ft_calloc(size, sizeof(char));
	ft_strlcpy(*array, command, size);
}
