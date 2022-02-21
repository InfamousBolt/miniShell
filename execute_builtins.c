/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergiopax <sergiopax@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:09:17 by keshav            #+#    #+#             */
/*   Updated: 2022/02/21 09:05:30 by sergiopax        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_environment	g_env;

int	is_builtin(char *command)
{
	if (!command)
		return (0);
	if (ft_strlen(command) == 2 && !ft_strncmp(command, "cd", 2))
		return (1);
	if (ft_strlen(command) == 4 && !ft_strncmp(command, "exit", 4))
		return (2);
	if (ft_strlen(command) == 4 && !ft_strncmp(command, "echo", 4))
		return (3);
	if (ft_strlen(command) == 3 && !ft_strncmp(command, "pwd", 3))
		return (4);
	if (ft_strlen(command) == 6 && !ft_strncmp(command, "setenv", 6))
		return (5);
	if (ft_strlen(command) == 6 && !ft_strncmp(command, "export", 6))
		return (5);
	if (ft_strlen(command) == 5 && !ft_strncmp(command, "unset", 5))
		return (6);
	if (ft_strlen(command) == 3 && !ft_strncmp(command, "env", 3))
		return (7);
	return (0);
}

int	execute_builtin(int b, char **command, t_instructions instructions)
{
	if (b == 1)
		cd(command);
	if (b == 2)
		clean_up_and_exit(instructions, true, true);
	if (b == 3)
		echo(command, instructions);
	if (b == 4)
		pwd(instructions);
	if (b == 5)
		export(command);
	if (b == 6)
		unset(command);
	if (b == 7)
		env(instructions);
	return (0);
}

int	exit_with_options(char *s)
{
	long int	option_to_num;
	char		*option;

	if (!ft_strncmp(s, "exit ", 5))
	{
		option = ft_strsub(s, 5, ft_strlen(s));
		if (ft_count_char(option, ' ') >= 1)
		{
			printf("exit: too many arguments\n");
			free(option);
			g_env.exit_status = 1;
		}
		else if (ft_is_numeric(option))
		{
			option_to_num = ft_str_to_num(option);
			exit(option_to_num);
		}
		else
		{
			g_env.exit_status = 2;
			exit(2);
		}
		return (1);
	}
	return (0);
}
