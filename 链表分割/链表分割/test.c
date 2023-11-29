#define  _CRT_SECURE_NO_WARNINGS
/*

struct ListNode {

    int val;

    struct ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

};*/

class Partition {

public:

    ListNode* partition(ListNode* pHead, int x) {

        if (pHead == nullptr)

        {

            return nullptr;

        }

        struct ListNode* lesshead, * lesstail, * passhead, * passtail;

        lesshead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode));

        passhead = passtail = (struct ListNode*)malloc(sizeof(struct ListNode));

        //struct ListNode*save;

        struct ListNode* cur = pHead;

        while (cur)

        {

            if (cur->val >= x)

            {

                //save=cur->next;

                passtail->next = cur;

                passtail = passtail->next;

            }

            else

            {

                //save=cur->next;

                lesstail->next = cur;

                lesstail = lesstail->next;

            }

            cur = cur->next;

        }

        lesstail->next = passhead->next;

        passtail->next = nullptr;

        pHead = lesshead->next;

        free(lesshead);

        free(passhead);

        return pHead;

    }

};