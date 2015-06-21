#ifndef NODEITEM_H_INCLUDED
#define NODEITEM_H_INCLUDED
#include"linklist.h"
typedef struct Customer//�ͻ���Ϣ
{
    int airnum;//�����
    char start[20];//���վ
    char end[20];//�յ�վ
    int price;//Ʊ��
    float discount;//�ۿ�
    char name[20];//����
    char id[20];//���֤��
    int number;//Ʊ��
    struct Customer *next;
}Customer,*pcus;
typedef struct Airline//������Ϣ
{
    int airnum;//�����
    char start[20];//���վ
    char end[20];//�յ�վ
    char time[25];//���ʱ��
    int total ;//������,ָ����������ɳ˿͵�����
    float discount;//�ۿ�
    int left ;//ʣ��Ʊ��
    int price;//Ʊ��
    struct Airline *next;
}Airline,*pair;
pair creat_airline();
void insert_infor_air(pair p);
int is_inlist_airline(int num,plinklist_Airline pl);
void insert_customer(pcus p);
pcus creat_customer();
void print_air(pair p);

#endif // NODEITEM_H_INCLUDED
