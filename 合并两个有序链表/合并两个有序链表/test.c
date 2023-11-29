#define  _CRT_SECURE_NO_WARNINGS
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL)
    {
        return list2;
    }
    else if (list2 == NULL)
    {
        return list1;
    }
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    tail->next = NULL;
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            tail->next = list1;
            tail = tail->next;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            tail = tail->next;
            list2 = list2->next;
        }
    }
    if (list1)
    {
        tail->next = list1;
    }
    else
    {
        tail->next = list2;
    }
    struct ListNode* list = head->next;
    return list;
}