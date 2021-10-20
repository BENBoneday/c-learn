#define _CRT_SECURE_NO_WARNINGS 1
#include"singleList.h"
Node* BuyListNode(SListDataType x)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("%s", strerror(errno));
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
void SListPushBack(Node* phead, SListDataType x)
{
	Node* newNode = BuyListNode(x);
	if (phead == NULL)
	{
		phead->next = newNode;
	}
	else
	{
		Node* tail = phead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
		newNode->data = x;
		newNode->next = NULL;
	}
	
}
void SListPrint(Node* phead)
{
	Node* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
}