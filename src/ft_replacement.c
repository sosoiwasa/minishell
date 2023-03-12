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

bool	isset(char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (true);
		i++;
	}
	return (false);
}

char	*ft_replacement(char *str, char *set, char c)
{
	char	*ans;
	size_t	i;

	i = 0;
	ans = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!ans)
		return (NULL);
	while (str[i])
	{
		if (isset(set, str[i]))
			ans[i] = c;
		else
			ans[i] = str[i];
		i++;
	}
	free(str);
	return (ans);
}
