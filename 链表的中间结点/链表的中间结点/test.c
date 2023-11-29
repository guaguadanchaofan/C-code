#define  _CRT_SECURE_NO_WARNINGS
/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     struct ListNode *next;

 * };

 */

struct ListNode* middleNode(struct ListNode* head) {

    int i = 0;

    struct ListNode* cur = head;

    if (head->next == NULL)

    {

        return head;

    }

    while (cur)

    {

        i++;

        cur = cur->next;

    }

    cur = head;

    i = i / 2;

    while (i)

    {

        cur = cur->next;

        i--;

    }

    return cur;

}