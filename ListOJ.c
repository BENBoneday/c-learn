//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
////·´×ªÁ´±í
//struct ListNode
//{
//    struct ListNode* next;
//};
//    
//struct ListNode* ReverseList(struct ListNode* pHead) {
//    // write code here
//    if (pHead == NULL)
//    {
//        return pHead;
//    }
//    struct ListNode* n1 = NULL;
//    struct ListNode* n2 = pHead;
//    struct ListNode* n3 = pHead->next;
//    while (n2 != NULL)
//    {
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//        if (n3)
//            n3 = n3->next;
//    }
//    return n1;
//}
//int main()
//{
//    return 0;
//}