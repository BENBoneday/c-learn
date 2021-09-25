#define _CRT_SECURE_NO_WARNINGS 1
#define Max_name 20 
#define Max_tel 12 
#define Max_sex 5 
#define Max_addr 20 
#define Max_size 1000 
#include<string.h>
#include<stdio.h>
//#include<stdio.h>
enum fun
{
	exit,
	add,
	delete,
	search,
	modify,
	show,
	sort
};
struct peoInfo
{
	char name[Max_name];
	int age;
	char sex[Max_sex];
	char tel[Max_tel];
	char addr[Max_addr];
};
struct contact
{
	struct peoInfo data[Max_size];
	int size;
};
void Initcontact(struct contact* con);
void addcontact(struct contact* con);
void showcontact(const struct contact* con);
void deletecontact(struct contact* con);
void searchcontact(const struct contact* con);
void modifycontact(struct contact* con);