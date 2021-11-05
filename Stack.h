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

//��ʼ��ջ
Node* InitStack();

//��ջ
void PushStack(Node* head,void* data);
//��ջ
void PopStack(Node* head);
//����ջ��Ԫ��
Node* StackTop(Node* Node);
//����ջԪ�ظ���
int StackNum(Node* Node);
//ջ�����
Node* ClearStack(Node* head);
//ջ������
void StackDeatroy(Node* Node);

