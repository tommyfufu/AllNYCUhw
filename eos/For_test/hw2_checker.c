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
int now_time=0;	//1 = 0.1sec
int time_arr[3000]={0};		

void itimer(int signum)
{
	//printf("%d",now_time);
	//fflush(stdout);
	now_time++;
}
void* client_0(void* data)        //part0
{
    
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
  		puts("Connection error");
  		return -1;
   	}


    char input_1[256]="shop list";
    send(sockfd,input_1,256,0);
    char rec[256]={};
    recv(sockfd,rec,sizeof(rec),0);
    if(strcmp(rec,"Dessert Shop: 3 min\n- cookie:60$|cake:80$\nBeverage Shop: 5 min\n- tea:40$|boba:70$\nDiner: 8 min\n- fried-rice:120$|Egg-drop-soup:50$")!=0)
    {
    	l_minus++;
    	printf("********************\nyour commend:\n %s\nanswer:\n Dessert Shop: 3 min\n- cookie:60$|cake:80$\nBeverage Shop: 5 min\n- tea:40$|boba:70$\nDiner: 8 min\n- fried-rice:120$|Egg-drop-soup:50$\n********************\n\n",rec);
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
    if(strcmp(rec,"Please wait a few minutes...")!=0)
    {
    	l_minus++;
    	printf("********************\nyour commend: %s\nanswer: Please wait a few minutes...\n********************\n\n",rec);
    	fflush(stdout);
    }

    recv(sockfd,rec,sizeof(rec),0);

    if(strcmp(rec,"Meal completed and you need to pay 360$")!=0)
    {
    	time_arr[now_time]=1;
    	if(now_time>40 || now_time<20) puts("time error");
    	l_minus++;
    	printf("********************\nyour commend: %s\nanswer: Meal completed and you need to pay 360$\n********************\n\n",rec);
    	fflush(stdout);
    }
    close(sockfd);
}

void* client_1(void* data)        //part1
{
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
	char rec[256]={};
	portNum = strtol(port, &ptr,10);
	info.sin_addr.s_addr = inet_addr(ip);
	info.sin_port = htons(portNum);
	sockfd = socket(AF_INET , SOCK_STREAM , 0);
	if(connect(sockfd,(struct sockaddr *)&info,sizeof(info))==-1)
	{
		puts("Connection error");
		return -1;
	}

	fflush(stdout);

	char input_6[256]="shop list";
	send(sockfd,input_6,256,0);
	recv(sockfd,rec,sizeof(rec),0);
	if(strcmp(rec,"Dessert Shop: 3 min\n- cookie:60$|cake:80$\nBeverage Shop: 5 min\n- tea:40$|boba:70$\nDiner: 8 min\n- fried-rice:120$|Egg-drop-soup:50$")!=0)
	{
		l_minus++;
		printf("********************\nyour commend:\n %s\nanswer:\n Dessert Shop: 3 min\n- cookie:60$|cake:80$\nBeverage Shop: 5 min\n- tea:40$|boba:70$\nDiner: 8 min\n- fried-rice:120$|Egg-drop-soup:50$\n********************\n\n",rec);
		fflush(stdout);
	}
		
	char input_7[256]="confirm";
	send(sockfd,input_7,256,0);
	recv(sockfd,rec,sizeof(rec),0);
	if(strcmp(rec,"Please order some meals")!=0)
	{
		l_minus++;
		printf("********************\nyour commend: %s\nanswer: Please order some meals\n********************\n\n",rec);
		fflush(stdout);
	}

	char input_8[256]="order Egg-drop-soup 100";
	send(sockfd,input_8,256,0);
	recv(sockfd,rec,sizeof(rec),0);
	if(strcmp(rec,"Egg-drop-soup 100")!=0)
	{
		l_minus++;
		printf("********************\nyour commend: %s\nanswer: Egg-drop-soup 100\n********************\n\n",rec);
		fflush(stdout);
	}

	char input_9[256]="order fried-rice 1";
	send(sockfd,input_9,256,0);
	recv(sockfd,rec,sizeof(rec),0);
	if(strcmp(rec,"fried-rice 1|Egg-drop-soup 100")!=0)
	{
		l_minus++;
		printf("********************\nyour commend: %s\nanswer: fried-rice 1|Egg-drop-soup 100\n********************\n\n",rec);
		fflush(stdout);
	}

	char input_10[256]="shop list";
	send(sockfd,input_10,256,0);
	recv(sockfd,rec,sizeof(rec),0);
	if(strcmp(rec,"Dessert Shop: 3 min\n- cookie:60$|cake:80$\nBeverage Shop: 5 min\n- tea:40$|boba:70$\nDiner: 8 min\n- fried-rice:120$|Egg-drop-soup:50$")!=0)
	{
		l_minus++;
		printf("********************\nyour commend:\n %s\nanswer:\n Dessert Shop: 3 min\n- cookie:60$|cake:80$\nBeverage Shop: 5 min\n- tea:40$|boba:70$\nDiner: 8 min\n- fried-rice:120$|Egg-drop-soup:50$\n********************\n\n",rec);
		fflush(stdout);
	}

	char input_11[256]="cancel";
	send(sockfd,input_11,256,0);
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
	char rec[256] = {};
    ip = argv[1];
    port = argv[2];
    if(argv[3]==NULL)
    	pword="0";
    else 
    	pword = argv[3];
    if(ip==NULL||port==NULL)
    {
    	puts("格式: ./hw2_checker <ip> <port>");
    	return -1;
    }

   	puts("start testing...\n\n");
    fflush(stdout);
	pthread_t th[50];
    pthread_create(&th[0],NULL,client_0,(void*)0);
	pthread_create(&th[1],NULL,client_0,(void*)1);
	pthread_join(th[0], NULL);
	pthread_join(th[1], NULL);
	printf("part1結束\n\n\n");

    fflush(stdout);
    //####################################################################//
    for(int i=2;i<22;i++)
    {
		pthread_create(&th[i], NULL, client_1, (void*)i);
	}
	for(int i=2;i<22;i++)
    {
        pthread_join(th[i], NULL);
    }
   	printf("part2結束\n\n\n");
	fflush(stdout);

    //####################################################################//
	portNum = strtol(port, &ptr,10);
    info.sin_addr.s_addr = inet_addr(ip);
    info.sin_port = htons(portNum);
    sockfd = socket(AF_INET , SOCK_STREAM , 0);
    if(connect(sockfd,(struct sockaddr *)&info,sizeof(info))==-1)
  	{
  		puts("Connection error");
  		return -1;
   	}

    fflush(stdout);

    char input_6[256]="shop list";
    send(sockfd,input_6,256,0);
    recv(sockfd,rec,sizeof(rec),0);
    if(strcmp(rec,"Dessert Shop: 3 min\n- cookie:60$|cake:80$\nBeverage Shop: 5 min\n- tea:40$|boba:70$\nDiner: 8 min\n- fried-rice:120$|Egg-drop-soup:50$")!=0)
    {
    	l_minus++;
    	printf("********************\nyour commend:\n %s\nanswer:\n Dessert Shop: 3 min\n- cookie:60$|cake:80$\nBeverage Shop: 5 min\n- tea:40$|boba:70$\nDiner: 8 min\n- fried-rice:120$|Egg-drop-soup:50$\n********************\n\n",rec);
    	fflush(stdout);
    }
        
    char input_7[256]="confirm";
    send(sockfd,input_7,256,0);
    recv(sockfd,rec,sizeof(rec),0);
    if(strcmp(rec,"Please order some meals")!=0)
    {
    	l_minus++;
    	printf("********************\nyour commend: %s\nanswer: Please order some meals\n********************\n\n",rec);
    	fflush(stdout);
    }

    char input_8[256]="order boba 100";
    send(sockfd,input_8,256,0);
    recv(sockfd,rec,sizeof(rec),0);
    if(strcmp(rec,"boba 100")!=0)
    {
    	l_minus++;
    	printf("********************\nyour commend: %s\nanswer: boba 100\n********************\n\n",rec);
    	fflush(stdout);
    }

    char input_9[256]="order tea 1";
    send(sockfd,input_9,256,0);
    recv(sockfd,rec,sizeof(rec),0);
    if(strcmp(rec,"tea 1|boba 100")!=0)
    {
    	l_minus++;
    	printf("********************\nyour commend: %s\nanswer: tea 1|boba 100\n********************\n\n",rec);
    	fflush(stdout);
    }

    char input_10[256]="confirm";
    send(sockfd,input_10,256,0);
    int start_time = now_time;
    recv(sockfd,rec,sizeof(rec),0);
    if(strcmp(rec,"Please wait a few minutes...")!=0)
    {
    	l_minus++;
    	printf("********************\nyour commend: %s\nanswer: Please wait a few minutes...\n********************\n\n",rec);
    	fflush(stdout);
    }

    recv(sockfd,rec,sizeof(rec),0);
    if(strcmp(rec,"Meal completed and you need to pay 7040$")!=0)
    {
    	l_minus++;
    	printf("********************\nyour commend: %s\nanswer: Meal completed and you need to pay 7040$\n********************\n\n",rec);
    	fflush(stdout);
    }
    time_arr[now_time]=1;
    if(now_time-start_time>60 || now_time-start_time<40) puts("time error");

    printf("part3結束\n\n\n");
    fflush(stdout);


    close(sockfd);
    //####################################################################//

}