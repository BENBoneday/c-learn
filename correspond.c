#define _CRT_SECURE_NO_WARNINGS 1
#include"correspond.h"

static int FindName(const struct contact* con, char name[Max_name])
{
	int i = 0;
	for (i = 0; i < con->size; i++)
	{
		if (0 == strcmp(con->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
	
}

void Initcontact(struct contact* con)
{
	memset(con->data,0,sizeof(con->data));
	con->size = 0;
}
void addcontact(struct contact* con)
{
	if (con->size == Max_size)
	{
		printf("通讯录已满\n");
	}
	else
	{
		printf("请输入姓名：\n");
		scanf("%s", con->data[con->size].name);
		printf("请输入年龄：\n");
		scanf("%d", &con->data[con->size].age);
		printf("请输入性别：\n");
		scanf("%s", con->data[con->size].sex);
		printf("请输入电话：\n");
		scanf("%s", con->data[con->size].tel);
		printf("请输入地址：\n");
		scanf("%s", con->data[con->size].addr);
		printf("添加成功！\n");
		con->size++;
	}

}
void showcontact(const struct contact* con)
{
	if (con->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
	}
	
	int i = 0;
	for (i = 0; i < con->size; i++)
	{
		printf("%-10s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			con->data[i].name,
			con->data[i].age,
			con->data[i].sex,
			con->data[i].tel,
			con->data[i].addr	 );
	}
}
void deletecontact(struct contact* con)
{
	char name[Max_name];
	printf("请输入要删除的姓名\n");
	scanf("%s", name);
	int i = 0;
	int ret = FindName(con, name);
	if (ret==-1)
	{
		printf("没有找到要删除的名字\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < con->size-1; j++)
		{
			con->data[j] = con->data[j + 1];
		}
		con->size--;
		printf("删除成功！\n");
	}
}
void searchcontact(const struct contact* con)
{
	char name[Max_name];
	printf("请输入查找的联系人的姓名\n");
	scanf("%s", name);
	int pos = FindName(con, name);
	if (pos == -1)
	{
		printf("没有找到该联系人！\n");
	}
	else 
	{
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-10s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			con->data[pos].name,
			con->data[pos].age,
			con->data[pos].sex,
			con->data[pos].tel,
			con->data[pos].addr);
	} 
}
void modifycontact(struct contact* con)
{
	char name[Max_name];
	printf("请输入要修改的名字\n");
	scanf("%s", name);
	int ret = FindName(con, name);
	if (ret == -1)
	{
		printf("未找到该联系人\n");

	}
	else
	{
		printf("请输入姓名：\n");
		scanf("%s", con->data[ret].name);
		printf("请输入年龄：\n");
		scanf("%d", &con->data[ret].age);
		printf("请输入性别：\n");
		scanf("%s", con->data[ret].sex);
		printf("请输入电话：\n");
		scanf("%s", con->data[ret].tel);
		printf("请输入地址：\n");
		scanf("%s", con->data[ret].addr);
		printf("添加成功！\n");
	}
}

void sortcontact(struct contact* con)
{
	int i, j;
	for (i = 0; i < con->size; i++)
	{
		for (j = con->size-1; j > i; j--)
		{
			if (strcmp(con->data[i].name, con->data[j].name) > 0)
			{
				struct peoInfo temp;
				temp = con->data[i];
				con->data[i] = con->data[j];
				con->data[j] = temp;
			}
		}
	}
	printf("排序成功！\n");
}