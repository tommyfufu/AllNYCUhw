#include <cstdio>      // fprintf(), perror()
#include <cstdlib>     // exit()
#include <cstring>     // memset()
#include <csignal>    // signal()
#include <fcntl.h>     // open()
#include <unistd.h>    // read(), write(), close()
#include <pthread.h>
#include <sys/socket.h> // socket(), connect()
#include <netinet/in.h> // struct sockaddr_in
#include <arpa/inet.h>  // htons()
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/time.h>
#include "sem_u.h"
#include "socket_u.h"
#include "calc_func.h"



int* csock;
static int sem_id = 0;

int time_deler[2] = {0,0};
int num_customer = 0;
int all_money = 0;
void* SocketHandler(void*);
void handler(int signum) {
    close(*csock);
    printf("close socket");
    del_semvalue(sem_id);
    printf("close semaphore");
    FILE *fp;
    fp = fopen("./result.txt","w+");
    char temp_s[128];
    sprintf(temp_s,"customer: %d\nincome: %d$",num_customer,all_money);
    fprintf(fp,temp_s);
    printf("\n%s\n",temp_s);
    exit(1);
}

void timer_handler(int signum) {
    semaphore_p(sem_id);
    if(time_deler[0] > 0) time_deler[0]--;
    if(time_deler[1] > 0) time_deler[1]--;
    semaphore_v(sem_id);
    //printf("timer\n");
}

int main(int argc, char *argv[]){
    
    printf("START");
    fflush(stdout);
    int fd,ret;
    int k=0;
    uint8_t i = 0;
    char temp[1024];
    char count_str[1024];
    struct sigaction sa,sa_timer;
    struct timespec req;
    struct itimerval timer;
    memset(&sa_timer,0,sizeof(sa));
    sa_timer.sa_handler = timer_handler;
    sigaction(SIGALRM , &sa_timer , NULL);
    
    // printf("zzzz \n res\n");
    // printf("%s,%d,%s,%d",res[0]->name,res[0]->distance,res[0]->res_meal[0].name,res[0]->res_meal[1].money);
    // printf("%s,%d,%s,%d",res[1]->name,res[1]->distance,res[1]->res_meal[1].name,res[1]->res_meal[1].money);
    // printf("%s,%d,%s,%d",res[2]->name,res[2]->distance,res[2]->res_meal[0].name,res[2]->res_meal[1].money);
    printf("socket");
    fflush(stdout);
    // Socket 
    socklen_t addr_size = 0;
    sockaddr_in sadr;
    pthread_t thread_id=0;
    signal(SIGINT, handler);
    if(argc < 2){
        printf("\nless port\n");
        return 0;
    }
    int hsock = socket_host(argv[1]);
    // sem
    sem_id = semget((key_t) 1234, 1, 0666 | IPC_CREAT);
    if (!set_semvalue(sem_id)){
        printf("error");
    }
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer , NULL);
    // Accept
    while(1){
        //printf("waiting for a connection\n");
        csock = (int*)malloc(sizeof(int));
        if((*csock = accept(hsock, (sockaddr*)&sadr, &addr_size))!= -1){
            printf("———————\nReceived connection from %s\n",inet_ntoa(sadr.sin_addr));
            fflush(stdout);
            pthread_create(&thread_id,0,&SocketHandler, (void*)csock);
            pthread_detach(thread_id);
        }
        // else{
        //    fprintf(stderr, "Error accept\n");
        // }
    }
    return 0;
}

void* SocketHandler(void* lp){
    int *csock_ = (int*)lp;
    char buffer[1024];
    int buffer_len = 1024;
    char temp[1024];
    int temp_len = 1024;
    char meal_name[128];
    int meal_num = 0;
    int bytecount;
    int i,j,k;
    int count_ = 0;
    int cur_meal = 0;
    int count_meal = 0;
    int total_money = 0;
    int dis_count = 0;
    enum Mode_e mode = INIT;
    enum Mode_e next_mode = INIT;
    char *find_str;
    Restaurant_s* cur_res;
    int cur_del = 0;
    printf("%d",mode);
    fflush(stdout);
    memset(buffer, 0, buffer_len);
    meal_s meal_d[2] ={
    {
        .name = "cookie",
        .money = 60,
        .num = 0,
    },
    {
        .name = "cake",
        .money = 80,
        .num = 0,
    }
    };
    meal_s meal_b[2] ={
        {
            .name = "tea",
            .money = 40,
            .num = 0,
        },
        {
            .name = "boba",
            .money = 70,
            .num = 0,
        }
    };
    meal_s meal_din[2] ={
        {
            .name = "fried-rice",
            .money = 120,
            .num = 0,
        },
        {
            .name = "Egg-drop-soup",
            .money = 50,
            .num = 0,
        }
    };
    Restaurant_s* res[3];
    char name_[2][128];
    int num[2];
    init_all_rest(res,meal_d,meal_b,meal_din);
    while(1){
        bytecount = recv(*csock_, buffer, buffer_len, 0);
        if(bytecount == -1){
            continue;
        }
        else if(bytecount == 0){
            printf("leave \n");
            break;
        }
        else{
            printf("Print %d,%s\n", bytecount, buffer);
            if(strstr(buffer,"shop list") != NULL){
                printf("send shop list");
                fflush(stdout);
                sprintf(temp,"Dessert Shop: 3 min\n- cookie:60$|cake:80$\nBeverage Shop: 5 min\n- tea:40$|boba:70$\nDiner: 8 min - fried-rice:120$|Egg-drop-soup:50$");
                send(*csock_, temp, strlen(temp),0);
                memset(temp, '\0', 1024);
            }
            if(strstr(buffer,"order") != NULL){
                sscanf(buffer,"order %s %d",meal_name,&meal_num);
                printf("order_ %s %ds\n",meal_name,meal_num);
                
                if(mode == INIT){
                    for(i=0;i<3;i++){
                        for(k=0;k<2;k++){
                            if (strstr(meal_name,res[i]->res_meal[k].name)!= NULL){
                                cur_res = res[i];
                                mode = ORDER;
                                //printf("%s\n",cur_res->name);
                                sprintf(temp,"%s %d",meal_name,meal_num);
                                //printf("temp = %s",temp);
                                send(*csock_, temp, strlen(temp)+1,0);
                                cur_res->res_meal[k].num = meal_num;
                                break;
                            }
                        }
                    }
                }
                else if(mode == ORDER){
                    //printf("temp = %s %s\n",temp,meal_name);
                    for(k=0;k<2;k++){
                        if (strstr(meal_name,cur_res->res_meal[k].name)!= NULL){
                            cur_res->res_meal[k].num += meal_num;
                            // if((strstr(temp,meal_name))== NULL){
                            //     sprintf(temp,"%s | %s %d",temp,meal_name,meal_num);
                            //     cur_res->res_meal[k].num = meal_num;
                            //     printf("append : %s\n",temp);
                            // }
                            // else{
                            //     cur_res->res_meal[k].num += meal_num;
                            //     if(strstr(temp,"|")==NULL){
                            //         memset(temp, '\0', 1024);
                            //         sprintf(temp,"%s %d",meal_name,cur_res->res_meal[k].num);
                            //         printf("one : %s\n",temp);
                            //     }
                            //     else{
                            //         sscanf(temp,"%s %d | %s %d",name_[0],&num[0],name_[1],&num[1]);
                            //         for(i=0;i<2;i++){
                            //             if(strstr(name_[i],meal_name)!= NULL){
                            //                 num[i] += meal_num;
                            //                 break;
                            //             }
                            //         }
                            //         memset(temp, '\0', 1024);
                            //         sprintf(temp,"%s %d | %s %d",name_[0],num[0],name_[1],num[1]);
                            //         printf("tow : %s\n",temp);
                            //     }
                            // }
                            memset(temp, '\0', 1024);
                            for(i=0;i<2;i++){
                                if(cur_res->res_meal[i].num != 0){
                                    if(strlen(temp) != 0){
                                        sprintf(temp,"%s|%s %d",temp,cur_res->res_meal[i].name,cur_res->res_meal[i].num);
                                    }
                                    else{
                                        sprintf(temp,"%s %d",cur_res->res_meal[i].name,cur_res->res_meal[i].num);
                                    }
                                    
                                }
                            }
                            //printf("%s match\n",cur_res->name);
                            send(*csock_, temp, strlen(temp)+1,0);
                            //printf("%s\n",temp);
                            break;
                        }
                    }
                    if(k==2){
                        send(*csock_, temp, strlen(temp)+1,0);
                        //printf("not find %s\n",temp);
                    }
                    
                }
            }
            if(strstr(buffer,"confirm") != NULL){
                printf("confirm\n");
                if(mode == INIT){
                    sprintf(temp,"Please order some meals");
                    printf("not order\n");
                    send(*csock_, temp, strlen(temp)+1,0);
                }
                else if(mode == ORDER){
                    total_money = cur_res->res_meal[0].num * cur_res->res_meal[0].money + cur_res->res_meal[1].num * cur_res->res_meal[1].money;
                    semaphore_p(sem_id);
                    if(time_deler[0] <= time_deler[1]){
                        cur_del = 0;
                    }
                    else{
                        cur_del = 1;
                    }
                    
                    //printf("del : %d %d\n",cur_del,time_deler[cur_del]);
                    if((time_deler[cur_del]+cur_res->distance) >= 30){
                        
                        sprintf(temp,"Your meals will take a long time, do you want to wait?");
                        send(*csock_, temp, strlen(temp)+1,0);
                        bytecount = recv(*csock_, buffer, buffer_len, 0);
                        //printf("buffer : %s\n",buffer);
                        if(strstr(buffer,"No") != NULL){
                            init_all_rest(res,meal_d,meal_b,meal_din);
                            //time_deler[cur_del] -= cur_res->distance;
                            semaphore_v(sem_id);
                            break;
                        }
                        time_deler[cur_del] += cur_res->distance;
                    }
                    else{
                        time_deler[cur_del] += cur_res->distance;
                        sprintf(temp,"Please wait a few minutes...");
                        send(*csock_, temp, strlen(temp)+1,0);
                    }
                    
                    //printf("sleep %d\n",time_deler[cur_del]);
                    int time_ = time_deler[cur_del];
                    semaphore_v(sem_id);
                    sleep(time_);
                    
                    sprintf(temp,"Meal completed and you need to pay %d$",total_money);
                    send(*csock_, temp, strlen(temp)+1,0);
                    semaphore_p(sem_id);
                    //time_deler[cur_del] -= cur_res->distance;
                    num_customer += 1;
                    all_money += total_money;
                    semaphore_v(sem_id);
                    mode = CANCEL;
                    cur_res->res_meal[0].num = 0;
                    cur_res->res_meal[1].num = 0;
                    break;
                }
            }
            if(strstr(buffer,"cancel") != NULL){
                init_all_rest(res,meal_d,meal_b,meal_din);
                
                break;
            }
        }
    }
    
} 