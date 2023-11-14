#include <stdio.h>
#include <unistd.h>

#include <stdlib.h>

#define bufsize 1024

int main()
{
    int n;
    char buf[bufsize];

    while ((n = read(STDIN_FILENO, buf, bufsize)) > 0)
    {
        printf("n is %d\n", n);

        if (write(STDOUT_FILENO, buf, n) != n)
            perror("write eorro\n");
    }

    if (n < 0)
        perror("read error");

    exit(0);
}