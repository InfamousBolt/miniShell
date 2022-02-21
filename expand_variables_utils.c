/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergiopax <sergiopax@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:04:21 by sergiopax         #+#    #+#             */
/*   Updated: 2022/02/21 09:19:02 by sergiopax        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_variables(bool *quotes, char **s, char *temp, int *i)
{
	*i = 0;
	*quotes = false;
	check_command_line(s);
	ft_memset(temp, 0, 20000);
}

void	expand_special_cases(int *i, char *s, char **ptr)
{
	if (*(s + *i + 1) == '?')
	{
		(*i) += 2;
		*ptr += sprintf_exit_status(*ptr);
	}
	else if (*(s + *i + 1) == '0')
	{
		(*i) += 2;
		ft_strlcat(*ptr, "-minishell", 10000);
		*ptr += 10;
	}
}
