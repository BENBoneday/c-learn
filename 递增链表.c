#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct LIST
{
	struct LIST* next;
	int val;
}List;
List* InitList1()
{
	List* head = (List*)malloc(sizeof(List));
	head->val = 1;
	List* node= (List*)malloc(sizeof(List));
	node->val = 3;
	head->next = node;
	node->next = NULL;
	
	
	return head;
}
List* InitList2()
{
	List* head = (List*)malloc(sizeof(List));
	head->val = 0;
	List* node = (List*)malloc(sizeof(List));
	node->val = 4;
	head->next = node;
	List* node1 = (List*)malloc(sizeof(List));
	node1->val = 5;
	node->next = node1;
	node1->next = NULL;

	return head;
}
List* CreateNode(List* l, int val)
{
	List* node = (List*)malloc(sizeof(node));
	l->next = node;
	node->next = NULL;
	return node;
}
void Destroy(List* l)
{
	if (l == NULL)
	{
		return;
	}
	List* cur = l;
	while (cur)
	{
		List* next = cur->next;
		free(cur);
		cur = next;
	}
}
List* MergeList(List* l1,List* l2)
{
	List* head = (List*)malloc(sizeof(List));
	if (l1->val < l2->val)
	{
		head->val = l1->val;
		head->next = NULL;
		l1 = l1->next;
	}
	else
	{
		head->val = l2->val;
		head->next = NULL;
		l2 = l2->next;
	}
	while (l1 && l2)
	{
		List* newnode = (List*)malloc(sizeof(List));
		if (l1->val < l2->val)
		{
			newnode->val = l1->val;
			newnode->next = head;
			head = newnode;
			l1 = l1->next;
		}
		else
		{
			newnode->val = l2->val;
			newnode->next = head;
			head = newnode;
			l2 = l2->next;
		}
	}
	if (l1)
	{
		while (l1)
		{
			List* newnode = (List*)malloc(sizeof(List));
			newnode->val=l1->val;
			newnode->next = head;
			head = newnode;
			l1 = l1->next;
		}
	}
	if (l2)
	{
		while (l2)
		{
			List* newnode = (List*)malloc(sizeof(List));
			newnode->val = l2->val;
			newnode->next = head;
			head = newnode;
			l2 = l2->next;
		}
	}
	return head;
}
int main()
{
	List* l1 = InitList1();
	List* l2 = InitList2();
	
	List* cur1 = l1;
	List* cur2 = l2;
	
	List* cur3=  MergeList(l1, l2);
	while (cur1)
	{
		printf("%d->", cur1->val);
		cur1=cur1->next;
	}
	printf("NULL\n");
	while (cur2)
	{
		printf("%d->", cur2->val);
		cur2 = cur2->next;
	}
	printf("NULL\n");
	while (cur3)
	{
		printf("%d->", cur3->val);
		cur3 = cur3->next;
	}
	printf("NULL\n");
	Destroy(l1);
	Destroy(l2);
	
	
	return 0;
}