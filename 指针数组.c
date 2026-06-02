/*数组指针        int (*p)[4]         p是个数组指针，指向一个有4个int类型元素的数组

    指针数组：是一个数组，该数组里的元素类型是指针   int *p[4]      一个数组，里面有四个int* 的数据
*/

//指针数组练习

#include <stdio.h>
int main()
{
        int a=10,b=20,c=30,d=40;
        int * arr[4]={&a,&b ,&c,&d};
        for(int i=0;i<4;i++)
        {       
                printf("%d ",*(arr[i]));
        }
        return 0;
}

