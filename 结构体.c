#include <stdio.h>

void Print(int a)
{
        printf("%d\n",a);
}

void Print1(int* p)
{
        printf("%d\n",*p);
}
struct Person
{
        int num;
        char name[10];
        int age;
        char sex[3];
};

void    PrintInfo(struct   Person p)
{
        printf("学号：%d,姓名：%s,年龄:%d,性别：%s\n",p.num,p.name,p.age,p.sex);
}

void PrintInfo1(struct Person *p)
{
        printf("学号：%d,姓名：%s,年龄:%d,性别：%s\n",p->num,p->name,p->age,p->sex);
}

int main()
{
        int a=10;
        int *p=&a;
        Print(a);
        Print1(&a);
        Print1(p);
        struct Person p1={1,"lili",25,"nv"};
        struct Person p2={2,"meimei",23,"nan"};
        struct Person * pp1=&p1;
        struct Person * pp2=&p2;

        PrintInfo(p1);
        PrintInfo(p2);
        PrintInfo1(pp1);
        PrintInfo1(pp2);
        PrintInfo1(&p1);
        PrintInfo1(&p2);        
        return 0;
}
