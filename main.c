#define _CRT_SECURE_NO_WARNINGS 1
#include"correspond.h"

void menu()
{
	printf("****** 1.�����ϵ��     2.ɾ����ϵ��\n");
	printf("****** 3.������ϵ��     4.�޸���ϵ��\n");
	printf("****** 5.չʾ��ϵ��     6.���� *****\n");
	printf("****** 0.�˳�                  *****\n");
}
int main()
{
	menu();
	int input=0;
	struct  contact con;
	Initcontact(&con);
	do
	{
		printf("������ѡ��Ĺ���\n");
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