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

static size_t	countelements(char const *s, char c)
{
	int		flag;
	size_t	cnt;
	size_t	i;

	i = 0;
	flag = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			cnt++;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (cnt);
}

char	**ft_free(char **p)
{
	size_t	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

static char	**createline(char **p, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < countelements(s, c) && s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		tmp = j;
		while (s[j] != c && s[j] != '\0')
			j++;
		p[i] = ft_strndup(&s[tmp], j - tmp);
		if (p[i] == NULL)
			return (ft_free(p));
		i++;
	}
	p[i] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**p;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	p = malloc(sizeof(char *) * (countelements(s, c) + 1));
	if (p == NULL)
		return (NULL);
	p = createline(p, s, c);
	return (p);
}
