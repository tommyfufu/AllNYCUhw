#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
        perror("usage: a.out <pathname>");
    if (access(argv[1], R_OK) < 0)
        perror("access error");
    else 
        printf("read access OK\n");
    if (open(argv[1], O_RDONLY) < 0)
        perror("open error");
    else
        printf("open for reading OK\n");
    exit(0);
}