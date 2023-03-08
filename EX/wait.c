/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwasa <siwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:10:28 by siwasa            #+#    #+#             */
/*   Updated: 2023/03/08 18:13:42 by siwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t	cpid;
	
	if (fork() == 0)
		exit(0); //terminate child
	else
		cpid = wait(NULL); //reaping parent
	printf("Parent pid = %d\n", getpid());
	printf("Child pid = %d\n", cpid);
	
	return (0);
}
