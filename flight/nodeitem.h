#ifndef NODEITEM_H_INCLUDED
#define NODEITEM_H_INCLUDED
#include"linklist.h"
typedef struct Customer//客户信息
{
    int airnum;//航班号
    char start[20];//起飞站
    char end[20];//终点站
    int price;//票价
    float discount;//折扣
    char name[20];//姓名
    char id[20];//身份证号
    int number;//票数
    struct Customer *next;
}Customer,*pcus;
typedef struct Airline//航班信息
{
    int airnum;//航班号
    char start[20];//起飞站
    char end[20];//终点站
    char time[25];//起飞时间
    int total ;//总容量,指的是最多容纳乘客的数量
    float discount;//折扣
    int left ;//剩余票数
    int price;//票价
    struct Airline *next;
}Airline,*pair;
pair creat_airline();
void insert_infor_air(pair p);
int is_inlist_airline(int num,plinklist_Airline pl);
void insert_customer(pcus p);
pcus creat_customer();
void print_air(pair p);

#endif // NODEITEM_H_INCLUDED
