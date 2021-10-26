#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* sortHead = head;
    Node* cur = head->next;
    sortHead->next = NULL;
    while (cur)
    {
        Node* next = cur->next;
        if (cur->val <= sortHead->val)
        {
            cur->next = sortHead;
            sortHead = cur;
        }
        else
        {
            Node* sortPreu = sortHead;
            Node* sortCur = sortPreu->next;
            while (sortCur)
            {
                if (cur->val <= sortCur->val)
                {
                    sortPreu->next = cur;
                    cur->next = sortCur;
                    break;
                }
                else
                {
                    sortPreu = sortCur;
                    sortCur = sortCur->next;
                }
            }

            //
            if (sortCur == NULL)
            {
                sortPreu->next = cur;
                cur->next = NULL;
            }
        }
        cur = next;
    }
    return sortHead;
}