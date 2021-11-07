#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkQueue.h"
//��ʼ��
Node* InitQueue() {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	Node* node = (Node*)malloc(sizeof(Node));
	queue->head = node;
	queue->tail = node;
	queue->head->next = node;
	queue->size = 0;
	
	return queue;
}
//���
void PushQueue( Queue* queue, void* data) {
	if (queue == NULL)
	{
		return;
	}
	Node* node = (Node*)malloc(sizeof(Node));
	Node* cur = queue->head;
	node->data = data;
	cur->next= node;
	node->next = cur;
	cur = node;
	queue->tail = node;
	queue->size++;
}
//���ض�ͷԪ��
Node* FrontQueue( Queue* queue) {
	if (queue == NULL)
	{
		return NULL;
	}
	return queue->head;
}
//����
void PopQueue( Queue* queue) {
	if (queue == NULL)
	{
		return;
	}
	Node* newTop = queue->head->next;
	free(queue->head);
	queue->head == NULL;
	queue->head = newTop;
	queue->tail->next = newTop;
	queue->size--;
}
//���ض�βԪ��
Node* TailQueue( Queue* queue) {
	if (queue == NULL)
	{
		return NULL;
	}
	return queue->tail;
}
//���ٶ���
void DestroyQueue( Queue* queue) {
	if (queue == NULL)
	{
		return;
	}
	Node* cur = queue->head;
	while (cur)
	{
		Node* next = cur->next;
		free(cur);
		cur = NULL;
		cur = next;
	}
}
//��ն���
void ClearQueue( Queue* queue) {
	if (queue == NULL)
	{
		return;
	}
	Node* cur = queue->head->next;
	while (cur->next!=queue->head)
	{
		Node* next = cur->next;
		free(cur);
		cur = NULL;
		cur = next;
		queue->size--;
	}
}
int QueueNum(Queue* queue)
{
	if (queue == NULL)
	{
		return;
	}
	return queue->size;
}