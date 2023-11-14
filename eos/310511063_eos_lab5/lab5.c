#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define BUFSIZE 1024

void handler(int signum)
{
    while (waitpid(-1, NULL, WNOHANG) > 0)
        ;
}

int main(int argc, char *argv[])
{
    //signal(SIGCHLD, handler);
    int sockfd, connfd;
    struct sockaddr_in addr_sin, addr_cln;
    socklen_t sLen = sizeof(addr_sin);
    memset(&addr_sin, 0, sLen);


    addr_sin.sin_family = AF_INET;
    addr_sin.sin_addr.s_addr = INADDR_ANY;
    addr_sin.sin_port = htons(3333);
    int n;
    char snd[BUFSIZE], rev[BUFSIZE];

    if (argc != 2)
    {
        printf("Usage: ./lab5 [port]\n");
        exit(EXIT_FAILURE);
    }

    sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    printf("sockfd : %d", sockfd);
    if (sockfd < 0)
    {
        printf("Can't create socket\n");
        exit(EXIT_FAILURE);
    }
    if (bind(sockfd, (struct sockaddr *)&addr_sin, sLen) < 0)
    {
        printf("Can't bind to port\n");
        exit(EXIT_FAILURE);
    }
    if (listen(sockfd, 100) < 0)
    {
        printf("Can't listen on port\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        if ((connfd = accept(sockfd, (struct sockaddr *)&addr_cln, &sLen)) == -1)
        {
            printf("Error accept\n");
            exit(EXIT_FAILURE);
        }
        printf("connect success\n");
        printf("connfd: %d\n", connfd);
        pid_t pid;
        pid = fork();
        if (pid == -1)
        {
            printf("fork error\n");
            exit(EXIT_FAILURE);
        }
        if (pid == 0)
        {
            close(sockfd);
            dup2(connfd, STDOUT_FILENO);
            execl("/usr/games/sl", "/usr/games/sl", "-l", NULL);
        }
        else
        {
            signal(SIGCHLD, handler);
        }
        close(connfd);
        
    }
    
    return 0;
}