#include "sockop.h"

int s;
int sockfd, connfd;

void handler(int signum)
{
    close(connfd);
    printf("close connfd\n");
    rmsem(s);
    printf("release sem\n");
    exit(0);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s port\n", argv[0]);
        return -1;
    }

    // signal(SIGCHLD, handler);
    int *balance = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *balance = 0;
    char buf[BUFSIZE];
    long int key = 927;

    struct sockaddr_in addr_cln;
    socklen_t sLen = sizeof(addr_cln);
    memset(&addr_cln, 0, sLen);
    // int fd;
    // fd = open("/tmp/aaa", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    // lseek(fd,0,0);
    // sprintf(balbuf, "%d", balance);
    // printf("%s\n", balbuf);
    // write(fd, balbuf, sizeof(int));
    // read(fd, balbuf,sizeof(int));
    // printf("%s\n", balbuf);
    // close(fd);
    signal(SIGINT, handler);
    sockfd = passivesock(argv[1], "tcp", 10);
    makesem(key, 1);
    int loop=0;
    while (1)
    {
        loop++;
        if ((connfd = accept(sockfd, (struct sockaddr *)&addr_cln, &sLen)) == -1)
        {
            printf("Error accept\n");
            exit(EXIT_FAILURE);
        }
        printf("connect success\n");
        printf("connfd: %d\n", connfd);

        pid_t pid, wpid;
        int status = 0;
        pid = fork();
        if (pid == -1)
        {
            printf("fork error\n");
            exit(EXIT_FAILURE);
        }
        if (pid == 0)
        {

            int action, amount;
            int tmp;
            while (1)
            {
                tmp = recv(connfd, buf, sizeof(buf), 0);
                if (tmp == 0)
                    break;
                else
                {
                    sscanf(buf, "%d %d", &action, &amount);

                    getandlock(s);
                    *balance = *balance + (action * amount);
                    printf("main s: %d\n", s);
                    releaseandunlock(s);

                    if (action == 1)
                        printf("After deposit:%d\n", *balance);
                    else
                        printf("After withdraw:%d\n", *balance);
                    // sprintf(balbuf, "%d", balance);
                    // write(fd, balbuf, sizeof(int));
                    
                    // close(fd);
                }
            }
        }
    }
    printf("loop : %d\n", loop);
    return 0;
}