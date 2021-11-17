#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
//初始化栈
Node* InitStack() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	head->data = 0;
	head->size = 0;
	return head;
}
//入栈
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
//出栈
void PopStack(Node* head) {
	assert(head);
	Node* out = head;
	head = head->next;
	free(out);
	out = NULL;
	return head;
}
//返回栈顶元素
Node* StackTop(Node* Node) {
	return Node;
}
//返回栈元素个数
int StackNum(Node* Node) {
	return Node->size;
}
//栈的清空
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
//栈的销毁
void StackDeatroy(Node* Node) {
	
}
