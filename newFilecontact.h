#define _CRT_SECURE_NO_WARNINGS 1
#define Max_name 20 
#define Max_tel 12 
#define Max_sex 5 
#define Max_addr 20 
#define Max_size 1000 
#define InitCapacity 3//初始容量
#define addCapacity 2 //每次追加的容量
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
//#include<stdio.h>
enum fun
{
	Exit,
	add,
	delete,
	search,
	modify,
	show,
	sort,
	save
};
typedef struct peoInfo
{
	char name[Max_name];
	int age;
	char sex[Max_sex];
	char tel[Max_tel];
	char addr[Max_addr];
}peoInfo;
typedef struct contact
{
	struct peoInfo* data;
	int size;
	int capacity;
}contact;
void Initcontact(struct contact* con);
void addcontact(struct contact* con);
void showcontact(const struct contact* con);
void deletecontact(struct contact* con);
void searchcontact(const struct contact* con);
void modifycontact(struct contact* con);
void sortcontact(struct contact* con);
void DestroyContact(contact* con);
void savecontact(contact* con);
void loadcontact(contact* con);