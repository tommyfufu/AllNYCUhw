#include "sockop.h"
const char *client_shop_list = "shop list";
const char *client_order = "order";
const char *client_confirm = "confirm";
const char *client_cancel = "cancel";
const char *server_shop_list = "Dessert Shop: 3 min\n- cookie:60$|cake:80$\nBeverage Shop: 5 min\n- tea:40$|boba:70$\nDiner: 8 min - fried-rice:120$|Egg-drop-soup:50$";
const char *plz_order = "Please order some meals";
const char *wait_del = "Please wait a few minutes...";
const char *arrive = "Delivery has arrived and you need to pay ";
const char *need_wait_long_time = "Your delivery will take a long time, do you want to wait?";
long int sem_key = 888;
typedef struct
{
    int delivery_man[2];
    int customer;
    int income;
} data_t;
int shmid, sem_fd;
data_t *shm;
pid_t ppid;
void handler(int signo, siginfo_t *info, void *context)
{

    pid_t nowpid = getpid();
    if ((signo == SIGINT) && (ppid == nowpid))
    {
        int retval;
        FILE *fd = fopen("result.txt", "w+");
        getandlock(sem_fd);
        fprintf(fd, "customer: %d\nincome: %d$", shm->customer, shm->income);
        releaseandunlock(sem_fd);
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
        close(connfd);
        close(sockfd);
        rmsem(sem_key);
        exit(0);
    }
}
void timer_handler(int signo)
{
    pid_t nowpid = getpid();

    getandlock(sem_fd);

    if (shm->delivery_man[0] > 0)
        (shm->delivery_man[0])--;
    if (shm->delivery_man[1] > 0)
        (shm->delivery_man[1])--;
    releaseandunlock(sem_fd);
}
int who_can_deliver_faster()
{
    getandlock(sem_fd);
    if (shm->delivery_man[0] <= shm->delivery_man[1])
    {
        releaseandunlock(sem_fd);
        return 0;
    }
    else
    {

        releaseandunlock(sem_fd);
        return 1;
    }
}
int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        printf("Usage: %s port\n", argv[0]);
        return -1;
    }
    // socket
    char buf[BUFSIZE];
    struct sockaddr_in addr_cln;
    socklen_t sLen = sizeof(addr_cln);
    memset(&addr_cln, 0, sLen);
    sockfd = passivesock(argv[1], "tcp", 10);

    // sem init
    sem_fd = makesem(sem_key, 1);
    // printf("semfd: %d, line: %d\n", sem_fd, __LINE__);
    //  share memory init
    key_t share_key;
    data_t our_data;
    if ((shmid = shmget(share_key, sizeof(our_data), IPC_CREAT | 0666)) < 0)
    {
        perror("shmget");
        exit(1);
    }
    if ((shm = shmat(shmid, NULL, 0)) == (char *)-1)
    {
        perror("shmat");
        exit(1);
    }
    getandlock(sem_fd);
    shm->customer = 0;
    shm->delivery_man[0] = 0;
    shm->delivery_man[1] = 0;
    shm->income = 0;
    releaseandunlock(sem_fd);
    // signal init
    struct sigaction my_action, time_action;
    struct itimerval timer;
    ppid = getpid();
    printf("ppid: %d\n", ppid);
    

    int flag = 0;
    while (1)
    {

        if ((connfd = accept(sockfd, (struct sockaddr *)&addr_cln, &sLen)) == -1)
        {
            // printf("Error accept\n");
            exit(EXIT_FAILURE);
        }
        pid_t pid;
        // hw2 start
        char s1[10], s2[10], ss[15], unuse[6], *ret, *order_list, p1[15], p2[15], *all_order_list, *tmpstr;
        order_list = (char *)malloc(sizeof(char) * 100);
        memset(order_list, 0, 100);
        all_order_list = (char *)malloc(sizeof(char) * 100);
        memset(all_order_list, 0, 100);
        int many = 0, tmp, ans = 0, store = 0, c1 = 0, c2 = 0;

        pid = fork();
        if (pid == -1)
        {
            // printf("fork error\n");
            exit(EXIT_FAILURE);
        }
        if (pid == 0)
        {
            while (1)
            {
                memset(buf, 0, BUFSIZE);
                tmp = recv(connfd, buf, BUFSIZE, 0);
                // printf("line:%d, buf: %s connfd:%d\n", __LINE__, buf, connfd);
                if (tmp == 0)
                {
                    // printf("receive complete\n");
                    break;
                }
                else if (tmp == -1)
                    continue;
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
                                                // printf("p2 %s", p2);
                                                // printf("s2 %s", s2);
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
                        else
                        {
                            int who = who_can_deliver_faster();
                            getandlock(sem_fd);
                            int wait_time = shm->delivery_man[who] + store;
                            releaseandunlock(sem_fd);
                            if (wait_time < 30)
                            {
                                // printf("wait time %d\n", wait_time);
                                send(connfd, wait_del, strlen(wait_del) + 1, 0);
                                getandlock(sem_fd);
                                shm->delivery_man[who] = wait_time;
                                shm->customer += 1;
                                shm->income += ans;
                                releaseandunlock(sem_fd);
                                // printf("wait time %d\n", wait_time);
                                sleep(wait_time);
                                sprintf(buf, "%s%d%s", arrive, ans, "$");
                                send(connfd, buf, strlen(buf) + 1, 0);
                                memset(order_list, 0, 100);
                                ans = 0;
                                store = 0;
                            }
                            else
                            {
                                // printf("wait time %d\n", wait_time);
                                send(connfd, need_wait_long_time, strlen(need_wait_long_time) + 1, 0);
                            }
                        }
                    }
                    else if ((ret = strstr(buf, client_cancel)) != NULL)
                    {
                        // printf("you cancel\n");
                        memset(buf, 0, BUFSIZE);
                        memset(order_list, 0, 100);
                        ans = 0;
                        store = 0;
                        break;
                    }
                    else if ((ret = strstr(buf, "Yes")) != NULL)
                    {

                        int who1 = who_can_deliver_faster();
                        getandlock(sem_fd);
                        int wait_time = shm->delivery_man[who1] + store;
                        releaseandunlock(sem_fd);
                        // send(connfd, wait_del, strlen(wait_del) + 1, 0);
                        getandlock(sem_fd);
                        shm->delivery_man[who1] = wait_time;
                        shm->customer += 1;
                        shm->income += ans;
                        releaseandunlock(sem_fd);
                        sleep(wait_time);
                        sprintf(buf, "%s%d%s", arrive, ans, "$");
                        send(connfd, buf, strlen(buf) + 1, 0);
                        memset(order_list, 0, 100);
                        ans = 0;
                        store = 0;
                    }
                    else if ((ret = strstr(buf, "No")) != NULL)
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
            return 0;
        }
        else
        {
            if (flag == 0)
            {
                flag = 1;
                pid = fork();

                if (pid == 0)
                {
                    // timer for sending kill to game every one sec
                    memset(&time_action, 0, sizeof(struct sigaction));
                    time_action.sa_handler = timer_handler;
                    sigaction(SIGALRM, &time_action, NULL);
                    timer.it_value.tv_sec = 1;
                    timer.it_value.tv_usec = 0;
                    timer.it_interval.tv_sec = 1;
                    timer.it_interval.tv_usec = 0;
                    setitimer(ITIMER_REAL, &timer, NULL);
                    
                    while (1)
                    {
                        sleep(100);
                    }
                    return 0;
                }
                else
                {
                    signal(SIGINT, handler);
                }
            }
        }
    }

    return 0;
}