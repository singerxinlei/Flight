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
        printf("�ռ䲻�㣡��\n");
        exit(EXIT_FAILURE);
    }
    return p;
}
pcus creat_customer()
{
    pcus p;
    if((p=(pcus)malloc(sizeof(struct Customer)))==NULL)
    {
        printf("�ռ䲻�㣡��\n");
        exit(EXIT_FAILURE);
    }
    return p;
}
void insert_infor_air(pair p)
{
    printf("���������վ��");
    scanf("%s",p->start);
    getchar();
    printf("�������յ�վ��");
    scanf("%s",p->end);
    getchar();
    printf("���������ʱ�䣺");
    scanf("%s",p->time);
    printf("������ú�����������");
    scanf("%d",&(p->total));
    getchar();
    printf("�������ۿۣ�");
    scanf("%f",&(p->discount));
    getchar();
    printf("������ʣ��Ʊ����");
    scanf("%d",&(p->left));
    getchar();
    printf("������Ʊ�ۣ�");
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
	printf("����ţ�");
	scanf("%d",&(p->airnum));
	getchar();
	printf("���վ��");
	scanf("%s",p->start);
	getchar();
	printf("�յ�վ��");
	scanf("%s",p->end);
	getchar();
	printf("Ʊ�ۣ�");
	scanf("%d",&(p->price));
	getchar();
	printf("�ۿۣ�");
	scanf("%f",&(p->discount));
	getchar();
	printf("������");
	scanf("%s",p->name);
	printf("���֤�ţ�");
	scanf("%s",p->id);
	getchar();
	printf("Ʊ����");
	scanf("%d",&(p->number));
	getchar();

}
void print_air(pair p)
{
    printf("����ţ�%d\n���վ��%s\n�յ�վ��%s\n���ʱ�䣺%s\n��������%d\n�ۿۣ�%f\nʣ��Ʊ����%d\nƱ�ۣ�%d\n",p->airnum,p->start,p->end,p->time,p->total,p->discount,p->left,p->price);
}
void import_air(plinklist_Airline pl)
{
    char code;
    printf("�Ƿ���Ҫ���ļ��е��뺽����Ϣ��Y/N");
    scanf("%c",&code);
    getchar();
    if(code=='Y'||code=='y')
    {
        char name[50];
        printf("�������ļ�·����");
        scanf("%s",name);
        getchar();
        FILE *fp;
        if((fp=fopen(name,"rb"))==NULL)
        {
            printf("���ļ��޷��򿪣�����\n");
            exit(EXIT_FAILURE);
        }
        while(!feof(fp))
        {
            pair p;
            if((p=creat_airline())!=NULL)
            {
                if(fscanf(fp,"%d%s%s%s%d%f%d%d",&(p->airnum),p->start,p->end,p->time,&(p->total),&(p->discount),&(p->left),&(p->price))==EOF)
                {
                    printf("��ȡʧ�ܣ�����\n");
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
    printf("�������ļ��洢·����");
    scanf("%s",name);
    getchar();
    if((fp=fopen(name,"wb"))==NULL)
    {
       printf("�޷��򿪸��ļ�������\n");
       exit(EXIT_FAILURE);
    }
    for(p=pl->head;p!=NULL;p=p->next)
    {
        if((fprintf(fp,"%d%s%s%s%d%f%d%d",p->airnum,p->start,p->end,p->time,p->total,p->discount,p->left,p->price))==EOF)
            {
                printf("��ȡʧ�ܣ�����\n");
                exit(EXIT_FAILURE);
            }

    }
}
