/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwasa <siwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:59:42 by siwasa            #+#    #+#             */
/*   Updated: 2023/03/08 21:07:21 by siwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main()
{
	int newfd;
	
	newfd = dup(STDOUT_FILENO);
	if (newfd == -1)
	{
		perror("dup");
		return (1);
	}
	printf("This message is printed once.\n");
	dup2(newfd, STDOUT_FILENO);
	printf("This messsage is printed twice.\n");
	close(newfd);
	return (0);
}
