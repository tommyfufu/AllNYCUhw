
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/syscall.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DRESSERT_SHOP_NO     	0
#define BEVERAGE_SHIO_NO    	1
#define DINER_NO            	2

#define NULL_MEAL		        0x00
#define COOKIE			        0x01
#define CAKE			        0x22
#define TEA			            0x03
#define BOBA			        0x24
#define FRIED_RICE		        0x05
#define EGG_DROP_SOUP		    0x26	

char meal_str[6][15] = {
    "cookie", "cake", "tea", "boba", "fried-rice", "Egg-drop-soup",
};

char meal_price[3][2]={{60, 80}, {40, 70}, {120, 50}};
char meal_cook_time[3] = {3, 5, 8};
// char meal_order_list[4]; // meal_1, meal_2, qty_1, qty_2

void order_machine(int fd);
void meal_menu(int fd);
void parser_cmd(int fd, char *cmd_str, int *order_list);
void parser_order_cmd(char *cmd_str, char *odr_no, char *odr_qty);
int parser_meal_quantity(char *cmd_str);
char cal_cook_time(char odr_no);
int cal_order_bill(int *order_list);
void end_process(int fd);





int main(int argc, char *argv[])
{
    int socket_port=atoi(argv[1]);

    // printf("Main_pid: %d, port: %d\n", getpid(), socket_port);
    struct sockaddr_in stSockAddr;
    int ConnectFD, SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(-1 == SocketFD)
    {
        perror("can not create socket");
        exit(EXIT_FAILURE);
    }
 
    memset(&stSockAddr, 0, sizeof(struct sockaddr_in));
 
    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(socket_port);
    stSockAddr.sin_addr.s_addr = INADDR_ANY;
    
    if(-1 == bind(SocketFD,(const struct sockaddr *)&stSockAddr, sizeof(struct sockaddr_in)))
    {
        perror("error bind failed");
        close(SocketFD);
        exit(EXIT_FAILURE);
    }


    int i;
    while(1)
    {
        if(-1 == listen(SocketFD, 10))
        {
            perror("error listen failed");
            close(SocketFD);
            exit(EXIT_FAILURE);
        }

        ConnectFD = accept(SocketFD, NULL, NULL);
     
        pid_t PID_STATE = fork();

        switch(PID_STATE)
        {
            case -1:
                perror("fork()");
                exit(-1);
                break;
            case 0:
                // Child process.     
                order_machine(ConnectFD);                
                break;
            default:
                // Parent process.
                break;
        }
    }
    close(ConnectFD);
    shutdown(SocketFD, SHUT_RDWR);
    close(SocketFD);
    return 0;
}

void order_machine(int fd)
{
    char buf[256]={};
    int meal_order_list[4] = {0}; // meal_1, meal_2, qty_1, qty_2
    while(1)
    {
        memset(buf, 0, sizeof(buf));
        recv(fd, buf, sizeof(buf), 0);
        parser_cmd(fd, buf, meal_order_list);
    }
}


void meal_menu(int fd)
{
    char buf[256];
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "Dessert Shop: 3 min\n- cookie:60$|cake:80$\nBeverage Shop: 5 min\n- tea:40$|boba:70$\nDiner: 8 min\n- fried-rice:120$|Egg-drop-soup:50$");
    send(fd, buf, sizeof(buf), 0);
}

void parser_cmd(int fd, char *cmd_str, int *order_list)
{
    char i=0;
    char cmd_str_tmp[32];
    char tx_buf[256];
    char buf_tmp1[64], buf_tmp2[32];
    char odr_no, odr_idx, odr_qty, str_idx, cook_time;    
    
    memset(cmd_str_tmp, 0, sizeof(cmd_str_tmp));
    if(((cmd_str[0] == 'O') || (cmd_str[0] == 'o')) &&
       ((cmd_str[1] == 'R') || (cmd_str[1] == 'r')) &&
       ((cmd_str[2] == 'D') || (cmd_str[2] == 'd')) &&
       ((cmd_str[3] == 'E') || (cmd_str[3] == 'e')) &&
       ((cmd_str[4] == 'R') || (cmd_str[4] == 'r')))
    {
        
        memcpy(cmd_str_tmp, cmd_str+6, 32);
        parser_order_cmd(cmd_str_tmp, &odr_no, &odr_qty);
        odr_idx = (odr_no & 0xF0)>>4;

        if(odr_no != 0)
        {
            if(order_list[odr_idx] != 0)
            {
                if(((order_list[0] & 0xF0) == (odr_no & 0xF0)) ||
                   ((order_list[2] & 0xF0) == (odr_no & 0xF0)))
                {
                    if((order_list[odr_idx] == odr_no))
                    {
                        // Have same shop order add ord_qty
                        order_list[odr_idx+1] += odr_qty;
                    }
                    else
                    {
                        // Different shop can not accpet order
                    }  
                }            
            }
            else
            {
                if((order_list[0] == 0) && (order_list[2] == 0))
                {
                    order_list[odr_idx] = odr_no;
                    order_list[odr_idx+1] += odr_qty;
                }
                else
                {
                    if((order_list[0] == 0) && 
                       ((((order_list[2] & 0x0F) - 1) / 2) == (((odr_no & 0x0F) - 1) / 2))) 
                    {
                        order_list[odr_idx] = odr_no;
                        order_list[odr_idx+1] += odr_qty;
                    }
                    else if((order_list[2] == 0) && 
                       ((((order_list[0] & 0x0F) - 1) / 2) == (((odr_no & 0x0F) - 1) / 2))) 
                    {
                        order_list[odr_idx] = odr_no;
                        order_list[odr_idx+1] += odr_qty;
                    }
                    else
                    {

                    }
                }
            }
            memset(tx_buf, 0, sizeof(tx_buf));
            memset(buf_tmp1, 0, sizeof(buf_tmp1));
            memset(buf_tmp2, 0, sizeof(buf_tmp2));

            if((order_list[0] != 0) && (order_list[2] != 0))
            {                
                str_idx = (order_list[odr_idx] & 0x0F) - 0x01;
                strncpy(buf_tmp1, meal_str[(order_list[0] & 0x0F)-1] , sizeof(meal_str[(order_list[0] & 0x0F)-1]));
                i=0;
                buf_tmp2[i++] = ' ';
                if(order_list[1] > 99)
                {
                    buf_tmp2[i++] = (order_list[1] / 100) + '0';
                    buf_tmp2[i++] = ((order_list[1] / 100) / 10) + '0';                    
                    buf_tmp2[i++] = (order_list[1] % 10) + '0'; 

                }
                else
                {
                    if(order_list[1] > 9)
                    {
                        buf_tmp2[i++] = (order_list[1] / 10) + '0';
                        buf_tmp2[i++] = (order_list[1] % 10) + '0';
                    }
                    else
                    {
                        buf_tmp2[i++] = order_list[1]  + '0';
                    }
                }

                buf_tmp2[i++] = '|';
                strcat(buf_tmp1, buf_tmp2);
                memcpy(tx_buf, buf_tmp1, sizeof(buf_tmp1));
                memset(buf_tmp1, 0, sizeof(buf_tmp1));
                memset(buf_tmp2, 0, sizeof(buf_tmp2));
                strncpy(buf_tmp1, meal_str[(order_list[2] & 0x0F)-1] , sizeof(meal_str[(order_list[2] & 0x0F)-1]));
                
                i=0;
                buf_tmp2[i++] = ' ';
                if(order_list[3] > 99)
                {
                    buf_tmp2[i++] = (order_list[3] / 100) + '0';
                    buf_tmp2[i++] = ((order_list[3] / 100) / 10) + '0';
                    buf_tmp2[i++] = (order_list[3] % 10) + '0';
                }
                else
                {
                    if(order_list[3] > 9)
                    {
                        buf_tmp2[i++] = (order_list[3] / 10) + '0';
                        buf_tmp2[i++] = (order_list[3] % 10) + '0';
                    }
                    else
                    {
                        buf_tmp2[i++] = order_list[3]  + '0';
                    }
                }

                strcat(buf_tmp1, buf_tmp2);
                strcat(tx_buf, buf_tmp1);
                memset(buf_tmp1, 0, sizeof(buf_tmp1));
                memset(buf_tmp2, 0, sizeof(buf_tmp2));                        
            }
            else
            {
                
                if(!order_list[0] || !order_list[2])
                {
                    if(order_list[0] != 0)
                        odr_idx = 0;
                    else
                        odr_idx = 2;

                    str_idx = (order_list[odr_idx] & 0x0F) - 0x01;
                    strncpy(buf_tmp1, meal_str[str_idx] , sizeof(meal_str[str_idx]));

                    i=0;
                    buf_tmp2[i++] = ' ';
                    if(order_list[odr_idx+1] > 99)
                    {
                        buf_tmp2[i++] = (order_list[odr_idx+1] / 100) + '0';
                        buf_tmp2[i++] = ((order_list[odr_idx+1] / 100) / 10) + '0';
                        buf_tmp2[i++] = (order_list[odr_idx+1] % 10) + '0';
                    }
                    else
                    {
                        if(order_list[odr_idx+1] > 9)
                        {
                            buf_tmp2[i++] = (order_list[odr_idx+1] / 10) + '0';
                            buf_tmp2[i++] = (order_list[odr_idx+1] % 10) + '0';
                        }
                        else
                        {
                            buf_tmp2[i++] = order_list[odr_idx+1]  + '0';
                        }
                    }
                    strcat(buf_tmp1, buf_tmp2);
                    strncpy(tx_buf, buf_tmp1, sizeof(buf_tmp1));
                    memset(buf_tmp1, 0, sizeof(buf_tmp1));
                    memset(buf_tmp2, 0, sizeof(buf_tmp2));
                }
            }
            send(fd, tx_buf, sizeof(tx_buf), 0);
        }    
    }
    else if(((cmd_str[0] == 'C') || (cmd_str[0] == 'c')) &&
            ((cmd_str[1] == 'A') || (cmd_str[1] == 'a')) &&
            ((cmd_str[2] == 'N') || (cmd_str[2] == 'n')) &&
            ((cmd_str[3] == 'C') || (cmd_str[3] == 'c')) &&
            ((cmd_str[4] == 'E') || (cmd_str[4] == 'e')) &&
            ((cmd_str[5] == 'L') || (cmd_str[5] == 'l')))
    {
        memset(tx_buf, 0, sizeof(tx_buf));
        memset(order_list, 0, sizeof(order_list));
        end_process(fd);
    }
    else if(((cmd_str[0] == 'C') || (cmd_str[0] == 'c')) &&
            ((cmd_str[1] == 'O') || (cmd_str[1] == 'o')) &&
            ((cmd_str[2] == 'N') || (cmd_str[2] == 'n')) &&
            ((cmd_str[3] == 'F') || (cmd_str[3] == 'f')) &&
            ((cmd_str[4] == 'I') || (cmd_str[4] == 'i')) &&
            ((cmd_str[5] == 'R') || (cmd_str[5] == 'r')) &&
            ((cmd_str[6] == 'M') || (cmd_str[6] == 'm')))
    {
        memset(tx_buf, 0, sizeof(tx_buf));
        if((order_list[0] == 0) && (order_list[2] == 0))
        {
            memset(tx_buf, 0, sizeof(tx_buf));
            sprintf(tx_buf, "Please order some meals");
            send(fd, tx_buf, sizeof(tx_buf), 0);
        }
        else
        {
            cook_time = cal_cook_time(order_list[0]);
            // memset(tx_buf, 0, sizeof(tx_buf));
            sprintf(tx_buf, "Please wait a few minutes...");
            printf("cook time: %d\n", cook_time);
            send(fd, tx_buf, sizeof(tx_buf), 0);

            sleep(cook_time);
            // usleep(cook_time* 1000 * 1000);
            memset(tx_buf, 0, sizeof(tx_buf));
            sprintf(tx_buf, "Meal completed and you need to pay %d$", cal_order_bill(order_list)); 
            send(fd, tx_buf, sizeof(tx_buf), 0);   
            printf("completed\n");
            // sleep(1); 
            end_process(fd);   
        }
    }
    else if(((cmd_str[0] == 'S') || (cmd_str[0] == 's')) &&
            ((cmd_str[1] == 'H') || (cmd_str[1] == 'h')) &&
            ((cmd_str[2] == 'O') || (cmd_str[2] == 'o')) &&
            ((cmd_str[3] == 'P') || (cmd_str[3] == 'p')) &&
            ((cmd_str[4] == ' ')                       ) &&
            ((cmd_str[5] == 'L') || (cmd_str[5] == 'l')) &&
            ((cmd_str[6] == 'I') || (cmd_str[6] == 'i')) &&
            ((cmd_str[7] == 'S') || (cmd_str[7] == 's')) &&
            ((cmd_str[8] == 'T') || (cmd_str[8] == 't')))
    {  
        meal_menu(fd);
    }
    else
    {   
 
    }
}

void parser_order_cmd(char *cmd_str, char *odr_no, char *odr_qty)
{
    char i=0;
    char cmd_str_tmp[15];

    if(((cmd_str[0] == 'C') || (cmd_str[0] == 'c')) &&
       ((cmd_str[1] == 'O') || (cmd_str[1] == 'o')) &&
       ((cmd_str[2] == 'O') || (cmd_str[2] == 'o')) &&
       ((cmd_str[3] == 'K') || (cmd_str[3] == 'k')) &&
       ((cmd_str[4] == 'I') || (cmd_str[4] == 'i')) &&
       ((cmd_str[5] == 'E') || (cmd_str[5] == 'e')))
    {
        odr_no[0] = COOKIE;
        memcpy(cmd_str_tmp, cmd_str+7, 10);        
        odr_qty[0] = parser_meal_quantity(cmd_str_tmp);
    }
    else if(((cmd_str[0] == 'C') || (cmd_str[0] == 'c')) &&
            ((cmd_str[1] == 'A') || (cmd_str[1] == 'a')) &&
            ((cmd_str[2] == 'K') || (cmd_str[2] == 'k')) &&
            ((cmd_str[3] == 'E') || (cmd_str[3] == 'e')))
    {
        odr_no[0] = CAKE;
        memcpy(cmd_str_tmp, cmd_str+5, 10);        
        odr_qty[0] = parser_meal_quantity(cmd_str_tmp);
    }
    else if(((cmd_str[0] == 'T') || (cmd_str[0] == 't')) &&
            ((cmd_str[1] == 'E') || (cmd_str[1] == 'e')) &&
            ((cmd_str[2] == 'A') || (cmd_str[2] == 'a')))
    {
        odr_no[0] = TEA;
        memcpy(cmd_str_tmp, cmd_str+4, 10);        
        odr_qty[0] = parser_meal_quantity(cmd_str_tmp);
    }
    else if(((cmd_str[0] == 'B') || (cmd_str[0] == 'b')) &&
            ((cmd_str[1] == 'O') || (cmd_str[1] == 'o')) &&
            ((cmd_str[2] == 'B') || (cmd_str[2] == 'b')) &&
            ((cmd_str[3] == 'A') || (cmd_str[3] == 'a')))
    {
        odr_no[0] = BOBA;
        memcpy(cmd_str_tmp, cmd_str+5, 10);        
        odr_qty[0] = parser_meal_quantity(cmd_str_tmp);
    }
    else if(((cmd_str[0] == 'F') || (cmd_str[0] == 'f')) &&
            ((cmd_str[1] == 'R') || (cmd_str[1] == 'r')) &&
            ((cmd_str[2] == 'I') || (cmd_str[2] == 'i')) &&
            ((cmd_str[3] == 'E') || (cmd_str[3] == 'e')) &&
            ((cmd_str[4] == 'D') || (cmd_str[4] == 'd')) &&
            ((cmd_str[5] == '-')                       ) &&
            ((cmd_str[6] == 'R') || (cmd_str[6] == 'r')) &&
            ((cmd_str[7] == 'I') || (cmd_str[7] == 'i')) &&
            ((cmd_str[8] == 'C') || (cmd_str[8] == 'c')) &&        
            ((cmd_str[9] == 'E') || (cmd_str[9] == 'e')))
    {
        odr_no[0] = FRIED_RICE;
        memcpy(cmd_str_tmp, cmd_str+11, 10);        
        odr_qty[0] = parser_meal_quantity(cmd_str_tmp);
    }
    else if(((cmd_str[0]  == 'E') || (cmd_str[0]  == 'e')) &&
            ((cmd_str[1]  == 'G') || (cmd_str[1]  == 'g')) &&
            ((cmd_str[2]  == 'G') || (cmd_str[2]  == 'g')) &&
            ((cmd_str[3]  == '-')                       )  &&
            ((cmd_str[4]  == 'D') || (cmd_str[4]  == 'd')) &&
            ((cmd_str[5]  == 'R') || (cmd_str[5]  == 'r')) &&
            ((cmd_str[6]  == 'O') || (cmd_str[6]  == 'o')) &&
            ((cmd_str[7]  == 'P') || (cmd_str[7]  == 'p')) &&
            ((cmd_str[8]  == '-')                        ) &&     
            ((cmd_str[9]  == 'S') || (cmd_str[9]  == 's')) &&
            ((cmd_str[10] == 'O') || (cmd_str[10] == 'o')) &&
            ((cmd_str[11] == 'U') || (cmd_str[11] == 'u')) &&   
            ((cmd_str[12] == 'P') || (cmd_str[12] == 'p')))
    {
        odr_no[0] = EGG_DROP_SOUP;
        memcpy(cmd_str_tmp, cmd_str+14, 10);        
        odr_qty[0] = parser_meal_quantity(cmd_str_tmp);
    }
    else
    {   
        odr_no[0] = NULL_MEAL;
        memcpy(cmd_str_tmp, cmd_str+14, 10);        
        odr_qty[0] = 0;
    }
}

int parser_meal_quantity(char *cmd_str)
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

char cal_cook_time(char odr_no)
{
    return meal_cook_time[((odr_no & 0x0F) - 1) / 2];
}

int cal_order_bill(int *order_list)
{
    char i, shop_idx, price_idx;
    int bill = 0;
    for(i=0; i<2; i++)
    {
        if(order_list[i*2] != 0)
        {
            shop_idx = ((order_list[i*2] & 0x0F) - 1) / 2; 
            price_idx = ((order_list[i*2] & 0x0F) - 1) % 2;       
            bill += meal_price[shop_idx][price_idx] * order_list[i*2+1];
        }
    }
    return bill;
}

void end_process(int fd)
{
    close(fd);
}


