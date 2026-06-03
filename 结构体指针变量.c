/*指针就是地址
指针变量就是存放地址的变量
结构体也是变量
变量访问有两种方式:1.变量名2地址

通过结构体变量地址来访问该结构体
需要一个变量来保持这个地址---->结构体指针变量*/


//任何变量都有四个东西:1.变量类型  2.变量名  3.变量的值    4.变量的地址
struct Test{
        int idata;
        char cdata;
};

#include  <stdio.h>
int main()
{
        int a=10;
        int *p=&a;
        char c= 'c';
        char *pc=&c;
        struct  Test t1={10,'c'};
        struct Test *pt1=&t1;

        printf("t1的idata是:%d\n",t1.idata);
        printf("t1的cdata是:%c\n",t1.cdata);//结构体变量访问，用.
        printf("t1的idata是:%d\n",pt1->idata);//结构体指针变量访问，用->
        printf("t1的cdata是:%c\n",pt1->cdata);    


        
           
        return 0;
}

