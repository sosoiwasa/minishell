/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwasa <siwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:28:46 by rmatsuok          #+#    #+#             */
/*   Updated: 2023/03/09 21:39:21 by siwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_trim
{
	char	c;
	size_t	nexttrim;
}	t_trim;

void	get_trim_char(char *s1, t_trim *data)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == '\'')
		{
			data->c = s1[i];
			break ;
		}
		if (s1[i] == '\"')
		{
			data->c = s1[i];
			break ;
		}
		i++;
	}
}

static char	*ft_strcpy_shell(char *dest, char *src, ssize_t start, ssize_t next)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		if (i == (size_t)start || i == (size_t)next)
			i++;
		else
		{
			dest[j] = src[i];
			i++;
			j++;			
		}
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strtrim(char *s1, char c, t_trim *data)
{
	char		*p;
	ssize_t		start;
	ssize_t		next;

	if (!s1)
		return (NULL);
	start = get_trim_char_index(s1 + data->nexttrim, c);
	if (start < 0)
		return (s1);
	start += data->nexttrim;
	next = get_trim_char_index(s1 + start + 1, c);
	if (next < 0)
		return (s1);
	next = start + next + 1;
	p = malloc(sizeof(char) * (ft_strlen(s1) - 2 + 1));
	if (p == NULL)
		return (NULL);
	p = ft_strcpy_shell(p, s1, start, next);
	data->nexttrim = next + 1 - 2;
	return (p);
}

char	*tokenize(char *str)
{
	char	*ans;
	char	*tmp;
	t_trim	data;

	data.nexttrim = 0;
	data.c = 0;
	ans = ft_strdup(str);
	//malloc error
	while (1)
	{
		get_trim_char(ans + data.nexttrim, &data);
		tmp = ft_strtrim(ans, data.c, &data);
		if (ft_strcmp(ans, tmp) == 0)
			break ;
		free(ans);
		ans = tmp;
	}
	return (ans);
}