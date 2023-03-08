/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwasa <siwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:49:03 by siwasa            #+#    #+#             */
/*   Updated: 2023/03/08 16:30:54 by siwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/apue.h"
#include <fcntl.h>

int main(int ac, char **av)
{
	if (ac != 2)
		err_quit("usage: a.out");
	if (access(av[1], R_OK) < 0)
		err_ret("access error for %s", av[1]);
	else
		printf("read access OK\n");
	if (open(av[1], O_RDONLY) < 0)
		err_ret("open error for %s", av[1]);
	else
		printf("open for reading OK\n");
	exit(0);
}
