#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include"nodeitem.h"
typedef struct
{
    struct Airline *head;

}linklist_Airline,*plinklist_Airline;

typedef struct
{
    struct Customer *head;

}linklist_customer,*plinklist_customer;

int is_inlist_airline(int num,plinklist_Airline pl);
void initializer_c(plinklist_customer pl);
void initializer_a(plinklist_Airline pl);
void insert_flight(plinklist_Airline pl);
void search_air(plinklist_Airline pl);
void search_flight(plinklist_Airline pl);
void find_airline(plinklist_Airline pl,char *from,char *to);
void ordering(plinklist_Airline pl1,plinklist_customer pl2);
void find_ralevent_airlane(plinklist_Airline pl,char *from,char *to);
void modify_air(plinklist_Airline pl);
void refund(plinklist_Airline pl1,plinklist_customer pl2);
void delete_cus(pcus p,pcus q,plinklist_customer pl);
void import_air(plinklist_Airline pl);
void export_air(plinklist_Airline pl);
#endif // LINKLIST_H_INCLUDED
