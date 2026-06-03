/*一个函数，返回值是一个地址（指针类型的数据）  int * a(int x,int y);*/

/*例8.25 有a个学生，每个学生有b门课程的成绩。
要求在用户输人学生序号以后，能输出该学生的全部成绩。用指针函数来实现。*/
#include <stdio.h>

int* getposperson(int pos,int pstu[][4])//int  (*pstu)[4]
{
        int *p;
        p=(int *)(pstu+pos);
        return p;
}

int main()
{
        int scores[3][4]={{55,66,77,88},{66,55,99,100},{11,22,33,59}};
        int pos;
        int *ppos;
        printf("请输入查看学生的学号:0,1,2\n");
        scanf("%d",&pos);
        
        ppos= getposperson(pos,scores);
        for(int i=0;i<4;i++)
        {
                //printf("%d ",*(ppos+i));
                printf("%d ",ppos[i]);
        }
        return 0;
}