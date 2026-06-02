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

int main()
{
        int a=10;
        int b=20;
        int ret;                                     //三个元素  每个元素类型都是函数指针
        int (*func[3])(int a,int b)={get_bigger,get_litter,sum};   //定义一个函数指针数组   ,并且初始化  
        //从内向外看  func先和[]结合是个数组    然后前面有*表明是指针  再外面 是函数
        //读得时候从外向内读
        for(int i=0;i<3;i++)
        {
                ret=(*func[i])(a,b);
                printf("%d ",ret);
        }
        return 0;
}




