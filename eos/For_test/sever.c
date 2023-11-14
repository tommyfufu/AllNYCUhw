/* Server code in C */
 
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
 
#define cINVALID_CMD        0
#define cDEPOSIT            1
#define cWITHDRAW           2
#define cTHREAD_CNT         50

long long int total_amount = 0;

char parser_cmd(char *cmd_str, char *amount);
int parser_amount(char *cmd_str);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *cal_amount(void *fd) 
{
    char rx_buf[256] = {0};
    char cal_behavior;
    char amount[2];
    int *ConnectFD = (int *)fd;
    printf("Thread %d\n", *ConnectFD);
    while(1)
    {
        recv(*ConnectFD, rx_buf, sizeof(rx_buf), 0);
        parser_cmd(rx_buf, amount);
        // pthread_mutex_lock(&mutex);
        // total_amount += number_in_circle_thread;
        // pthread_mutex_unlock(&mutex);
    }
    // shutdown(*ConnectFD, SHUT_RDWR);
    close(*ConnectFD);
    pthread_exit((void *) NULL); 
}

int main(int argc, char *argv[])
{
    struct sockaddr_in stSockAddr;
    int SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    int Socket_port = atoi(argv[1]);


    pthread_t *threads = malloc(cTHREAD_CNT * sizeof(pthread_t));
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    int i;

    if(-1 == SocketFD)
    {
        perror("can not create socket");
        exit(EXIT_FAILURE);
    }
 
    memset(&stSockAddr, 0, sizeof(struct sockaddr_in));
 
    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(Socket_port);
    stSockAddr.sin_addr.s_addr = INADDR_ANY;
 
    if(-1 == bind(SocketFD,(const struct sockaddr *)&stSockAddr, sizeof(struct sockaddr_in)))
    {
        perror("error bind failed");
        close(SocketFD);
        exit(EXIT_FAILURE);
    }
    
    
    i=0;
    for(;;)
    {
        if(-1 == listen(SocketFD, 10))
        {
            perror("error listen failed");
            close(SocketFD);
            exit(EXIT_FAILURE);
        }
        int ConnectFD = accept(SocketFD, NULL, NULL);
        printf("> ConnectFD: %d\n", ConnectFD);
        if(0 > ConnectFD)
        {
            perror("error accept failed");
            close(SocketFD);
            exit(EXIT_FAILURE);
        }
 
        /* perform read write operations ... */
        printf("accpet\n");
        pthread_create(&threads[i++], NULL, cal_amount, &ConnectFD);
    }
    for (i=0; i<cTHREAD_CNT; i++) 
        pthread_join(threads[i], NULL);
    // pthread_mutex_destroy(&mutex);
    close(SocketFD);
    return 0;
}

char parser_cmd(char *cmd_str, char *amount)
{   
    char cmd_str_tmp[64];
    if(((cmd_str[0] == 'D') || (cmd_str[0] == 'd')) &&
       ((cmd_str[1] == 'E') || (cmd_str[1] == 'e')) &&
       ((cmd_str[2] == 'P') || (cmd_str[2] == 'p')) &&
       ((cmd_str[3] == 'O') || (cmd_str[3] == 'o')) &&
       ((cmd_str[4] == 'S') || (cmd_str[4] == 's')) &&
       ((cmd_str[5] == 'I') || (cmd_str[5] == 'i')) &&
       ((cmd_str[6] == 'T') || (cmd_str[6] == 't')))
    {
        memcpy(cmd_str_tmp, cmd_str+8, 10);   
        amount[0] = parser_amount(cmd_str_tmp);
        printf("deposit %d\n", amount[0]);
        return cDEPOSIT;
    }
    else if(((cmd_str[0] == 'W') || (cmd_str[0] == 'w')) &&
            ((cmd_str[1] == 'I') || (cmd_str[1] == 'i')) &&
            ((cmd_str[2] == 'T') || (cmd_str[2] == 't')) &&
            ((cmd_str[3] == 'H') || (cmd_str[3] == 'h')) &&
            ((cmd_str[4] == 'D') || (cmd_str[4] == 'd')) &&
            ((cmd_str[5] == 'R') || (cmd_str[5] == 'r')) &&
            ((cmd_str[6] == 'A') || (cmd_str[6] == 'a')) &&
            ((cmd_str[7] == 'W') || (cmd_str[7] == 'w')) )  
    {
        memcpy(cmd_str_tmp, cmd_str+9, 10);   
        amount[0] = parser_amount(cmd_str_tmp);
        printf("withdraw %d\n", amount[0]);
        memcpy(cmd_str_tmp, cmd_str+9, 10);
        return cWITHDRAW;
    }
    else
    {
        // printf("cINVALID_CMD\n");
        return cINVALID_CMD;
    }
}

int parser_amount(char *cmd_str)
{
    if((cmd_str[0] >= '0' && cmd_str[0] <= '9') && 
       (cmd_str[1] >= '0' && cmd_str[1] <= '9') &&
       (cmd_str[2] >= '0' && cmd_str[2] <= '9'))
    {
        return ((cmd_str[0]-0x30)*100) + ((cmd_str[1]-0x30)*10) + (cmd_str[2]-0x30);
    }
    else
    {
        if((cmd_str[0] >= '0' && cmd_str[0] <= '9') && 
           (cmd_str[1] >= '0' && cmd_str[1] <= '9'))
        {
            return ((cmd_str[0]-0x30)*10) + (cmd_str[1]-0x30);
        }
        else
        {
            if(cmd_str[0] >= '0' && cmd_str[0] <= '9')
            {
                return cmd_str[0]-0x30;
            }
            else
            {
                return -1;
            }
        }
    }
}


