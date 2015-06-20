#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"linklist.h"
#include"nodeitem.h"

pair creat_airline()
{
    pair p;
    if((p=(pair)malloc(sizeof(struct Airline)))==NULL)
    {
        printf("空间不足！！\n");
        exit(EXIT_FAILURE);
    }
    return p;
}
pcus creat_customer()
{
    pcus p;
    if((p=(pcus)malloc(sizeof(struct Customer)))==NULL)
    {
        printf("空间不足！！\n");
        exit(EXIT_FAILURE);
    }
    return p;
}
void insert_infor_air(pair p)
{
    printf("请输入起飞站：");
    scanf("%s",p->start);
    getchar();
    printf("请输入终点站：");
    scanf("%s",p->end);
    getchar();
    printf("请输入起飞时间：");
    scanf("%s",p->time);
    printf("请输入该航班总容量：");
    scanf("%d",&(p->total));
    getchar();
    printf("请输入折扣：");
    scanf("%f",&(p->discount));
    getchar();
    printf("请输入剩余票数：");
    scanf("%d",&(p->left));
    getchar();
    printf("请输入票价：");
    scanf("%d",&(p->price));
}
int is_inlist_airline(int num,plinklist_Airline pl)
{
    pair p;
    for(p=pl->head;p!=NULL;p=p->next)
    {
        if(num==p->airnum)
            return 1;
    }
    return 0;
}
void insert_customer(pcus p)
{
	printf("航班号：");
	scanf("%d",&(p->airnum));
	getchar();
	printf("起飞站：");
	scanf("%s",p->start);
	getchar();
	printf("终点站：");
	scanf("%s",p->end);
	getchar();
	printf("票价：");
	scanf("%d",&(p->price));
	getchar();
	printf("折扣：");
	scanf("%f",&(p->discount));
	getchar();
	printf("姓名：");
	scanf("%s",p->name);
	printf("身份证号：");
	scanf("%s",p->id);
	getchar();
	printf("票数：");
	scanf("%d",&(p->number));
	getchar();

}
void print_air(pair p)
{
    printf("航班号：%d\n起飞站：%s\n终点站：%s\n起飞时间：%s\n总容量：%d\n折扣：%f\n剩余票数：%d\n票价：%d\n",p->airnum,p->start,p->end,p->time,p->total,p->discount,p->left,p->price);
}
void import_air(plinklist_Airline pl)
{
    char code;
    printf("是否需要从文件中导入航班信息？Y/N");
    scanf("%c",&code);
    getchar();
    if(code=='Y'||code=='y')
    {
        char name[50];
        printf("请输入文件路径：");
        scanf("%s",name);
        getchar();
        FILE *fp;
        if((fp=fopen(name,"rb"))==NULL)
        {
            printf("该文件无法打开！！！\n");
            exit(EXIT_FAILURE);
        }
        while(!feof(fp))
        {
            pair p;
            if((p=creat_airline())!=NULL)
            {
                if(fscanf(fp,"%d%s%s%s%d%f%d%d",&(p->airnum),p->start,p->end,p->time,&(p->total),&(p->discount),&(p->left),&(p->price))==EOF)
                {
                    printf("读取失败！！！\n");
                    exit(EXIT_FAILURE);
                }
                p->next=pl->head;
                pl->head=p;
            }
        }
    }
}
void export_air(plinklist_Airline pl)
{
    pair p;
    FILE *fp;
    char name[50];
    printf("请输入文件存储路径：");
    scanf("%s",name);
    getchar();
    if((fp=fopen(name,"wb"))==NULL)
    {
       printf("无法打开该文件！！！\n");
       exit(EXIT_FAILURE);
    }
    for(p=pl->head;p!=NULL;p=p->next)
    {
        if((fprintf(fp,"%d%s%s%s%d%f%d%d",p->airnum,p->start,p->end,p->time,p->total,p->discount,p->left,p->price))==EOF)
            {
                printf("读取失败！！！\n");
                exit(EXIT_FAILURE);
            }

    }
}
