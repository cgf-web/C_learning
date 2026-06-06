#include <stdio.h>

typedef struct spy{
        char* name;
        struct spy *next;
}spy, *p_spy;

        spy A={"A",NULL};
        spy B={"B",NULL};
        spy C={"C",NULL};
        p_spy head=NULL;
void  insert_spy(p_spy newspy)
{
        if(head==NULL)
        {
                head=newspy;
                newspy->next=NULL;
        }
        else
        {
                /*先找到链表的最后一项*/
                /*last->next=newspy;*/
                p_spy last=head;
                while(last->next!=NULL)
                {
                        last=last->next;
                }
                last->next=newspy;
                newspy->next=NULL;
        }
}

void remove_spy(p_spy oldspy)
{
        p_spy  left;
        if(head==oldspy)
        {
                head=oldspy;
        }
        else{
                left=head;
                while(left)
                {
                        if(left->next==oldspy)
                        {
                                       left->next=oldspy->next;
                        }
                        left=left->next;
                }
        }
}

void print_spy(void)
{
        p_spy temp=head;
        while(temp)
        {
                printf("%s\n",temp->name);
                temp=temp->next;
        }
}

int main()
{

        head=&A;

       /* A.next=&B;
        B.next=&C;
        C.next=NULL;*/
        insert_spy(&A);
        insert_spy(&B);
        insert_spy(&C);

        print_spy();
        remove_spy(&B);
        printf("remove spy B\n");
        print_spy();
        
        

        return 0;
}