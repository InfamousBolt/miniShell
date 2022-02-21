/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_process_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergiopax <sergiopax@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 08:30:52 by sergiopax         #+#    #+#             */
/*   Updated: 2022/02/21 09:25:41 by sergiopax        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_environment	g_env;

void	exit_with_error(char *s)
{
	perror("\e[0;36mError executing command");
	write(STDERR_FILENO, s, ft_strlen(s));
	write(STDERR_FILENO, " : was not executed\n",
		ft_strlen(" : was not executed\n"));
	write(STDERR_FILENO, "exiting with status 2\e[0;37m\n",
		ft_strlen("exiting with status 2\e[0;37m\n"));
	g_env.exit_status = 2;
	exit(2);
}

void	set_exit_status(int pid)
{
	int	status;

	status = 0;
	if (pid > 0)
	{
		waitpid(pid, &status, WCONTINUED);
		if (WIFEXITED(status))
			g_env.exit_status = WEXITSTATUS(status);
	}
}
