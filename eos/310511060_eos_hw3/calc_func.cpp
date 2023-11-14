#pragma once
#include "calc_func.h"

void init_rest(Restaurant_s** res,const char *name,int distance,meal_s *meal_){
    *res = (Restaurant_s*)malloc(sizeof(Restaurant_s));
    //printf("1");
    (*res)->name = (char*)name;
    //printf("%s\n",(*res)->name);
    (*res)->distance = distance;
    (*res)->total = 0;
    (*res)->res_meal = meal_;
    meal_[0].num = 0;
    meal_[1].num = 0;
}
void init_all_rest(Restaurant_s** res,meal_s *meal_d,meal_s *meal_b,meal_s *meal_din){
    init_rest(&res[0],"Dessert shop",3, meal_d);
    init_rest(&res[1],"Beverage  shop",5, meal_b);
    init_rest(&res[2],"Diner ",8, meal_din);
}
