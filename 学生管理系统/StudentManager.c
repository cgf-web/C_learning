#include "StudentManager.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

static Node* createNode()
{
	Node* node = (Node*)malloc(sizeof(Node));//每次进来录入一个学生信息，就申请一个节点的内存空间
	if (!node)
	{
		printf("malloc failed\n");
		return  NULL;
	}
	node->next = NULL;
	return node;
}

int menu()
{
	printf("********************************************\n");
	printf("*     欢迎使用高校学生成绩管理系统V1.0     *\n");
	printf("********************************************\n");
	printf("*               请选择功能                 *\n");
	printf("********************************************\n");
	printf("*			1, 录入学生信息				\n");
	printf("*			2, 打印学生信息				\n");
	printf("*			3，保存学生信息				\n");
	printf("*			4, 读取学生信息				\n");
	printf("*			5，统计学生人数				\n");
	printf("*			6, 查找学生信息				\n");
	printf("*			7，修改学生信息				\n");
	printf("*			8，删除学生信息				\n");
	printf("*			0, 退出系统					\n");
	printf("********************************************\n");
	printf("select:>");
	int select = -1;
	scanf("%d", &select);
	return select;
}

void entry(List* list)
{
	Node *node=createNode();
	printf("输入学生学号>");
	scanf("%llu", &node->stu.number);
	printf("输入学生姓名>");
	scanf("%s", node->stu.name);
	printf("输入学生语文成绩>");
	scanf("%f", &node->stu.chinese);
	printf("输入学生数学成绩>");
	scanf("%f", &node->stu.math);
	printf("输入学生英语成绩>");
	scanf("%f", &node->stu.english);

	node->next = list->front;
	list->front = node;
	list->size++;//插入节点
}

void print(List* list)
{
	printf("********************************************\n");
	printf("*     欢迎使用高校学生成绩管理系统V1.0     *\n");
	printf("********************************************\n");
	printf("*      学号 * 姓名 * 语文 * 数学 * 英语    *\n");
	printf("********************************************\n");

	Node* curNode = list->front;
	while (curNode!=NULL)
	{
		printf("  %llu * %s * %.1f * %.1f * %.1f\n", 
			curNode->stu.number, curNode->stu.name, 
			curNode->stu.chinese, curNode->stu.math, 
			curNode->stu.english);
			curNode = curNode->next;
	}
}

void save(List* list)
{
	FILE* fp = fopen("students.data", "wb");
	if (!fp)
	{
		perror("file open failed");
		return;
	}

	Node* curNode = list->front;
	while (curNode != NULL)
	{
		fwrite(&curNode->stu, sizeof(curNode->stu), 1, fp);
		//参数：&curNode->stu：要写入的数据的地址，写入数据的大小，写入数据的数量，文件指针
		curNode = curNode->next;
	}
	fclose(fp);
}

void savehuman(List* list)
{
	FILE* fp = fopen("students.txt", "w");
	if (!fp)
	{
		perror("file open failed");
		return;
	}

	Node* curNode = list->front;
	while (curNode != NULL)
	{
		/* 使用空格分隔，便于读取时用 %s/%f 匹配 */
		fprintf(fp, "%llu %s %.1f %.1f %.1f\n",
			curNode->stu.number,
			curNode->stu.name,
			curNode->stu.chinese,
			curNode->stu.math,
			curNode->stu.english);
		curNode = curNode->next;
	}
	fclose(fp);
}

void read(List* list)
{
	FILE* fp = fopen("students.data", "rb");
	if (!fp)
	{
		perror("file open failed");
		return ;
	}
	while (!feof(fp))
	{
		Node* node = createNode();
		if (!node)
		{
			break;
		}
		size_t len=fread(&node->stu, sizeof(Student), 1, fp);
		//参数：&node->stu：要读取数据的地址，读取数据的大小，读取数据的数量，文件指针
		if (len == 0)
		{
			free(node);
			break;
		}
		node->next = list->front;//每次读取一个学生信息，就把这个学生信息插入到链表的头部
		list->front = node;
		list->size++;
	}
	fclose(fp);
}

void readhuman(List* list)
{
	FILE* fp = fopen("students.txt", "r");
	if (!fp)
	{
		perror("file open failed");
		return;
	}

	char line[256];
	int readCount = 0;
	while (fgets(line, sizeof(line), fp))
	{
		/* 处理可能的 UTF-8 BOM */
		char* p = line;
		if ((unsigned char)p[0] == 0xEF && (unsigned char)p[1] == 0xBB && (unsigned char)p[2] == 0xBF)
		{
			p += 3;
		}

		Node* node = createNode();
		if (!node)
		{
			break;
		}

		/* 使用宽松的格式，%49s 防止溢出（name 长度为 50） */
		int matched = sscanf(p, "%llu %49s %f %f %f",
			&node->stu.number,
			node->stu.name,
			&node->stu.chinese,
			&node->stu.math,
			&node->stu.english);

		if (matched != 5)
		{
			/* 如果行格式错误，释放节点并跳过 */
			free(node);
			continue;
		}

		node->next = list->front;
		list->front = node;
		list->size++;
		readCount++;
	}

	fclose(fp);
	printf("已从 students.txt 读取 %d 条记录。\n", readCount);
}

void statistics(List* list)
{
	//printf("学生总人数为:%d\n", list->size);
	int count=0;
	Node* curNode = list->front;
	while (curNode != NULL)
	{
		count++;
		curNode = curNode->next;
	}
	printf("学生总人数为:%d\n", count);
}

Node* find(List* list)
{
	if (list->size == 0)
	{
		return NULL;
	}
	char buf[32];
	printf("请输入要查找学生学号或姓名\n");
	scanf("%s", buf);

	//把buf转成整形
	unsigned long long number = 0;
	sscanf(buf, "%llu", &number);

	Node* curNode = list->front;
	while (curNode != NULL)
	{
		if (strcmp(curNode->stu.name, buf) == 0 ||
			curNode->stu.number==number)
		{
			return curNode;
		}
		curNode = curNode->next;
	}

	return NULL;
}

void alter(List* list)
{
	if (list->size == 0)
	{
		printf("暂无学生\n");
		return;
	}
	char buf[32];
	printf("请输入要修改学生学号或姓名\n");
	scanf("%s", buf);

	//把buf转成整形
	unsigned long long number = 0;
	sscanf(buf, "%llu", &number);

	Node* curNode = list->front;
	while (curNode != NULL)
	{
		if (strcmp(curNode->stu.name, buf) == 0 ||
			curNode->stu.number == number)
		{
			printf("请输入要修改的学生的成绩（语文，数学，英语）\n");
			scanf("%f %f %f", &curNode->stu.chinese, &curNode->stu.math, &curNode->stu.english);
			printf("修改成功QAQ\n");
			break;
		}
		curNode = curNode->next;
	}
	if (curNode == NULL)
	{
		printf("未找到该学生~~\n");
	}
}


void removestudent(List* list)
{
	if (list->size == 0)
	{
		printf("暂无学生\n");
		return;
	}
	char buf[32];
	printf("请输入要删除学生学号或姓名\n");
	scanf("%s", buf);

	//把buf转成整形
	unsigned long long number = -1;
	sscanf(buf, "%llu", &number);

	Node* curNode = list->front;
	Node* prevNode = NULL;

	while (curNode != NULL)
	{
		if (strcmp(curNode->stu.name, buf) == 0 ||
			curNode->stu.number == number)
		{
			break;
		}
		prevNode = curNode;
		curNode = curNode->next;
	}
	if (curNode)//
	{
		//要删除的就是第一个节点
		if (prevNode == NULL)//只有要删除的是第一个节点时，prevNode=curNode这个语句不会执行
		{
			list->front = curNode->next;//第二个节点的地址赋值给list->front，删除第一个节点
		}
		else//这种情况，curNode不是第一个节点，prevNode指向curNode的前一个节点
//要删除的节点是中间节点或者最后一个节点时，prevNode->next指向curNode->next，删除curNode
		{
			prevNode->next = curNode->next;
		}
		list->size--;
		free(curNode);
		printf("删除成功\n");
	}
	//if (strcmp(curNode->stu.name, buf) == 0 ||
	//	curNode->stu.number == number)
	//{
	//	list->front = curNode->next;//第二个节点的地址赋值给list->front，删除第一个节点
	//	free(curNode);
	//}
	//while (curNode->next != NULL)
	//{
	//	if (strcmp(curNode->stu.name, buf) == 0 ||
	//		curNode->stu.number == number)

	//	curNode = curNode->next;
	//}
}
