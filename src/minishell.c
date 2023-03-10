/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwasa <siwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:28:46 by rmatsuok          #+#    #+#             */
/*   Updated: 2023/03/13 13:24:13 by siwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fatal_error(const char *msg) __attribute__((noreturn));

void	fatal_error(const char *msg)
{
	ft_puterror((char *)msg);
	exit(1);
}

int	interpret(char *line, t_data *data)
{
	extern char	**environ;
	pid_t		pid;
	char		*path;
	char		*tline;
	int			wstatus;

	// if (!*line)
	// 	return (0);
	tline = tokenize(line);
	// tline = ft_replacement(tline, " \n\t", ' ');
	data->args = ft_split(tline, ' ');
	free(tline);
	pid = fork();
	if (pid < 0)
		fatal_error("fork");
	else if (pid == 0)
	{
		// child process
		path = get_exec_path(data->args[0]);
		if (!path)
		{
			ft_puterror(data->args[0]);
			ft_puterror(": command not found\n");
			exit (0);
		}
		execve(path, data->args, environ);
		fatal_error("execve");
	}
	else
	{
		// parent process
		wait(&wstatus);
		return (WEXITSTATUS(wstatus));
	}
}

int	main(void)
{
	char	*line;
	t_data	data;

	rl_outstream = stderr;
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			break ;
		if (*line)
			add_history(line);
		interpret(line, &data);
		ft_free(data.args);
		free(line);
	}
	printf("\nexit\n");
	exit(0);
}
