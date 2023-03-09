/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuok <rmatsuok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:27:38 by rmatsuok          #+#    #+#             */
/*   Updated: 2023/01/10 16:27:40 by rmatsuok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strcat(char *dest, char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	s1len;
	size_t	s2len;

	s2len = ft_strlen(s2);
	if (!s1)
	{
		p = ft_strdup(s2);
		if (!p)
			return (NULL);
		return (p);
	}
	s1len = ft_strlen(s1);
	p = malloc(sizeof(char) * (s1len + s2len + 1));
	if (p == NULL)
		return (NULL);
	p = ft_strcpy(p, s1);
	p = ft_strcat(p, s2);
	free(s1);
	return (p);
}
