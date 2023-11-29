#define  _CRT_SECURE_NO_WARNINGS

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* newlist = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        struct ListNode* newnode = cur->next;
        cur->next = newlist;
        newlist = cur;
        cur = newnode;
    }
    return newlist;
}