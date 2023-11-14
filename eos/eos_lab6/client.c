#include "sockop.h"
#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    int connfd;
    int n, val, action, amount, times;
    char buf[BUFSIZE];

    if (argc != 6)
    {
        printf("Usage: ./client <ip> <port> <deposit/withdraw> <amount> <times>\n");
        exit(EXIT_FAILURE);
    }

    if ((strcmp(argv[3], "deposit")) == 0)
        action = 1;
    else if ((strcmp(argv[3], "withdraw")) == 0)
        action = -1;
    else
    {
        printf("Usage: ./client <ip> <port> <deposit/withdraw> <amount> <times>\n");
        exit(EXIT_FAILURE);
    }
    sscanf(argv[4], "%d", &amount);
    sscanf(argv[5], "%d", &times);
    sprintf(buf, "%d %d", action, amount);
    connfd = connectsock(argv[1], argv[2], "tcp");
    for(;times>0;times--)
        send(connfd, buf, sizeof(buf), 0);
    close(connfd);

    return 0;
}