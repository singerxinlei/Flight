#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"
#include "nodeitem.h"
void initializer_c(plinklist_customer pl)
{
    pl->head=NULL;
}
void initializer_a(plinklist_Airline pl)
{
    pl->head=NULL;
}
void insert_flight(plinklist_Airline pl)
{
    pair p;
    if((p=creat_airline())!=NULL)
    {
        printf("�����뺽��ţ�");
        scanf("%d",&(p->airnum));
        getchar();
        if(is_inlist_airline(p->airnum,pl)==1)
        {
            printf("�ñ���Ѵ���\n");
            free(p);
            return;
        }
        insert_infor_air(p);
        p->next=pl->head;
        pl->head=p;

    }
}
void search_air(plinklist_Airline pl)
{
    int num;
    pair p;
    printf("�����뺽��ţ�");
    scanf("%d",&num);
    getchar();
    if(is_inlist_airline(num,pl))
    {
        for(p=pl->head;p!=NULL;p=p->next)
        {
            if (num==p->airnum) {
                print_air(p);
                return;
            }
        }
    }
    else
    {
        printf("�ú���Ų����ڣ�����\n");
        return;
    }
}
void search_flight(plinklist_Airline pl)
{
    char from[20];
    char to[20];
    printf("���������վ��");
    scanf("%s",from);
    getchar();
    printf("�������յ�վ��");
    scanf("%s",to);
    find_airline(pl,from,to);
}
void find_airline(plinklist_Airline pl,char *from,char *to)
{
    int i=0;
    pair p;
    for(p=pl->head;p!=NULL;p=p->next)
    {
        if(!strcmp(from,p->start)&&!strcmp(to,p->end))
            {
                print_air(p);
                i++;
            }
    }
    if(i==0)
    {
        printf("û�з��������ĺ��࣡��\n");
        return;
    }
}
void ordering(plinklist_Airline pl1,plinklist_customer pl2)
{
    char*from;
	char*to;
	from=(char *)malloc(sizeof(char)*20);
	to=(char *)malloc(sizeof(char)*20);
    char time[25];
    char code;
    pair p;
    int i=0;
    printf("�����أ�");
    scanf("%s",from);
    getchar();
    printf("�յ�վ��");
    scanf("%s",to);
    getchar();
    printf("ʱ�䣺");
	scanf("%s",time);
	getchar();
    for(p=pl1->head;p!=NULL;p=p->next)
    {
        if(!strcmp(from,p->start)&&!strcmp(to,p->end)&&!strcmp(p->time,time))
            {
                print_air(p);
                i++;
            }
    }
    if(i==0)
    {
        printf("û�з��������ĺ��࣡��\n");
        printf("Ϊ���ṩ��غ��ࣺ");
        find_ralevent_airlane(pl1,from,to);
    }
    printf("�Ƿ�Ԥ����ƱY/N��");
    scanf("%c",&code);
    getchar();
	if(code=='Y'||code=='y')
	{
		int num;
		pair p;
		printf("��������ҪԤ���ĺ���ĺ���ţ�");
		scanf("%d",&num);
		getchar();
		for(p=pl1->head;p!=NULL&&p->airnum!=num;p=p->next)
			;
		p->left=p->left-1;
		printf("����������������Ϣ����ɶ�Ʊ��");
		pcus temp;
		temp=creat_customer();
		if(temp!=NULL)
        {
           insert_customer(temp);
           temp->next=pl2->head;
           pl2->head=temp;
        }
    }
}
void find_ralevent_airlane(plinklist_Airline pl,char*from,char*to)
{
    pair p,q;
    printf("zhi da hang ban");
    for(p=pl->head;p!=NULL&&!strcmp(p->start,from)&&!strcmp(q->end,to);p=p->next)
    {
        print_air(p);
        
    }
    printf("zhuan ji hang ban");
    for(p=pl->head;p!=NULL&&!strcmp(p->start,from);p=p->next)
    {
        for(q=pl->head;q!=NULL&&!strcmp(q->end,to);q=q->next)
            if(!strcmp(p->end,q->start)&&q->time>p->time)
            {
                print_air(p);
                print_air(q);
            }
    }
}
void modify_air(plinklist_Airline pl)
{
    int number;
    printf("��������Ҫ�޸ĵĺ���ĺ���ţ�");
    scanf("%d",&number);
    if(is_inlist_airline(number,pl))
    {
        pair p;
        for(p=pl->head;p!=NULL&&p->airnum!=number;p=p->next)
            ;
        printf("����������Ϣ��\n");
		printf("����ţ�");
        scanf("%d",&(p->airnum));
		getchar();
        insert_infor_air(p);
    }else{
        printf("zi ji tian jia~~~~~          ");
    }

}
void refund(plinklist_customer pl2)
{
    char id[20];
    pcus p,q;
    printf("�������������֤���룺");
    scanf("%s",id);
    getchar();
    for(p=NULL,q=pl2->head;q!=NULL&&strcmp(id,q->id)!=0;p=q,q=q->next)
        ;
    if(q==NULL)
    {
        printf("�ÿͻ������ڣ���\n");
        return;
    }
    int num;
    printf("�����뺽��ţ�");
    scanf("%d",&num);
    if(num==q->airnum)
    {
        int number;
        printf("��������Ʊ������");
        scanf("%d",&number);
        if(number<=q->number)
        {
            printf("��Ʊ�ɹ���\n");
            q->number-=number;
            if(q->number==0)
                {
                    delete_cus(p,q,pl2);
                    return;
                }
        }
        else
        {
            printf("��Ʊ��������������Ʊ�������޷������Ʊ������\n");
            return;
        }
    }
    else
    {
        printf("�����������󣡣�\n");
        return;
    }
}
void delete_cus(pcus p,pcus q,plinklist_customer pl)
{
    if(p==NULL)
    {
        pl->head=q->next;
        free(q);
        free(p);
    }
    else
    {
        p->next=q->next;
        free(q);
    }
}
