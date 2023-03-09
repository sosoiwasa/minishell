/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwasa <siwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:25:29 by siwasa            #+#    #+#             */
/*   Updated: 2023/03/09 18:21:26 by siwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main()
{
	char *argv[] = {"ls", "-l", "-a", NULL};
	char *envp[] = {NULL};
	execve("/bin/ls", argv, envp);
	return (0);
}