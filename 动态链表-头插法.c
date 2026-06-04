/*
动态链表头插法：新节点永远插在最前面，作为新的头节点
输入数字插入，输入 0 退出并结束创建
*/

#include <stdio.h>
#include <stdlib.h>  // malloc 函数需要这个头文件

// 定义链表节点结构体
struct Test
{
    int data;               // 节点的数据域：存放数字
    struct Test *next;      // 节点的指针域：指向下一个节点的地址
};

// 功能：头插法插入新节点，参数是旧头节点，返回值是新头节点
struct Test* insertFromhead(struct Test* head)
{
    struct Test* new;  // 定义一个指针，用来指向新创建的节点

    // 循环不停创建节点，直到输入 0 退出
    while(1)
    {
        // 1. 申请一块内存，用来存放新节点
        new = (struct Test*)malloc(sizeof(struct Test));

        // 2. 输入节点的数据
        printf("input your new node data:");
        scanf("%d", &new->data);  // 把输入的值放到新节点的 data 里

        // 3. 如果输入 0，就退出创建，返回当前链表
        if(new->data == 0)
        {
            printf("0 quit\n");
            return head;  // 返回现在的头节点
        }

        // 4. 如果链表是空的（第一个节点）
        if(head == NULL)
        {
            head = new;  // 新节点直接作为头节点
        }
        // 5. 链表不为空，执行头插法（核心逻辑）
        else
        {
            new->next = head;  // 新节点指向原来的头节点
            head = new;        // 新节点变成新的头节点
        }
    }

    return head;  // 返回最终的头节点
}

// 功能：遍历链表，打印所有节点的数据
void printlink(struct Test *head)
{
    // 定义一个遍历指针，从头节点开始走
    struct Test *point = head;

    // 只要指针不为空，就一直往后走
    while(point != NULL)
    {
        printf("%d ", point->data);  // 打印当前节点的数据
        point = point->next;         // 指针移动到下一个节点
    }

    putchar('\n');  // 换行
}

int main()
{
    struct Test *head = NULL;  // 一开始链表为空，头指针为 NULL

    // 调用头插法函数，创建链表
    head = insertFromhead(head);

    // 打印整个链表
    printlink(head);

    return 0;
}