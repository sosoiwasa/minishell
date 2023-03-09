/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuok <rmatsuok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:28:46 by rmatsuok          #+#    #+#             */
/*   Updated: 2023/03/08 15:28:58 by rmatsuok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_exec_path(char *line)
{
	size_t	i;
	char	*path;
	char	*ans;
	char	**tmp;

	i = 0;
	path = getenv("PATH");
	if (!path)
		exit(EXIT_FAILURE);
	tmp = ft_split(path, ':');
	while (tmp[i])
	{
		ans = ft_strdup(tmp[i]);
		ans = ft_strjoin(ans, "/");
		ans = ft_strjoin(ans, line);
		if (access(ans, X_OK) == 0)
		{
			ft_free(tmp);
			return (ans);
		}
		free(ans);
		i++;
	}
	return (NULL);
}


// int main(void)
// {
// 	if (access("/bin/ls", X_OK) == 0)
// 		printf("ok\n");
// 	else
// 		printf("no ok\n");
// }