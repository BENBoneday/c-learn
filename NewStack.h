#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef struct LinkNode
{
	void* data;
	struct LinkNode* next;
	int size;
}Node;

//初始化栈
Node* InitStack();

//入栈
void PushStack(Node* head,void* data);
//出栈
void PopStack(Node* head);
//返回栈顶元素
Node* StackTop(Node* Node);
//返回栈元素个数
int StackNum(Node* Node);
//栈的清空
Node* ClearStack(Node* head);
//栈的销毁
void StackDeatroy(Node* Node);

