#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

 
int main(int argc, char *argv[]) 
{
    struct sockaddr_in stSockAddr;
    char *socket_ip = argv[1];
    long socket_port = atol(argv[2]);
    char *behavior = argv[3];
    // int amount = atoi(argv[4]);
    char *amount = argv[4];
    int times = atoi(argv[5]);
    int Res;
    int SocketFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    char tx_buf[256] = {0};
    char str_tmp[10] = {0};
    char i;
    int ConnectFD;
    // ./client <ip> <port> <deposit/withdraw> <amount> <times>

    // printf("1: %s\n", argv[1]);
    // printf("2: %s\n", argv[2]);
    // printf("3: %s\n", argv[3]);
    // printf("4: %s\n", argv[4]);
    // printf("5: %s\n", argv[5]);
    printf("1: %s\n", socket_ip);
    printf("2: %ld\n", socket_port);
    printf("3: %s\n", behavior);
    printf("4: %s\n", amount);
    printf("5: %d\n", times);
    // memset(tx_buf, 0, sizeof(tx_buf));
    memcpy(tx_buf, behavior, sizeof(behavior+1));
    str_tmp[0] = ' ';
    printf(">> %s\n", tx_buf);
    strcat(tx_buf, str_tmp);
    strcat(tx_buf, amount);
    printf(">> %s\n", tx_buf);

    if (-1 == SocketFD)
    {
        perror("cannot create socket");
        exit(EXIT_FAILURE);
    }
 
    memset(&stSockAddr, 0, sizeof(struct sockaddr_in));
 
    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(socket_port);
    Res = inet_pton(AF_INET, socket_ip, &stSockAddr.sin_addr);
 
    if (0 > Res)
    {
        perror("error: first parameter is not a valid address family");
        close(SocketFD);
        exit(EXIT_FAILURE);
    }
    else if (0 == Res)
    {
        perror("char string (second parameter does not contain valid ipaddress");
        close(SocketFD);
        exit(EXIT_FAILURE);
    }
 
    ConnectFD = connect(SocketFD, (const struct sockaddr *)&stSockAddr, sizeof(struct sockaddr_in));
    if (-1 == ConnectFD)
    {
        perror("connect failed");
        close(SocketFD);
        exit(EXIT_FAILURE);
    }
 
    /* perform read write operations ... */
    while(times > 0)
    {
        times--;
        send(SocketFD, tx_buf, sizeof(tx_buf), 0);    
        usleep(10);  
    }
    shutdown(SocketFD, SHUT_RDWR);
 
    close(SocketFD);

    return 0;
}