#define  _CRT_SECURE_NO_WARNINGS
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    ListNode* listA = headA;
    ListNode* listB = headB;
    int la = 0;
    while (listA)
    {
        la++;
        listA = listA->next;
    }
    int lb = 0;
    while (listB)
    {
        lb++;
        listB = listB->next;
    }
    int num = abs(la - lb);
    ListNode* curB = headB;
    ListNode* curA = headA;
    if (la > lb)
    {
        while (num)
        {
            curA = curA->next;
            num--;
        }
    }
    else
    {
        while (num)
        {
            curB = curB->next;
            num--;
        }
    }
    while (curA != curB && curA != NULL && curB != NULL)
    {
        curA = curA->next;
        curB = curB->next;
    }
    if (curA == NULL || curB == NULL)
    {
        return NULL;
    }
    else
    {
        return curA;
    }
}