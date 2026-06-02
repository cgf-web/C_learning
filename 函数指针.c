/*如果在程序中定义了一个函数，在编译时，编译系统为函数代码分配一段存储空间，
这段存储空间的起始地址(又称入口地址)称为这个函数的指针。函数名就是地址
int a;
int *p;
int  getData(int a,int b);
int (*p)(int a,int b);函数指针  p=getData(int a,int b)
int* p(int a,int b);指针函数   p是带有两个参数的函数，返回值是一个int*类型的指针
上面两个  是因为加了括号(优先级)
*/
#include <stdio.h>

int incData(int data)
{
        return ++data;
}

void  printWelcome()
{
        puts("程序启动，欢迎登陆\n");
}

int main()
{
        void (*p)();//定义一个函数指针变量            int *p;
        p=printWelcome;//指向函数                      p=&a;
        printWelcome();       
        int (*p1)(int data);
        p1=incData;
        (*p)();//函数调用
        printf("%d\n",(*p1)(3));
        return 0;
}