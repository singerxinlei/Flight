#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
#include "nodeitem.h"
int main()
{
    int chioce;
    linklist_Airline l1;
    linklist_customer l2;
    initializer_a(&l1);
    initializer_c(&l2);
    import_air(&l1);
    for(;;)
    {
       printf("¼�뺽����Ϣ������1:\n��ѯĳ�����ߵ����������2\n��Ʊ������3\n��Ʊ������4\n��ѯ�����м亽��������5\n�޸ĺ�����Ϣ������6\n�˳�������7\n");
        printf("��ѡ����Ŀ��");
        scanf("%d",&chioce);
        getchar();
        switch(chioce)
        {
            case 1:insert_flight(&l1);break;
            case 2:search_air(&l1);break;
            case 3:ordering(&l1,&l2);break;
            case 4:refund(&l1,&l2);break;
            case 5:search_flight(&l1);break;
            case 6:modify_air(&l1);break;
            case 7:export_air(&l1);return 0;
            default:printf("������󣡣���\n");break;
        }
    }

    return 0;
}
