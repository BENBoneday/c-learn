#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ListNode
{
    int val;
    struct ListNode* next;
};
struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    int count = 0;
    if (head->next == NULL)
    {
        return head;
    }
    while (fast != NULL)
    {
        fast = fast->next;

        if (count == k)
        {
            slow = slow->next;

        }
        if (count != k)
        {
            count++;
        }
    }
    return slow;
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
    n3->next = n4;
    n3->val = 9;
    n4->next = n5;
    n4->val = 10;
    n5->next = n6;
    n5->val = 6;
    n6->next = NULL;
    n6->val = 33;
    struct ListNode* head = getKthFromEnd(n1, 2);
    while (head)
    {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("NULL");
	return 0;
}