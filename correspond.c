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
		printf("ͨѶ¼����\n");
	}
	else
	{
		printf("������������\n");
		scanf("%s", con->data[con->size].name);
		printf("���������䣺\n");
		scanf("%d", &con->data[con->size].age);
		printf("�������Ա�\n");
		scanf("%s", con->data[con->size].sex);
		printf("������绰��\n");
		scanf("%s", con->data[con->size].tel);
		printf("�������ַ��\n");
		scanf("%s", con->data[con->size].addr);
		printf("��ӳɹ���\n");
		con->size++;
	}

}
void showcontact(const struct contact* con)
{
	if (con->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("������Ҫɾ��������\n");
	scanf("%s", name);
	int i = 0;
	int ret = FindName(con, name);
	if (ret==-1)
	{
		printf("û���ҵ�Ҫɾ��������\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < con->size-1; j++)
		{
			con->data[j] = con->data[j + 1];
		}
		con->size--;
		printf("ɾ���ɹ���\n");
	}
}
void searchcontact(const struct contact* con)
{
	char name[Max_name];
	printf("��������ҵ���ϵ�˵�����\n");
	scanf("%s", name);
	int pos = FindName(con, name);
	if (pos == -1)
	{
		printf("û���ҵ�����ϵ�ˣ�\n");
	}
	else 
	{
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("������Ҫ�޸ĵ�����\n");
	scanf("%s", name);
	int ret = FindName(con, name);
	if (ret == -1)
	{
		printf("δ�ҵ�����ϵ��\n");

	}
	else
	{
		printf("������������\n");
		scanf("%s", con->data[ret].name);
		printf("���������䣺\n");
		scanf("%d", &con->data[ret].age);
		printf("�������Ա�\n");
		scanf("%s", con->data[ret].sex);
		printf("������绰��\n");
		scanf("%s", con->data[ret].tel);
		printf("�������ַ��\n");
		scanf("%s", con->data[ret].addr);
		printf("��ӳɹ���\n");
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
	printf("����ɹ���\n");
}