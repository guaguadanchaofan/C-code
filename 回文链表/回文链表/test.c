#define  _CRT_SECURE_NO_WARNINGS
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* newA = NULL;
    struct ListNode* save = NULL;
    while (slow)
    {
        save = slow;
        slow = slow->next;
        save->next = newA;
        newA = save;
    }
    while (newA)
    {
        if (newA->val != head->val)
        {
            return false;
        }
        newA = newA->next;
        head = head->next;
    }
    return true;
}