#include"List.h"
void test(ListNode* phead)
{
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	PrintList(phead);
	ListPushFront(phead, 1);
	ListPushFront(phead, 2);
	ListPushFront(phead, 3);
	ListPushFront(phead, 4);
	ListPushFront(phead, 5);
	PrintList(phead);
}


int main()
{
	ListNode* phead=InitList();
	test(phead);
	return 0;
}