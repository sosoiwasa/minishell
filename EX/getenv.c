/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwasa <siwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:32:22 by siwasa            #+#    #+#             */
/*   Updated: 2023/03/08 22:35:41 by siwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *env_value;

    // 環境変数 "PATH" の値を取得する
    env_value = getenv("PATH");

    if (env_value != NULL) {
        printf("PATH = %s\n", env_value);
    } else {
        printf("Env value does not exist.\n");
    }

    return 0;
}
