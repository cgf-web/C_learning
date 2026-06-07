#pragma once

typedef struct Student {
	unsigned long long number;
	char name[50];
	float chinese;
	float math;
	float english;
}Student;

/*链表节点*/
typedef struct Node {
	Student stu;
	struct Node* next;
}Node;


typedef struct List
{
	Node* front;//指向第一个节点
	int size;//当前节点数量
}List;


typedef enum MenuOptions {
	Quit,
	Entry,
	Print,
	Save,
	Read,
	Statistics,
	Find,
	Alter,
	Remove,
} MenuOptions;
int menu();


void entry(List* list);
void print(List* list);
void save(List* list);//二进制文件保存学生信息
void savehuman(List* list);//文本文件保存
void read(List* list);
void readhuman(List* list);
void statistics(List* list);
Node* find(List* list);
void alter(List* list);
void removestudent(List* list);
