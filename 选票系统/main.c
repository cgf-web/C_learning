#include <stdio.h>
#include <stdlib.h>

//struct Test
//{
//	int idata; 
//	char cdata;
//};
//
//int main()
//{
//	int a=10;
//	int* p = &a;
//
//	char c='c';
//	char* pc = &c;
//	
//	struct Test t1 = { 10,'c'};//任何变量都有四个东西，1.类型 2.名字 3.地址 4.值
//	struct Test* pt1 = &t1;
//
//	printf("t1的idata=%d\n", t1.idata);//结构体变量名.成员名(直接访问)
//	printf("t1的idata=%d\n", pt1->idata);//结构体指针变量名->成员名（间接访问）	
//	pt1->cdata = 'R';
//	printf("t1的cdata=%c\n", t1.cdata);
//	printf("t1的cdata=%c\n", pt1->cdata);
//}

//typedef struct Student
//{
//	int num;
//	char name[32];
//	char sex;
//	int age;
//	double score;
//	char addr[32];
//}Student;
//
//int main()
//{
//	int arr[3] = { 1,2,3 };
//	int i;
//	int len;
//	Student arr2[3] = {
//		2,"张三", '男', 20, 90.5, "北京市",
//		3,"李四", '女', 19, 88.5, "上海市",
//		4,"王五", '男', 21, 92.5, "广州市"
//	};
//	Student* p;
//	p = arr2;
//	len = sizeof(arr2) / sizeof(arr2[0]);
//	for (i = 0; i < len; i++)
//	{
//		printf("学号:%d,年龄：%d,分数:%lf,名字:%s,地址:%s\n", arr2[i].num, arr2[i].age,
//			arr2[i].score, arr2[i].name, arr2[i].addr);
//	}
//	p = arr2;
//	for (i = 0; i < len; i++)
//	{
//		printf("学号:%d,年龄：%d,分数:%lf,名字:%s,地址:%s\n", p->num, p->age,
//			p->score, p->name, p->addr);
//		p++;
//	}
//	return 0;
//}



typedef struct XuanMin
{
	char name[32];
	int tickets;
}XuanMin;
int main1()
{
	XuanMin xm[3];
	XuanMin max;
	XuanMin* p = xm;

	int feiPiao = 0;
	int i;
	int len;
	int j;
	int mark = 0;

	int total = 5;
	char tmpName[32];

	//初始化选民信息
	len = sizeof(xm) / sizeof(xm[0]);
	for (i = 0; i < len; i++)
	{
		p->tickets = 0;
		printf("请输入第%d个选民的名字:\n", i + 1);
		scanf_s("%s", xm[i].name);
		getchar();
		p++;
	}

	//唱票环节
	for (i = 0; i < total; i++)
	{
		mark = 0;
		printf("请输入你投给谁:\n");
		memset(tmpName, '\0', sizeof(tmpName));
		scanf_s("%s", tmpName);
		p = xm;
		for (j = 0; j < len; j++)
		{
			if (strcmp(tmpName, p->name))
			{
				xm[j].tickets++;
				mark = 1;
			}
			p++;
		}
		if (mark = 0)
		{
			printf("没有此候选人,放弃\n");
			feiPiao++;
		}
	}

	//公布结果
	p = xm;
	for (i = 0; i < len; i++)
	{
		printf("名字:%s，票数:%d\n", p->name, p->tickets);
		p++;
	}
	max = xm[0];
	for (i = 0; i < len; i++)
	{
		if (max.tickets < p->tickets)
		{
			max = xm[i];
		}
		p++;
	}
	printf("%s以%d票当选！！,废票是%d\n", max.name, max.tickets,feiPiao);
}
//注意：指针++，每次遍历会到数组尾巴，下次遍历就越界了，所以每次遍历前都要把指针重新指向数组首地址。

