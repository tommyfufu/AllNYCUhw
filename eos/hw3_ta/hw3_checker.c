#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <pthread.h>
#include <fcntl.h>
#include <semaphore.h>
#include <signal.h>


char *ip;
char *port;
char *pword;
int now_time=0; //1 = 0.1sec
int time_arr[3000]={0};     
sem_t timearr_sem;
void itimer(int signum)
{
    //printf("%d",now_time);
    //fflush(stdout);
    now_time++;
}
void* client_0(void* data)        //part0
{
    
    int client_id=data;

    int l_minus=0;
    //socket的建立
    int sockfd = 0;
    //socket的連線
    struct sockaddr_in info;
    bzero(&info,sizeof(info));
    info.sin_family = PF_INET;
    //localhost test
    int portNum;
    char *ptr;

    portNum = strtol(port, &ptr,10);
    info.sin_addr.s_addr = inet_addr(ip);
    info.sin_port = htons(portNum);
    sockfd = socket(AF_INET , SOCK_STREAM , 0);

    if(connect(sockfd,(struct sockaddr *)&info,sizeof(info))==-1)
    {
        
        printf("thread%dConnection error\n",client_id);

        fflush(stdout);
    }


    char input_1[256]="shop list";
    send(sockfd,input_1,256,0);
    char rec[256]={};
    recv(sockfd,rec,sizeof(rec),0);
    if(strcmp(rec,"Dessert Shop: 3 min\n- cookie:60$|cake:80$\nBeverage Shop: 5 min\n- tea:40$|boba:70$\nDiner: 8 min - fried-rice:120$|Egg-drop-soup:50$")!=0)
    {
        l_minus++;
        printf("********************\nyour commend:\n %s\nanswer:\n Dessert Shop: 3 min\n- cookie:60$|cake:80$\nBeverage Shop: 5 min\n- tea:40$|boba:70$\nDiner: 8 min - fried-rice:120$|Egg-drop-soup:50$\n********************\n\n",rec);
        fflush(stdout);
    }
        
    char input_2[256]="order cookie 3";
    send(sockfd,input_2,256,0);
    recv(sockfd,rec,sizeof(rec),0);
    if(strcmp(rec,"cookie 3")!=0)
    {
        l_minus++;
        printf("********************\nyour commend: %s\nanswer: cookie 3\n********************\n\n",rec);
        fflush(stdout);
    }

    char input_3[256]="order cookie 3";
    send(sockfd,input_3,256,0);
    recv(sockfd,rec,sizeof(rec),0);
    if(strcmp(rec,"cookie 6")!=0)
    {
        l_minus++;
        printf("********************\nyour commend: %s\nanswer: cookie 6\n********************\n\n",rec);
        fflush(stdout);
    }

    char input_4[256]="order tea 1";
    send(sockfd,input_4,256,0);
    recv(sockfd,rec,sizeof(rec),0);
    if(strcmp(rec,"cookie 6")!=0)
    {
        l_minus++;
        printf("********************\nyour commend: %s\nanswer: cookie 6\n********************\n\n",rec);
        fflush(stdout);
    }

    char input_5[256]="confirm";
    send(sockfd,input_5,256,0);
    recv(sockfd,rec,sizeof(rec),0);
    if(strcmp(rec,"Please wait a few minutes...")==0)
    {
        recv(sockfd,rec,sizeof(rec),0);

        if(strcmp(rec,"Meal completed and you need to pay 360$")!=0)
        {
            time_arr[now_time]+=1;
            l_minus++;
            printf("********************\nyour commend: %s\nanswer: Meal completed and you need to pay 360$\n********************\n\n",rec);
            fflush(stdout);
        }
        printf("client%d finish1\n",client_id);
        fflush(stdout);
        sem_wait(&timearr_sem);
        time_arr[now_time]+=1;
        sem_post(&timearr_sem);
    }
    else if(strcmp(rec,"Your meals will take a long time, do you want to wait?")==0)
    {
        char input_6[256]="Yes";
        send(sockfd,input_6,256,0); 
        recv(sockfd,rec,sizeof(rec),0); 
        if(strcmp(rec,"Meal completed and you need to pay 360$")!=0)
        {
            l_minus++;
            printf("********************\nyour commend: %s\nanswer: Meal completed and you need to pay 360$\n********************\n\n",rec);
            fflush(stdout);
        }
        printf("client%d finish1\n",client_id);
        fflush(stdout);  
        sem_wait(&timearr_sem);
        time_arr[now_time]+=1;
        sem_post(&timearr_sem);
    }
    else
    {
        printf("********************\nyour commend: %s\nanswer: Please wait a few minutes... or Your meals will take a long time, do you want to wait?\n********************\n\n",rec);
        fflush(stdout);
    }
    
    close(sockfd);
}
void* client_1(void* data)        //part1
{
    
    int client_id=data;

    int l_minus=0;
    //socket的建立
    int sockfd = 0;
    //socket的連線
    struct sockaddr_in info;
    bzero(&info,sizeof(info));
    info.sin_family = PF_INET;
    //localhost test
    int portNum;
    char *ptr;

    portNum = strtol(port, &ptr,10);
    info.sin_addr.s_addr = inet_addr(ip);
    info.sin_port = htons(portNum);
    sockfd = socket(AF_INET , SOCK_STREAM , 0);

    if(connect(sockfd,(struct sockaddr *)&info,sizeof(info))==-1)
    {
        
        printf("thread%dConnection error\n",client_id);

        fflush(stdout);
    }

    char input_1[256]="confirm";
    send(sockfd,input_1,256,0);
    char rec[256]={};
    recv(sockfd,rec,sizeof(rec),0);
    if(strcmp(rec,"Please order some meals")!=0)
    {
        l_minus++;
        printf("********************\nyour commend: %s\nanswer: Please order some meals\n********************\n\n",rec);
        fflush(stdout);
    }
    
    char input_2[256]="order Egg-drop-soup 2";
    send(sockfd,input_2,256,0);
    recv(sockfd,rec,sizeof(rec),0);
    if(strcmp(rec,"Egg-drop-soup 2")!=0)
    {
        l_minus++;
        printf("********************\nyour commend: %s\nanswer: Egg-drop-soup 2\n********************\n\n",rec);
        fflush(stdout);
    }   
    //printf("client%d order\n",client_id);
    //fflush(stdout);   
    char input_3[256]="confirm";
    send(sockfd,input_3,256,0);
    recv(sockfd,rec,sizeof(rec),0);
    if(strcmp(rec,"Please wait a few minutes...")==0)
    {
        recv(sockfd,rec,sizeof(rec),0);
        if(strcmp(rec,"Meal completed and you need to pay 100$")!=0)
        {
            time_arr[now_time]+=1;
            l_minus++;
            printf("********************\nyour commend: %s\nanswer: Meal completed and you need to pay 100$\n********************\n\n",rec);
            fflush(stdout);
        }
        printf("client%d finish1\n",client_id);
        fflush(stdout);
        sem_wait(&timearr_sem);
        time_arr[now_time]+=1;
        sem_post(&timearr_sem);
    }
    else if(strcmp(rec,"Your meals will take a long time, do you want to wait?")==0)
    {
        printf("client%d finish0\n",client_id);
        fflush(stdout);
        char input_4[256]="No";
        send(sockfd,input_4,256,0);     
    }
    else
    {
        printf("********************\nyour commend: %s\nanswer: Please wait a few minutes... or Your meals will take a long time, do you want to wait?\n********************\n\n",rec);
        fflush(stdout);
    }
    
    
    fflush(stdout);
    close(sockfd);
}
void* client_2(void* data)        //part2
{
    
    int client_id=data;

    int l_minus=0;
    //socket的建立
    int sockfd = 0;
    //socket的連線
    struct sockaddr_in info;
    bzero(&info,sizeof(info));
    info.sin_family = PF_INET;
    //localhost test
    int portNum;
    char *ptr;

    portNum = strtol(port, &ptr,10);
    info.sin_addr.s_addr = inet_addr(ip);
    info.sin_port = htons(portNum);
    sockfd = socket(AF_INET , SOCK_STREAM , 0);

    if(connect(sockfd,(struct sockaddr *)&info,sizeof(info))==-1)
    {
        
        printf("thread%dConnection error\n",client_id);

        fflush(stdout);
    }

    char input_1[256]="confirm";
    send(sockfd,input_1,256,0);
    char rec[256]={};
    recv(sockfd,rec,sizeof(rec),0);
    if(strcmp(rec,"Please order some meals")!=0)
    {
        l_minus++;
        printf("********************\nyour commend: %s\nanswer: Please order some meals\n********************\n\n",rec);
        fflush(stdout);
    }
    
    char input_2[256]="order fried-rice 1";
    send(sockfd,input_2,256,0);
    recv(sockfd,rec,sizeof(rec),0);
    if(strcmp(rec,"fried-rice 1")!=0)
    {
        l_minus++;
        printf("********************\nyour commend: %s\nanswer: fried-rice 1\n********************\n\n",rec);
        fflush(stdout);
    }   
    
    char input_3[256]="confirm";
    send(sockfd,input_3,256,0);
    recv(sockfd,rec,sizeof(rec),0);
    if(strcmp(rec,"Please wait a few minutes...")==0)
    {
        recv(sockfd,rec,sizeof(rec),0);

        if(strcmp(rec,"Meal completed and you need to pay 120$")!=0)
        {
            time_arr[now_time]+=1;
            l_minus++;
            printf("********************\nyour commend: %s\nanswer: Meal completed and you need to pay 120$\n********************\n\n",rec);
            fflush(stdout);
        }
        printf("client%d finish1\n",client_id);
        fflush(stdout);
        sem_wait(&timearr_sem);
        time_arr[now_time]+=1;
        sem_post(&timearr_sem);
    }
    else if(strcmp(rec,"Your meals will take a long time, do you want to wait?")==0)
    {
        char input_4[256]="Yes";
        send(sockfd,input_4,256,0); 
        recv(sockfd,rec,sizeof(rec),0); 
        if(strcmp(rec,"Meal completed and you need to pay 120$")!=0)
        {
            l_minus++;
            printf("********************\nyour commend: %s\nanswer: Meal completed and you need to pay 120$\n********************\n\n",rec);
            fflush(stdout);
        }
        printf("client%d finish1\n",client_id);
        fflush(stdout);  
        sem_wait(&timearr_sem);
        time_arr[now_time]+=1;
        sem_post(&timearr_sem);
    }
    else
    {
        printf("********************\nyour commend: %s\nanswer: Please wait a few minutes... or Your meals will take a long time, do you want to wait?\n********************\n\n",rec);
        fflush(stdout);
    }
    
    close(sockfd);
}
int main(int argc , char *argv[])
{
    struct itimerval timer;
    timer.it_value.tv_sec=0;
    timer.it_value.tv_usec=100000;
    timer.it_interval.tv_sec=0;
    timer.it_interval.tv_usec=100000 ;
    setitimer(ITIMER_REAL,&timer,NULL);
    signal(SIGALRM,itimer);
    sem_init(&timearr_sem,0,1);
    //####################################################################//

    int l_minus=0;
    //socket的建立
    int sockfd = 0;
    //socket的連線
    struct sockaddr_in info;
    bzero(&info,sizeof(info));
    info.sin_family = PF_INET;
    //localhost test
    int portNum;
    char *ptr;
    ip = argv[1];
    port = argv[2];
    if(argv[3]==NULL)
        pword="0";
    else 
        pword = argv[3];
    if(ip==NULL||port==NULL)
    {
        puts("格式: ./hw3_checker <ip> <port>");
        return -1;
    }

    portNum = strtol(port, &ptr,10);
    info.sin_addr.s_addr = inet_addr(ip);
    info.sin_port = htons(portNum);
    sockfd = socket(AF_INET , SOCK_STREAM , 0);


    pthread_t th[50];
    pthread_create(&th[36],NULL,client_0,(void*)36);

    for(int i=0;i<32;i++)
    {
        pthread_create(&th[i], NULL, client_1, (void*)i);

    }
    sleep(5);
    pthread_create(&th[32], NULL, client_2, (void*)32);
    pthread_create(&th[33], NULL, client_2, (void*)33);
    pthread_create(&th[34], NULL, client_2, (void*)34);
    pthread_create(&th[35], NULL, client_2, (void*)35);
    
    for(int i=0;i<32;i++)
    {
        pthread_join(th[i], NULL);

    }
    pthread_join(th[32], NULL);
    pthread_join(th[33], NULL);
    pthread_join(th[34], NULL);
    pthread_join(th[35], NULL);
    pthread_join(th[36], NULL);
    //ime_arr_checker(time_arr);

    printf("time log: ");
    for(int i=0;i<500;i++)
    {
        if(time_arr[i])
            printf("%.1f:%d | ",i/10.0,time_arr[i]);
    }
    puts("");








}