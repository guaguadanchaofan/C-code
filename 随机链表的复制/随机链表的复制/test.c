#define  _CRT_SECURE_NO_WARNINGS
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
typedef struct Node Node;
struct Node* copyRandomList(struct Node* head) {
    if (head == NULL)
    {
        return NULL;
    }
    Node* cur = head;
    Node* next = head->next;
    while (cur)
    {
        Node* copy = (Node*)malloc(sizeof(Node));
        copy->val = cur->val;
        copy->next = next;
        cur->next = copy;
        if (next == NULL)
        {
            break;
        }
        cur = next;
        next = next->next;
    }
    cur = head;
    while (cur)
    {
        Node* copy = cur->next;
        if (cur->random != NULL)
        {
            copy->random = cur->random->next;
        }
        else
        {
            copy->random = NULL;
        }
        cur = copy->next;
    }
    Node* copyhead = NULL;
    Node* copytail = NULL;
    cur = head;
    while (cur)
    {
        Node* copy = cur->next;
        Node* next = copy->next;
        if (copytail == NULL)
        {
            copyhead = copytail = copy;
        }
        else
        {
            copytail->next = copy;
            copytail = copy;
        }
        cur->next = next;
        cur = next;
    }
    return copyhead;
}