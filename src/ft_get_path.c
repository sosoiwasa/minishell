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
		///no malloc error
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
	ft_free(tmp);
	return (NULL);
}


// int main(void)
// {
// 	if (access("/bin/ls", X_OK) == 0)
// 		printf("ok\n");
// 	else
// 		printf("no ok\n");
// }