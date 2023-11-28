#define  _CRT_SECURE_NO_WARNINGS
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sockCollocation(int* sockets, int socketsSize, int* returnSize) {
    int i = 0;
    int num1 = 0;
    int num2 = 0;
    int a = 0;
    int pos = 0;
    for (i = 0; i < socketsSize; i++)
    {
        a ^= sockets[i];
    }
    int* arr = (int*)malloc(2 * sizeof(int));
    for (i = 0; i < 32; i++)
    {
        if ((a >> i) & 1 == 1)
        {
            pos = i;
            break;
        }
    }
    for (i = 0; i < socketsSize; i++)
    {
        if (sockets[i] >> pos & 1 == 1)
        {
            num1 ^= sockets[i];
        }
        else
        {
            num2 ^= sockets[i];
        }
    }
    arr[0] = num1;
    arr[1] = num2;
    *returnSize = 2;
    return arr;
}
int missingNumber(int* nums, int numsSize) {

    int sum = ((numsSize + 1) * (numsSize)) / 2;

    int i = 0;

    for (i = 0; i < numsSize; i++)

    {

        sum = sum - nums[i];

    }

    return sum;

}

void rotate(int* nums, int numsSize, int k) {
    int arr[numsSize];
    for (int i = 0; i < numsSize; i++)
    {
        arr[(i + k) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; ++i)
    {
        nums[i] = arr[i];
    }
}
int removeElement(int* nums, int numsSize, int val) {

    int count = 0;

    for (int i = 0; i < numsSize; i++)

    {

        if (nums[i] != val)

        {

            nums[count] = nums[i];

            count++;

        }

    }

    return count;

}
int removeDuplicates(int* nums, int numsSize) {

    if (numsSize == 0)

    {

        return 0;

    }

    int fast = 1;

    int slow = 1;

    while (fast < numsSize)

    {

        if (nums[fast] != nums[fast - 1])

        {

            nums[slow] = nums[fast];

            slow++;

        }

        fast++;

    }

    return slow;

}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    while (cur)
    {
        if (cur->val != val)
        {
            prev = cur;
        }
        else
        {
            if (prev == NULL)
            {
                head = head->next;
            }
            else
                prev->next = cur->next;
        }
        cur = cur->next;
    }
    return head;
}