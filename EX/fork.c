/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwasa <siwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:37:16 by siwasa            #+#    #+#             */
/*   Updated: 2023/03/08 18:00:37 by siwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t	c_pid = fork();
	if (c_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (c_pid == 0)
	{
		printf("printed from child process - %d\n", getpid());
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("printed from parent process - %d\n", getpid());
		wait(NULL);
	}
	exit(EXIT_SUCCESS);
}
