/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwasa <siwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:50:16 by siwasa            #+#    #+#             */
/*   Updated: 2023/03/08 16:54:13 by siwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
	(void)ac;
    if (access(av[1], F_OK) == 0)
	{
        printf("File exists\n");
    }
	else
	{
        printf("File does not exist\n");
    }
    return 0;
}
