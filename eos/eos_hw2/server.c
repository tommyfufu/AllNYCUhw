#include "sockop.h"

int s;
int sockfd, connfd;
const char *client_shop_list = "shop list";
const char *client_order = "order";
const char *client_confirm = "confirm";
const char *client_cancel = "cancel";
const char *server_shop_list = "Dessert Shop:3km\n- cookie:60$|cake:80$\nBeverage Shop:5km\n- tea:40$|boba:70$\nDiner:8km\n- fried-rice:120$|Egg-drop-soup:50$";
const char *plz_order = "Please order some meals";
const char *wait_del = "Please wait a few minutes...";
const char *arrive = "Delivery has arrived and you need to pay ";
// const char *cookie = "cookie";
// const char *cake = "cake";
// const char *tea = "tea";
// const char *boba = "boba";
// const char *fried_rice = "fried-rice";
// const char *Egg_drop_soup = "Egg-drop-soup";
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s port\n", argv[0]);
        return -1;
    }

    char buf[BUFSIZE];
    // long int key = 925;

    struct sockaddr_in addr_cln;
    socklen_t sLen = sizeof(addr_cln);
    memset(&addr_cln, 0, sLen);

    sockfd = passivesock(argv[1], "tcp", 10);
    // makesem(key, 1);

    while (1)
    {

        if ((connfd = accept(sockfd, (struct sockaddr *)&addr_cln, &sLen)) == -1)
        {
            // printf("Error accept\n");
            exit(EXIT_FAILURE);
        }
        // printf("connect success\n");
        // printf("connfd: %d\n", connfd);

        char s1[10], s2[10], ss[15], unuse[6], *ret, *order_list, p1[15], p2[15], *all_order_list, *tmpstr;
        order_list = (char *)malloc(sizeof(char) * 100);
        memset(order_list, 0, 100);

        all_order_list = (char *)malloc(sizeof(char) * 100);
        memset(all_order_list, 0, 100);

        int many = 0, tmp, ans = 0, store = 0, c1 = 0, c2 = 0;
        while (1)
        {
            memset(buf, 0, BUFSIZE);
            tmp = recv(connfd, buf, BUFSIZE, 0);
            if (tmp == 0)
            {
                printf("receive failed\n");
                break;
            }
            else
            {
                if ((ret = strstr(buf, client_shop_list)) != NULL) // shoplist
                {
                    send(connfd, server_shop_list, strlen(server_shop_list), 0);
                }
                else if ((ret = strstr(buf, client_order)) != NULL)
                {
                    // store 1
                    if (((ret = strstr(buf, "cookie")) != NULL) || ((ret = strstr(buf, "cake")) != NULL))
                    {

                        if ((store == 3) || (store == 0))
                        {

                            sscanf(buf, "%s %s %d", unuse, ss, &many);

                            if (store == 0)
                                sprintf(all_order_list, "%s %d", ss, many);
                            else
                            {
                                strcpy(p1, "cookie");
                                strcpy(p2, "cake");

                                if (strcmp(ss, "cookie") == 0) // order cookie
                                {

                                    if (((tmpstr = strstr(all_order_list, "cookie")) != NULL)) // old_list_has_old_same_item
                                    {

                                        if ((tmpstr = strstr(all_order_list, "cake")) != NULL) // old_list_has_another_item
                                        {
                                            sscanf(all_order_list, "%s %d%s%s %d", s1, &c1, tmpstr, s2, &c2);
                                            c1 += many;
                                            sprintf(all_order_list, "%s %d%s%s %d", p1, c1, "|", p2, c2);
                                        }
                                        else
                                        {
                                            sscanf(all_order_list, "%s %d", s1, &c1);
                                            c1 += many;
                                            sprintf(all_order_list, "%s %d", p1, c1);
                                        }
                                    }
                                    else // old_list_doesn't_have_same_old_item
                                    {
                                        if ((tmpstr = strstr(all_order_list, "cake")) != NULL) // old_list_has_another_item
                                        {
                                            sscanf(all_order_list, "%s %d", s2, &c2);
                                            c1 += many;
                                            sprintf(all_order_list, "%s %d%s%s %d", p1, many, "|", p2, c2);
                                        }
                                    }
                                }
                                else if (strcmp(ss, "cake") == 0) // order cake
                                {

                                    if (((tmpstr = strstr(all_order_list, "cake")) != NULL)) // old_list_has_old_same_item
                                    {
                                        if ((tmpstr = strstr(all_order_list, "cookie")) != NULL) // old_list_has_another_item
                                        {

                                            sscanf(all_order_list, "%s %d%s%s %d", s1, &c1, tmpstr, s2, &c2);
                                            c2 += many;
                                            sprintf(all_order_list, "%s %d%s%s %d", p1, c1, "|", p2, c2);
                                        }
                                        else // old_list_doesn't_have_another_item
                                        {

                                            sscanf(all_order_list, "%s %d", s2, &c2);

                                            c2 += many;
                                            sprintf(all_order_list, "%s %d", p2, c2);
                                        }
                                    }
                                    else // old_list_doesn't_have_same_old_item
                                    {

                                        if ((tmpstr = strstr(all_order_list, "cookie")) != NULL) // old_list_has_another_item
                                        {
                                            sscanf(all_order_list, "%s %d", s1, &c1);
                                            c2 += many;
                                            sprintf(all_order_list, "%s %d%s%s %d", p1, c1, "|", p2, c2);
                                        }
                                    }
                                }
                                else
                                    continue;
                            }
                        }
                        
                        send(connfd, all_order_list, strlen(all_order_list) + 1, 0);
                        

                        if (strcmp(ss, "cookie") == 0)
                            ans += (many * 60);
                        else if (strcmp(ss, "cake") == 0)
                            ans += (many * 80);

                        store = 3;
                    }
                    // store 2
                    if (((ret = strstr(buf, "tea")) != NULL) || ((ret = strstr(buf, "boba")) != NULL))
                    {

                        if ((store == 5) || (store == 0))
                        {

                            sscanf(buf, "%s %s %d", unuse, ss, &many);

                            if (store == 0)
                                sprintf(all_order_list, "%s %d", ss, many);
                            else
                            {
                                strcpy(p1, "tea");
                                strcpy(p2, "boba");

                                if (strcmp(ss, "tea") == 0) // order cookie
                                {

                                    if (((tmpstr = strstr(all_order_list, "tea")) != NULL)) // old_list_has_old_same_item
                                    {

                                        if ((tmpstr = strstr(all_order_list, "boba")) != NULL) // old_list_has_another_item
                                        {
                                            sscanf(all_order_list, "%s %d%s%s %d", s1, &c1, tmpstr, s2, &c2);
                                            c1 += many;
                                            sprintf(all_order_list, "%s %d%s%s %d", p1, c1, "|", p2, c2);
                                        }
                                        else
                                        {
                                            sscanf(all_order_list, "%s %d", s1, &c1);
                                            c1 += many;
                                            sprintf(all_order_list, "%s %d", p1, c1);
                                        }
                                    }
                                    else // old_list_doesn't_have_same_old_item
                                    {
                                        if ((tmpstr = strstr(all_order_list, "boba")) != NULL) // old_list_has_another_item
                                        {
                                            sscanf(all_order_list, "%s %d", s2, &c2);
                                            c1 += many;
                                            sprintf(all_order_list, "%s %d%s%s %d", p1, many, "|", p2, c2);
                                        }
                                    }
                                }
                                else if (strcmp(ss, "boba") == 0) // order boba
                                {

                                    if (((tmpstr = strstr(all_order_list, "boba")) != NULL)) // old_list_has_old_same_item
                                    {
                                        if ((tmpstr = strstr(all_order_list, "tea")) != NULL) // old_list_has_another_item
                                        {

                                            sscanf(all_order_list, "%s %d%s%s %d", s1, &c1, tmpstr, s2, &c2);
                                            c2 += many;
                                            sprintf(all_order_list, "%s %d%s%s %d", p1, c1, "|", p2, c2);
                                        }
                                        else // old_list_doesn't_have_another_item
                                        {

                                            sscanf(all_order_list, "%s %d", s2, &c2);
                                            printf("p2 %s", p2);
                                            printf("s2 %s", s2);
                                            c2 += many;
                                            sprintf(all_order_list, "%s %d", p2, c2);
                                        }
                                    }
                                    else // old_list_doesn't_have_same_old_item
                                    {

                                        if ((tmpstr = strstr(all_order_list, "tea")) != NULL) // old_list_has_another_item
                                        {
                                            sscanf(all_order_list, "%s %d", s1, &c1);
                                            c2 += many;
                                            sprintf(all_order_list, "%s %d%s%s %d", p1, c1, "|", p2, many);
                                        }
                                    }
                                }
                                else
                                    continue;
                            }
                        }
                        
                        send(connfd, all_order_list, strlen(all_order_list) + 1, 0);
                        
                        if (strcmp(ss, "tea") == 0)
                            ans += (many * 40);
                        else if (strcmp(ss, "boba") == 0)
                            ans += (many * 70);

                        store = 5;
                    }
                    // store 3
                    if (((ret = strstr(buf, "fried-rice")) != NULL) || ((ret = strstr(buf, "Egg-drop-soup")) != NULL))
                    {

                        if ((store == 8) || (store == 0))
                        {

                            sscanf(buf, "%s %s %d", unuse, ss, &many);

                            if (store == 0)
                                sprintf(all_order_list, "%s %d", ss, many);
                            else
                            {
                                strcpy(p1, "fried-rice");
                                strcpy(p2, "Egg-drop-soup");

                                if (strcmp(ss, "fried-rice") == 0) // order cookie
                                {

                                    if (((tmpstr = strstr(all_order_list, "fried-rice")) != NULL)) // old_list_has_old_same_item
                                    {

                                        if ((tmpstr = strstr(all_order_list, "Egg-drop-soup")) != NULL) // old_list_has_another_item
                                        {
                                            sscanf(all_order_list, "%s %d%s%s %d", s1, &c1, tmpstr, s2, &c2);
                                            c1 += many;
                                            sprintf(all_order_list, "%s %d%s%s %d", p1, c1, "|", p2, c2);
                                        }
                                        else
                                        {
                                            sscanf(all_order_list, "%s %d", s1, &c1);
                                            c1 += many;
                                            sprintf(all_order_list, "%s %d", p1, c1);
                                        }
                                    }
                                    else // old_list_doesn't_have_same_old_item
                                    {
                                        if ((tmpstr = strstr(all_order_list, "Egg-drop-soup")) != NULL) // old_list_has_another_item
                                        {
                                            sscanf(all_order_list, "%s %d", s2, &c2);
                                            c1 += many;
                                            sprintf(all_order_list, "%s %d%s%s %d", p1, many, "|", p2, c2);
                                        }
                                    }
                                }
                                else if (strcmp(ss, "Egg-drop-soup") == 0) // order boba
                                {

                                    if (((tmpstr = strstr(all_order_list, "Egg-drop-soup")) != NULL)) // old_list_has_old_same_item
                                    {
                                        if ((tmpstr = strstr(all_order_list, "fried-rice")) != NULL) // old_list_has_another_item
                                        {

                                            sscanf(all_order_list, "%s %d%s%s %d", s1, &c1, tmpstr, s2, &c2);
                                            c2 += many;
                                            sprintf(all_order_list, "%s %d%s%s %d", p1, c1, "|", p2, c2);
                                        }
                                        else // old_list_doesn't_have_another_item
                                        {

                                            sscanf(all_order_list, "%s %d", s2, &c2);

                                            c2 += many;
                                            sprintf(all_order_list, "%s %d", p2, c2);
                                        }
                                    }
                                    else // old_list_doesn't_have_same_old_item
                                    {

                                        if ((tmpstr = strstr(all_order_list, "fried-rice")) != NULL) // old_list_has_another_item
                                        {
                                            sscanf(all_order_list, "%s %d", s1, &c1);
                                            c2 += many;
                                            sprintf(all_order_list, "%s %d%s%s %d", p1, c1, "|", p2, many);
                                        }
                                    }
                                }
                                else
                                    continue;
                            }
                        }

                        
                        send(connfd, all_order_list, strlen(all_order_list) + 1, 0);
                        

                        if (strcmp(ss, "fried-rice") == 0)
                            ans += (many * 120);
                        else if (strcmp(ss, "Egg-drop-soup") == 0)
                            ans += (many * 50);

                        store = 8;
                    }
                }
                else if ((ret = strstr(buf, client_confirm)) != NULL)
                {
                    if (ans == 0)
                    {
                        send(connfd, plz_order, strlen(plz_order) + 1, 0);
                        continue;
                    }
                    sprintf(buf, "%s%d%s", arrive, ans, "$");
                    send(connfd, wait_del, strlen(wait_del)+1, 0);
                    sleep(store);
                    send(connfd, buf, strlen(buf) + 1, 0);
                    memset(order_list, 0, 100);
                    ans = 0;
                    store = 0;
                }
                else if ((ret = strstr(buf, client_cancel)) != NULL)
                {
                    memset(buf, 0, BUFSIZE);
                    memset(order_list, 0, 100);
                    ans = 0;
                    store = 0;
                    break;
                }
                else
                    continue;
            }
        }
    }
    close(connfd);
    close(sockfd);
    return 0;
}