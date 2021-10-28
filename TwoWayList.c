#define _CRT_SECURE_NO_WARNINGS 1
#include"TwoWayList.h"
Node* CreatNewNode(LTDataType x)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("%s", strerror(errno));
		exit(-1);
	}
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->val = x;
	return newNode;
}
Node* ListInit()
{
	Node* phead = CreatNewNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void ListPushBack(Node* phead, LTDataType x)
{
	Node* newNode =CreatNewNode(x);
	Node* tail = phead->prev;
	tail->next = newNode;
	newNode->prev = tail;
	phead->prev = newNode;
	newNode->next = phead;
}
void ListPopBack(Node* phead)
{
	assert(phead);
	assert(phead->next != phead);
	Node* tail = phead->prev;
	phead->prev = tail->prev;
	tail->prev->next = phead;
	free(tail);
	tail = NULL;
}
void ListPrint(Node* phead)
{
	assert(phead);
	Node* cur = phead->next;
	printf("%d->", phead->val);
	while (cur != phead)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("\n");
}