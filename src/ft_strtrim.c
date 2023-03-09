/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwasa <siwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:53:06 by siwasa            #+#    #+#             */
/*   Updated: 2023/03/09 16:53:38 by siwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	flag(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = 0;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	end = (int)ft_strlen(s1);
	while (s1[start] != '\0' && flag(s1[start], set) == 1)
		start++;
	while (end > start && flag(s1[end - 1], set) == 1)
		end--;
	p = (char *)malloc(sizeof(char) * (end - start + 1));
	if (p == NULL)
		return (p);
	while (end > start)
		p[i++] = s1[start++];
	p[i] = '\0';
	return (p);
}
