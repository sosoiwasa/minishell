/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwasa <siwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:18:33 by siwasa            #+#    #+#             */
/*   Updated: 2023/03/08 22:21:33 by siwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    struct stat a;
    if (argc != 2) {
        fprintf(stderr, "Please enter file name as 1st argument: %s \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (lstat(argv[1], &a) == -1) {
        perror("some error for lstat");
        exit(EXIT_FAILURE);
    }
    if ((a.st_mode & S_IFMT) == S_IFDIR)
        printf ("Directory\n");
    else if ((a.st_mode & S_IFMT) == S_IFIFO)
        printf ("FIFO/PIPE\n");
    else if ((a.st_mode & S_IFMT) == S_IFCHR)
        printf ("Character Device\n");
    else if ((a.st_mode & S_IFMT) == S_IFBLK)
        printf ("Block Device\n");
    else if ((a.st_mode & S_IFMT) == S_IFREG)
        printf ("Regular\n");
    else if ((a.st_mode & S_IFMT) == S_IFSOCK)
        printf ("Socket\n");
    else if ((a.st_mode & S_IFMT) == S_IFLNK)
        printf ("Symbolic Link\n");
    else
        printf("Unknown\n");
    printf("No. of link list:%ld\n", (long) a.st_nlink);
    printf("Ownership: UID=%ld GID=%ld\n", (long) a.st_uid, (long) a.st_gid);
    printf("inode no %ld\n", (long) a.st_ino);
    printf("Mode: %lo (octal)\n", (unsigned long) a.st_mode);
    printf("Last change time is: %s", ctime(&a.st_ctime));
    printf("Last access time is: %s", ctime(&a.st_atime));
    printf("Last changing the content of the file time is: %s", ctime(&a.st_mtime));
    printf("Preferred length of the blocks of giving I/O: %ld bytes\n", (long) a.st_blksize);
    printf("The length of the file is: %lld bytes\n", (long long) a.st_size);
    printf("Counting the no. of used blocks %lld\n", (long long) a.st_blocks);
    return 0;
}
