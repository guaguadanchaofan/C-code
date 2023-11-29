#define  _CRT_SECURE_NO_WARNINGS
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  *
  * @param pListHead ListNode��
  * @param k int����
  * @return ListNode��
  */
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    if (pListHead == NULL)
    {
        return NULL;
    }
    int i = 0;
    struct ListNode* cur = pListHead;
    while (cur)
    {
        cur = cur->next;
        i++;
    }
    if (k > i)
    {
        return NULL;
    }
    cur = pListHead;
    while (i - k)
    {
        cur = cur->next;
        i--;
    }
    return cur;
}