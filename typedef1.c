#include <stdio.h>

void Print(int a)
{
        printf("%d\n",a);
}

void Print1(int* p)
{
        printf("%d\n",*p);
}
typedef struct Person
{
        int num;
        char name[10];
        int age;
        char sex[3];
}person,*pPerson;//给它起别名 *pPerson → 代表指向这个结构体的指针

//typedef struct Person person;//typedef重起名字，最好写在文件最顶部（最安全）

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
        person p1={1,"lili",25,"nv"};
        person p2={2,"meimei",23,"nan"};
        person * pp1=&p1;
        person * pp2=&p2;
        pPerson pp3=&p1;
        pPerson pp4=&p2;       
        PrintInfo(p1);
        PrintInfo(p2);
        PrintInfo1(pp1);
        PrintInfo1(pp2);
        PrintInfo1(&p1);
        PrintInfo1(&p2);
        PrintInfo1(pp3);
        PrintInfo1(pp4);                
        return 0;
}

/*                                                                typedef后 typedef  struct Person       person,*pPerson
int            →   struct Person                           →            person
int*         →   struct Person*                          →            person*
int a        →   struct Person p                        →           person  p
int *p      →   struct Person *p                      →           person *p
int *p                                                                     →          pPerson   p


*/