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
       printf("录入航班信息请输入1:\n查询某个航线的情况请输入2\n订票请输入3\n退票请输入4\n查询两城市间航班请输入5\n修改航班信息请输入6\n退出请输入7\n");
        printf("请选择项目：");
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
            default:printf("输入错误！！！\n");break;
        }
    }

    return 0;
}
