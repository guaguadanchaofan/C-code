#define  _CRT_SECURE_NO_WARNINGS
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
struct ListNode* detectCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != NULL)
    {
        slow = slow->next;
        if (fast->next == NULL)
        {
            return NULL;
        }
        fast = fast->next->next;
        if (fast == slow)
        {
            ListNode* ptr = head;
            while (ptr != slow)
            {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return NULL;
}