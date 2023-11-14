#pragma once
//#include "/home/lu/microtime/linux/include/asm-arm/arch-pxa/lib/creator_pxa270_lcd.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
struct meal{
    char *name;
    int money;
    int num;
};
struct Restaurant{
    char *name;
    struct meal *res_meal;
    int distance;
    int total;
};

enum Mode_e {
    INIT, LIST, ORDER, MEAL, COUNT, CONFIRM,PICK,CANCEL
};

struct node{
    long int val;
    struct node* next;
};

struct Stack{
    struct node* top;
};
typedef struct Restaurant Restaurant_s;
typedef struct meal meal_s;

void init_rest(Restaurant_s** res,const char *name,int distance,meal_s *meal_);
void init_all_rest(Restaurant_s** res,meal_s *meal_d,meal_s *meal_b,meal_s *meal_din);