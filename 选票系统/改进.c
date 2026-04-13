#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

//typedef struct XuanMin
//{
//    char name[32];
//    int tickets;
//}XuanMin;
//
//// 初始化候选人
//struct XuanMin* initXms(XuanMin* p, int* pn)
//{
//    int i;
//    if (p == NULL)
//    {
//        printf("请输入有几个人参选：\n");
//        scanf_s("%d", pn);
//        p = (XuanMin*)malloc(*pn * sizeof(struct XuanMin));
//    }
//    for (i = 0; i < *pn; i++)
//    {
//        p->tickets = 0;
//        printf("请输入第%d个候选人的名字:\n", i + 1);
//        scanf_s("%s", p->name, (unsigned)_countof(p->name));
//        p++;
//    }
//    return p - *pn;
//}
//
//// 打印所有候选人
//void printXms(XuanMin* p, int len)
//{
//    int i;
//    for (i = 0; i < len; i++)
//    {
//        printf("名字:%s,票数:%d\n", p->name, p->tickets);
//        p++;  // 移到下一个（原来放错位置了）
//    }
//}
//
//// 投票函数
//int doVot(XuanMin* p, int len)
//{
//    int i;
//    int feiPiao = 0;
//    int mark = 0;
//    char tmpName[32];
//    struct XuanMin* pbak = p;
//
//    printf("\n===== 开始投票 =====\n");
//    for (i = 0; i < len; i++)  // 一共投 len 次
//    {
//        mark = 0;
//        printf("第%d次投票，请输入名字：", i + 1);
//        memset(tmpName, '\0', sizeof(tmpName));
//        scanf_s("%s", tmpName, (unsigned)_countof(tmpName));
//
//        p = pbak;
//        int j;
//        for (j = 0; j < len; j++)
//        {
//            // 正确：名字相同才加票
//            if (strcmp(tmpName, p->name) == 0)
//            {
//                p->tickets++;
//                mark = 1;
//                break;  // 找到就跳出，不重复加票
//            }
//            p++;
//        }
//        // 判断是否废票（== 不是 =）
//        if (mark == 0)
//        {
//            printf("没有此候选人，废票！\n");
//            feiPiao++;
//        }
//    }
//    return feiPiao;
//}
//
//// 得票最高者
//struct XuanMin* getMax(struct XuanMin* p, int len)
//{
//    struct XuanMin* max = p;
//    int i;
//    for (i = 0; i < len; i++)
//    {
//        if (max->tickets < p->tickets)
//            max = p;
//        p++;
//    }
//    return max;
//}
//
//int main()
//{
//    XuanMin* xm = NULL;
//    XuanMin* max;
//    int total = 0;
//
//    xm = initXms(xm, &total);
//    printf("\n===== 候选人列表 =====\n");
//    printXms(xm, total);
//
//    int feip = doVot(xm, total);
//
//    printf("\n===== 投票结果 =====\n");
//    printf("废票数：%d\n", feip);
//    printXms(xm, total);
//
//    max = getMax(xm, total);
//    printf("\n%s 以 %d 票当选！废票：%d\n", max->name, max->tickets, feip);
//
//    free(xm);  // 释放内存
//    return 0;
//}


//共用体
//结构体元素有各自单独空间
//联合体元素共享空间，空间大小由最大类型确定

struct TestT
{
    int a;
    char c;
    double d;
};

union TestU
{
    int i;
    char c;
    double d;
};
int main()
{
    struct TestT t1;
    union TestU u1;
    printf("t1的大小是:%d\n", sizeof(t1));//16
    printf("u1的大小是:%d\n", sizeof(u1));//8
    t1.a = 10;
    t1.c = 'c';
    t1.d = 90.2;

    printf("a:%p,%d\n", &t1.a,t1.a);//000000E7BF6FF708
    printf("c:%p,%c\n", &t1.c,t1.c);//000000E7BF6FF70C
    printf("d:%p,%lf\n", &t1.d,t1.d);//000000E7BF6FF710

    u1.i = 10;
    u1.c = 'c';
    u1.d = 85.2;
    printf("i=%d\n", u1.i);
    printf("i:%p\n", &u1.i);
    printf("c:%p\n", &u1.c);
    printf("d:%p\n", &u1.d);//000000E9438FFC58联合体共用一个地址空间

}