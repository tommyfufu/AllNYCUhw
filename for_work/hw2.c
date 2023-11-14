#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])

{
    // socket的建立
    int port = atoi(argv[1]);
    char inputBuffer[256] = {};

    int sockfd = 0, forClientSockfd = 0;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
    {
        printf("Fail to create a socket.");
    }

    // socket的連線
    struct sockaddr_in serverInfo, clientInfo;
    int addrlen = sizeof(clientInfo);
    bzero(&serverInfo, sizeof(serverInfo));

    serverInfo.sin_family = PF_INET;
    serverInfo.sin_addr.s_addr = INADDR_ANY;
    serverInfo.sin_port = htons(port);
    bind(sockfd, (struct sockaddr *)&serverInfo, sizeof(serverInfo));
    listen(sockfd, 5);

    int store = 0;           // 1 = Dessert Shop, 2 = Beverage Shop, 3 = Diner
    int store_1[2] = {0, 0}; // Dessert Shop
    int store_2[2] = {0, 0}; // Beverage Shop
    int store_3[2] = {0, 0}; // Diner

    forClientSockfd = accept(sockfd, (struct sockaddr *)&clientInfo, &addrlen);
    while (1)
    {

        // memset(inputBuffer, '\0', sizeof(inputBuffer));
        recv(forClientSockfd, inputBuffer, sizeof(inputBuffer), 0);
        int ret;
        printf("Get CMD: %s\n", inputBuffer);

        if (!strcmp(inputBuffer, "shop list"))
        { // 0 is the same
            char message[] = {"Dessert Shop: 3 min\n- cookie:60$|cake:80$\nBeverage Shop: 5 min\n- tea:40$|boba:70$\nDiner: 8 min\n- fried-rice:120$|Egg-drop-soup:50$\n"};
            send(forClientSockfd, message, sizeof(message), 0);
        }
        else if (ret = (strstr(inputBuffer, "order")) != NULL)
        {
            char *item, *num, *cur_num;
            printf("LINE: %d\n", __LINE__);
            item = strtok(inputBuffer, " "); // "order"
            printf("LINE: %d\n", __LINE__);
            item = strtok(NULL, " ");        // item
            printf("LINE: %d\n", __LINE__);
            num = strtok(NULL, " ");         // order num
            printf("LINE: %d\n", __LINE__);
            printf("item %s\n", item);
            printf("num %s\n", num);
            if (store == 0 || store == 1)
            {
                store = 1;
                if (!strcmp(item, "cookie"))
                {
                    
                    
                    store_1[0] += atoi(num);
                    snprintf(cur_num, sizeof(cur_num), "%d", store_1[0]);
                    char *buf;
                    sprintf(buf, "%s %s", item, num);
                    // strcat(buf, "cookie ");
                    // strcat(buf, cur_num);
                    printf("CMD to client1: %s\n", buf);
                    //send(forClientSockfd, test, strlen(test), 0);
                    send(forClientSockfd, buf, sizeof(buf), 0);
                }
                else if (!strcmp(item, "cake"))
                {
                }
            }
            else if (store == 0 || store == 2)
            {
            }
            else if (store == 0 || store == 3)
            {
            }
        }
        else
        {
            printf("Error CMD\n");
        }
    }
    return 0;
}
