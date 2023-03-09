/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isatty.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwasa <siwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:36:26 by siwasa            #+#    #+#             */
/*   Updated: 2023/03/09 15:50:06 by siwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("./test/test.txt", O_RDONLY);
	if (isatty(fd)) //isatty(fd)
		printf("Standard input is a terminal device.");
	else
		printf("Standard input is not a terminal device.");
	return (0);
}
