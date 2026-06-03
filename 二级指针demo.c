/*一个函数，返回值是一个地址（指针类型的数据）  int * a(int x,int y);*/

/*例8.25 有a个学生，每个学生有b门课程的成绩。
要求在用户输人学生序号以后，能输出该学生的全部成绩。用指针函数来实现。*/
#include <stdio.h>

void  getposperson(int pos,int pstu[][4],int **ppos)//形参的改变不会影响实参
{
        *ppos=(int *)(pstu+pos);
}

void func(int a)//形参是实参的临时拷贝，改变形参不会改变实参
{
        a++;
}

void func1(int *p)
{
        (*p)++;//得加括号，++优先级比*高   通过传a的地址，p接收，来改变a的值
}
int main()
{
        int scores[3][4]={{55,66,77,88},{66,55,99,100},{11,22,33,59}};
        int pos;
        int *ppos;
        printf("请输入查看学生的学号:0,1,2\n");
        scanf("%d",&pos);
        
       /* getposperson(pos,scores,ppos);//此处的ppos是野指针，在上面函数中只是局部赋给ppos地址，main中的ppos没有改变
        for(int i=0;i<4;i++)
        {
                //printf("%d ",*(ppos+i));
                printf("%d ",ppos[i]);//形参传过去的只是一个野地址，
        }*/
        /*getposperson(pos,scores,&ppos);
        for(int i=0;i<4;i++)
        {
                //printf("%d ",*(ppos+i));
                printf("%d ",ppos[i]);
        }*/

        int a=10;
        func(a);
        printf("a=%d\n",a);
        func1(&a);
        printf("a=%d\n",a);
        return 0;
}