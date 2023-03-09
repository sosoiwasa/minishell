/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwasa <siwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:45:36 by siwasa            #+#    #+#             */
/*   Updated: 2023/03/09 21:46:39 by siwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    ft_puterror(char *str)
{
    size_t    len;

    len = ft_strlen(str);
    write(STDERR_FILENO, str, len);
    return (-1);
}
