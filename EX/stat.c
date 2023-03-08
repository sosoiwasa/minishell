/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwasa <siwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:35:16 by siwasa            #+#    #+#             */
/*   Updated: 2023/03/08 21:47:51 by siwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

void printFileProperties(struct stat stats);

int main()
{
    char path[100];
    struct stat stats;

    printf("Enter file path: ");
    scanf("%s", path);

    if (stat(path, &stats) == 0) {
        printFileProperties(stats);
    }
    else {
        printf("Unable to get file properties.\n");
    }

    return 0;
}

void printFileProperties(struct stat stats)
{
    struct tm dt;

    // File permissions
    printf("File permissions: ");
    printf( (S_ISDIR(stats.st_mode)) ? "d" : "-");
    printf( (stats.st_mode & S_IRUSR) ? "r" : "-");
    printf( (stats.st_mode & S_IWUSR) ? "w" : "-");
    printf( (stats.st_mode & S_IXUSR) ? "x" : "-");
    printf( (stats.st_mode & S_IRGRP) ? "r" : "-");
    printf( (stats.st_mode & S_IWGRP) ? "w" : "-");
    printf( (stats.st_mode & S_IXGRP) ? "x" : "-");
    printf( (stats.st_mode & S_IROTH) ? "r" : "-");
    printf( (stats.st_mode & S_IWOTH) ? "w" : "-");
    printf( (stats.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    // File size
    printf("File size: %lld bytes\n", stats.st_size);

    // Creation time
    dt = *(gmtime(&stats.st_ctime));
    printf("Created on: %d-%02d-%02d %02d:%02d:%02d\n",
           dt.tm_year + 1900, dt.tm_mon + 1, dt.tm_mday,
           dt.tm_hour, dt.tm_min, dt.tm_sec);

    // Last modification time
    dt = *(gmtime(&stats.st_mtime));
    printf("Last modified on: %d-%02d-%02d %02d:%02d:%02d\n",
           dt.tm_year + 1900, dt.tm_mon + 1, dt.tm_mday,
           dt.tm_hour, dt.tm_min, dt.tm_sec);
}
