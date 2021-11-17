#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
//��ʼ��ջ
Node* InitStack() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	head->data = 0;
	head->size = 0;
	return head;
}
//��ջ
void PushStack(Node* head, void* data) {
	assert(head);
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (newNode == NULL)
	{
		exit(-1);
	}
	newNode->next = head;
	head = newNode;
	head->size++;
}
//��ջ
void PopStack(Node* head) {
	assert(head);
	Node* out = head;
	head = head->next;
	free(out);
	out = NULL;
	return head;
}
//����ջ��Ԫ��
Node* StackTop(Node* Node) {
	return Node;
}
//����ջԪ�ظ���
int StackNum(Node* Node) {
	return Node->size;
}
//ջ�����
Node* ClearStack(Node* head) {
	assert(head);
	while (head->size != 0)
	{
		Node* clearNode = head;
		head = head->next;
		free(clearNode);
		clearNode = NULL;
		head->size--;
	}
	return head;
}
//ջ������
void StackDeatroy(Node* Node) {
	
}
