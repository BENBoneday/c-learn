#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkQueue.h"
typedef struct Person
{
	Node node;
	char name[20];
	int age;
}Person;
int main()
{
	Queue* queue = InitQueue();

	Person p1, p2, p3, p4, p5;

	strcpy(p1.name, "aaa");
	strcpy(p2.name, "bbb");
	strcpy(p3.name, "ccc");
	strcpy(p4.name, "ddd");
	strcpy(p5.name, "eee");

	p1.age = 20;
	p2.age = 30;
	p3.age = 40;
	p4.age = 50;
	p5.age = 60;

	PushQueue(queue, (Node*)&p1);
	PushQueue(queue, (Node*)&p2);
	PushQueue(queue, (Node*)&p3);
	PushQueue(queue, (Node*)&p4);
	PushQueue(queue, (Node*)&p5);

	while (QueueNum(queue)>0)
	{
		Person* p = (Person*)FrontQueue(queue);
		printf("Name:%s   Age:%d\n", p->name, p->age);
		PopQueue(queue);
	}
	DestroyQueue(queue);
	return 0;
}