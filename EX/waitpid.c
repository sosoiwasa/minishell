/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwasa <siwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:19:56 by siwasa            #+#    #+#             */
/*   Updated: 2023/03/08 20:17:53 by siwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t	child_pid;
	pid_t	wpid;
	int		status;
	
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		printf("child process with PID %d\n", getpid());
		sleep(5);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("parent process with PID %d\
				waiting for child with PID %d\n", getpid(), child_pid);
		do
		{
			wpid = waitpid(child_pid, &status, WUNTRACED);
			if (wpid == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
			if (WIFEXITED(status))
				printf("child process with PID %d\
				 		exited with status %d\n", wpid, WEXITSTATUS(status));
			else if (WIFSIGNALED(status))
				printf("child process with PID %d\
						terminated by signal %d\n", wpid, WTERMSIG(status));
			
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}
