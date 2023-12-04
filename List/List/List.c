#include"List.h"


//初始化
ListNode* InitList()
{
	ListNode* phead = (ListNode*)malloc(sizeof(ListNode));
	if (phead == NULL)
	{
		printf("error");
		exit(-1);
	}
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//打印
void PrintList(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->x);
		cur = cur->next;
	}
	printf("\n");
}

//申请新节点
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	assert(node);
	node->x = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

//尾插
void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);
	/*ListNode* node = BuyListNode(x);
	ListNode* tail = phead->prev;
	node->prev = tail;
	tail->next = node;
	node->next = phead;
	phead->prev = node;*/
	ListInsert(phead, x);
}

//尾删
void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	/*ListNode* tail = phead->prev;
	ListNode* tailPrev = tail->prev;
	phead->prev = tailPrev;
	tailPrev->next = phead;*/
	ListErase(phead->prev);
}

//头插
void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);
	/*ListNode* node = BuyListNode(x);
	ListNode* first = phead->next;
	node->next = first;
	node->prev = phead;
	first->prev = node;
	phead->next = node;*/
	ListInsert(phead->next, x);
}

//头删
void ListPopFront(ListNode* phead)
{
	assert(phead->next != phead);
	assert(phead);
	/*ListNode* first = phead->next;
	ListNode* second = first->next;
	phead->next = second;
	second->prev = phead;
	free(first);*/
	ListErase(phead->next);
}

//查找
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->x == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//pos插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* node = BuyListNode(x);
	node->next = pos;
	node->prev = prev;
	pos->prev = node;
	prev->next = node;
}

//pos删除
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* next = pos->next;
	ListNode* prev = pos->prev;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}

//链表清空
void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur!=phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}
