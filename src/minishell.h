/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwasa <siwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:28:46 by rmatsuok          #+#    #+#             */
/*   Updated: 2023/03/09 21:46:27 by siwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_data
{
	char	**args;
}	t_data;

char	*ft_strjoin(char *s1, char *s2);
char	*get_exec_path(char *line);
char	*ft_strndup(const char *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);
char	**ft_free(char **p);
int    ft_puterror(char *str);

#endif
