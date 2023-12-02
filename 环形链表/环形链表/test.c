#define  _CRT_SECURE_NO_WARNINGS
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
bool hasCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != slow)
    {
        if (fast == NULL || fast->next == NULL)
        {
            return false;
        }
        fast = fast->next->next;
        slow = slow->next;

    }
    return true;
}