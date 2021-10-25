#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ListNode
{
    int val;
    struct ListNode* next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    if (l1->val < l2->val)
    {
        head = tail = l1;
        l1 = l1->next;
    }
    else
    {
        head = tail = l2;
        l2 = l2->next;
    }
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1)
        tail->next = l1;
    if (l2)
        tail->next = l2;

    return head;
}
int main()
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n1->next = n2;
    n1->val = 6;
    n2->next = n3;
    n2->val = 4;
    n3->next = NULL;
    n3->val = 9;
    n4->next = n5;
    n4->val = 10;
    n5->next = n6;
    n5->val = 6;
    n6->next = NULL;
    n6->val = 33;
    struct ListNode* head = mergeTwoLists(n1, n4);
    while (head)
    {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("NULL");
    return 0;
}