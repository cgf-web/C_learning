#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "StudentManager.h"



int main(int argc,char* argv[])
{
	List list = {0};
	memset(&list, 0, sizeof(List));

	bool isRunning = true;
	while (isRunning)
	{
		MenuOptions m = menu(); // 修复：初始化m，调用menu函数获取用户选择
		switch (m)
		{
			case Quit:
				isRunning = false;
			break;
			case Entry:
				entry(&list);
			break;	
			case Print:
				print(&list);
			break;
			case Save:
				//save(&list);
				savehuman(&list);
			break;	
			case Read:
				//read(&list);
				readhuman(&list);
			break;
			case Statistics:
				statistics(&list);
			break;		
			case Find:
				{
					Node* node = find(&list);
					if (!node)
					{
						printf("no that student\n");
					}
					else
					{
						printf("%llu\t\t%s\t\t%.1f\t\t%.1f\t\t%.1f",
							node->stu.number, node->stu.name, node->stu.chinese,
							node->stu.math, node->stu.english);
					}
				}
			break;
			case Alter:
				alter(&list);
			break;
			case Remove:
				removestudent(&list);
			break;	
		}
	
		if (isRunning)
		{
			system("pause");
			system("cls");
		}
		
	}	
	save(&list);
	savehuman(&list);
	return 0;
}