#define _CRT_SECURE_NO_WARNINGS 1
#include"correspond.h"

void menu()
{
	printf("****** 1.添加联系人     2.删除联系人\n");
	printf("****** 3.搜索联系人     4.修改联系人\n");
	printf("****** 5.展示联系人     6.排序 *****\n");
	printf("****** 0.退出                  *****\n");
}
int main()
{
	menu();
	int input=0;
	struct  contact con;
	Initcontact(&con);
	do
	{
		printf("请输入选择的功能\n");
		scanf("%d", &input);
		switch (input)
		{
		case exit:
			break;
		case add:
			addcontact(&con);
			break;
		case delete:
			deletecontact(&con);
			break;
		case search:
			searchcontact(&con);
			break;
		case modify:
			modifycontact(&con);
			break;
		case show:
			showcontact(&con);
			break;
		case sort:
			sortcontact(&con);
			break;
		}
	} while (input);
	
	
	return 0;
}