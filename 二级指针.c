#include  <stdio.h>

int main()
{
        int a=10;
        int *p=&a;
        printf("a的地址是:%p\n",&a);
        printf("p保存的是a的地址:%p,内容是:%d\n",p,*p);

       // int **pp=&p;
        //printf("p的地址是:%p\n",pp);

        int *p2=&p;
        printf("p2保存的是p的地址:%p\n",p2);
        printf("*p2是a的地址%p\n",*p2);
        printf("**p2可以访问到数据a:%d\n",* (*p2));
        
        return 0;
}