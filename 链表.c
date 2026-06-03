/*链表是一种数据结构，数据存放的思想*/

//数组：相同类型元素的集合，每个元素地址连续
//缺点：增，删数据不方便（不灵活），数组容量固定
//结构体：不同类型元素（数据）的集合，每个元素地址也连续

//链表    优点：极其灵活   增删只改变局部就行

#include <stdio.h>

struct Test
{
        int data;
        struct Test *next;
};

int main()
{
        int arr[10]={1,2,3,4,5,6,7,8,9,10};
        int length=sizeof(arr)/sizeof(arr[0]);
        for(int i=0;i<length;i++)
        {
                printf("%d ",arr[i]);
        }

        struct Test t1={1,NULL};
        struct Test t2={2,NULL};
        struct Test t3={3,NULL};

        t1.next=&t2;
        t2.next=&t3;

        printf("use t1 to print three nums\n");
        printf("%d %d %d\n",t1.data,(t1.next)->data,(t1.next)->next->data);

        return 0;
}
