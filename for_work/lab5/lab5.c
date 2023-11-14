/* Server code in C */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/syscall.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#define NUM_THREADS 3

void *Multi_Connect_Function(void *arg)
{

    int *ConnectFD = (int *)arg;
    char *output = (char *)malloc(20 * sizeof(char));
    printf("Train ID: %ld\n", syscall(SYS_gettid));
    //write(*ConnectFD, output, strlen(output));

    dup2(*ConnectFD, STDOUT_FILENO);

    system("sl -l");
    close(*ConnectFD);
    shutdown(*ConnectFD, SHUT_RDWR);
}
int main(int argc, char *argv[])
{
    int socket_port = atoi(argv[1]);
    pthread_t *threads = malloc(NUM_THREADS * sizeof(pthread_t));

    struct sockaddr_in stSockAddr;
    int ConnectFD, SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    printf("Main_pid: %d, port: %d\n", getpid(), socket_port);

    if (-1 == SocketFD)
    {
        perror("can not create socket");
        exit(EXIT_FAILURE);
    }

    memset(&stSockAddr, 0, sizeof(struct sockaddr_in));

    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(socket_port);
    stSockAddr.sin_addr.s_addr = INADDR_ANY;

    if (-1 == bind(SocketFD, (const struct sockaddr *)&stSockAddr, sizeof(struct sockaddr_in)))
    {
        perror("error bind failed");
        close(SocketFD);
        exit(EXIT_FAILURE);
    }

    int i;
    for (i = 0; i < NUM_THREADS; i++)
    {
        if (-1 == listen(SocketFD, 10))
        {
            perror("error listen failed");
            close(SocketFD);
            exit(EXIT_FAILURE);
        }

        ConnectFD = accept(SocketFD, NULL, NULL);

        if (0 > ConnectFD)
        {
            perror("error accept failed");
            close(SocketFD);
            exit(EXIT_FAILURE);
        }
        else
        {
            pthread_create(&threads[i], NULL, Multi_Connect_Function, &ConnectFD);
        }
    }
    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
    free(threads);
    shutdown(SocketFD, SHUT_RDWR);
    close(SocketFD);
    return 0;
}
