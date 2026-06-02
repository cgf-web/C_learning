/*例8.24 有两个整数a和b,由用户输入1,2或3。
如输入1,程序就给出a和b中大者，输人2,就给出a和b中小者，
输人3,则求a与b之和。*/

#include <stdio.h>
#include <stdlib.h>
int get_bigger(int a,int b)
{
        if(a>=b)
        return a;
        else
        return b; 
}

int get_litter(int a,int b)
{
        if(a>=b)
        return b;
        else
        return a; 
}

int sum(int a,int b)
{
        return a+b;
}

int dataHandler(int  a,int b,int (*func)(int a,int b))/*回调函数*/
{                                       //第三个参数传进来一个函数
        int ret;
        ret=(*func)(a,b);//函数调用    //也可以写成 ret=func(a,b);
        return ret;
}

int main()
{
        int a=10;
        int b=20;
        int ret;
        int cmd;
        printf("请输入1(取大者),2(取小者),3(求和))\n");
        scanf("%d",&cmd);
        int(*func)(int a,int b);//定义一个函数指针，该函数两个整形参数，返回值类型为int          int *p
        switch(cmd)
        {
                case 1:
                        func=get_bigger;            //指针指向具体函数         p=&a;
                        break;
                case 2:
                       func=&get_litter;   //函数名本身就是地址
                        break;
                case 3:
                        func=sum;
                        break;      
                default:
                        printf("输入错误! @请输入1(取大者),2(取小者),3(求和))\n");
                        exit(-1);
        }
        ret=dataHandler(a,b,func);//最终调用   func是某个处理函数的地址，
        printf("ret = %d\n",ret);
        return 0;
}




