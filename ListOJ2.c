#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode
{
    struct ListNode* next;
};
struct ListNode* ReverseList(struct ListNode* pHead) {
    // write code here
    if (pHead == NULL)
    {
        return pHead;
    }
    struct ListNode* cur = pHead;
    struct ListNode* next = pHead->next;
    struct ListNode* newHead = NULL;
    while (cur != NULL)
    {
        cur->next = newHead;
        newHead = cur;
        cur = next;
        next = next->next;
    }
    return newHead;
}
int main()
{
    return 0;
}