/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwasa <siwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:59:29 by siwasa            #+#    #+#             */
/*   Updated: 2023/03/08 17:16:49 by siwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main()
{
	//print the current working dir
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("current working directory: %s\n", cwd);
	
	//change the current working directory to /tmp
	if (chdir("./test") != 0)
	{
		perror("chdir() to ./test failed");
		return (1);
	}

	//print the new current working dir
	getcwd(cwd, sizeof(cwd));
	printf("new current working directory: %s\n", cwd);

	return (0);
}
