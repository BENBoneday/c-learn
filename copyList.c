#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};
typedef struct Node Node;
typedef struct Node Node;
struct Node* copyRandomList(struct Node* head)
{
    if (head == NULL)
        return NULL;
    //1.复制链表结点并连接
    Node* cur = head;
    while (cur)
    {
        Node* copy = (Node*)malloc(sizeof(Node));//创建结点
        copy->next = NULL;
        copy->random = NULL;
        copy->val = cur->val;



        Node* next = cur->next;

        cur->next = copy;
        copy->next = next;//连接


        cur = next;
    }
    //2.处理copy结点中的random
    cur = head;
    while (cur)
    {
        Node* copy = cur->next;
        if (cur->random)
        {
            copy->random = cur->random->next;
        }
        else
        {
            copy->random = NULL;
        }
        cur = cur->next->next;
    }
    //3.拆解链表
    cur = head;
    Node* copyHead = head->next;
    while (cur)
    {
        Node* copy = cur->next;
        Node* next = copy->next;
        cur->next = next;
        if (next)
            copy->next = next->next;
        else
            copy->next = NULL;

        cur = next;
    }
    return copyHead;
}
int main()
{
    return 0;
}