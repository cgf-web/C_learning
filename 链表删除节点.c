/*插入新节点 */
#include <stdio.h>
#include <stdlib.h>

struct Test
{
        int data;
        struct Test *next;
};


struct Test*  insertFromForward(struct Test *head,int data,struct Test *new)
{
        struct Test *p=head;
                if(p->data==data)//从原先链表的第一个节点前插
                {
                        new->next=p;               
                        return new;
                }
        while(p->next!=NULL)
        {
                if((p->next)->data==data)
                {
                        new->next=p->next;
                        p->next=new;
                        printf("insert ok\n");
                        return head;
                }
                p=p->next;
        }
        printf("no this data %d\n",data);
        return head;      
}


void  insertFromBehind(struct Test *head,int data,struct Test *new)
{
        struct Test *p=head;
        while(p!=NULL)
        {
                if(p->data==data)
                {
                        new->next=p->next;
                        p->next=new;                  
                }
                p=p->next;
        }
}

struct Tset *  deleteNode(struct Test* head,int data)
{
        struct Test * p=head;
        if(p->data==data)//要删除节点元素是第一个节点
        {
                head=head->next;
                //free(p);   一般是动态创建链表，删除后需要释放   静态不能free
                return head;
        }
        while(p->next!=NULL)
        {
                if(p->next->data==data)
                {
                        p->next=p->next->next;
                        printf("delete success\n");
                        return  head;
                }
                p=p->next;
        }
                printf("no that data:%d\n",data);
                return head;
}

void printlink(struct Test *head)
{
        struct Test *point=head;
        while(point!=NULL)
        {
                //if(point->next!=NULL)
                //{
                        printf("%d ",point->data);
                        point=point->next;
                //}
        }
        putchar('\n');
}
int getLinkTotalNodeNum(struct Test *head)
{
        int cnt=0;
        struct Test * point=head;
        while(point!=NULL)
        {
                cnt++;
                point=point->next;
        }
        return cnt;
}

int searchLinkData(struct Test *head,int data)
{
        struct Test * point=head;
        while(point!=NULL)
        {
                if(point->data==data)
                {
                       return 1; 
                }
                point=point->next;
        }
        return 0;
}


int main()
{
        int arr[10]={1,2,3,4,5,6,7,8,9,10};
        int length=sizeof(arr)/sizeof(arr[0]);
        for(int i=0;i<length;i++)
        {
                printf("%d ",arr[i]);
        }

        struct Test *head=NULL;
        struct Test t1={1,NULL};
        struct Test t2={2,NULL};
        struct Test t3={3,NULL};
        struct Test t4={4,NULL};
        struct Test t5={5,NULL};

        t1.next=&t2;
        t2.next=&t3;
        t3.next=&t4;
        t4.next=&t5;

        head=&t1;
        struct Test new={100,NULL};
        //printf("use t1 to print three nums\n");
        //printf("%d %d %d %d\n",t1.data,(t1.next)->data,(t1.next)->next->data,((t1.next)->next)->next->data);
        printlink(head);
        insertFromBehind(head,5,&new); 
        printlink(head);
        struct Test new1={101,NULL};
        head=insertFromForward(head,1,&new1);
        printf("从第一个节点前插入\n");
        printlink(head);  
        struct Test new2={102,NULL};
        head=insertFromForward(head,100,&new2);
        printf("插入后\n");
        printlink(head);     
        deleteNode(head,100);
       printlink(head);             
       /*printf("Link Node Num =%d\n",getLinkTotalNodeNum(&t1));
        int ret=searchLinkData(&t1,1);
        if(ret==0)
        printf("no 1\n");
        else
        printf("have 1\n");
        ret=searchLinkData(&t1,8);       
        if(ret==0)
        printf("no 8\n");
        else
        printf("have 8\n");   */  


        return 0;
}
