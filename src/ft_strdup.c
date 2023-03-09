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

char	*ft_strdup(const char *src)
{
	size_t		i;
	size_t		j;
	char		*str;

	i = ft_strlen(src);
	j = 0;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	while (src[j] != '\0')
	{
		str[j] = src[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
