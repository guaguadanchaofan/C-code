#include"List.h"


//��ʼ��
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

//��ӡ
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

//�����½ڵ�
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	assert(node);
	node->x = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

//β��
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

//βɾ
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

//ͷ��
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

//ͷɾ
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

//����
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

//pos����
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

//posɾ��
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

//�������
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
