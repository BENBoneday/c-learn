#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct ListNode Node;
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* prev = NULL;
    Node* cur = head;
    Node* next = cur->next;
    while (next)
    {
        if (cur->val != next->val)
        {
            prev = cur;
            cur = next;
            next = next->next;
        }
        else
        {
            while (next && next->val == cur->val)
            {
                next = next->next;
            }
            if (prev)
            {
                prev->next = next;
            }
            else
            {
                head = next;
            }
            //ÊÍ·Å
            while (cur != next)
            {
                Node* del = cur;
                cur = cur->next;
                free(del);

            }
            if (next)
                next = cur->next;
        }

    }
    return head;
}