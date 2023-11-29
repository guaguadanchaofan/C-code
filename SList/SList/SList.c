#define  _CRT_SECURE_NO_WARNINGS
#include"SList.h"


//��̬����ڵ�
SListNode* BuySListNode(SLTDatetype x)
{
	struct SListNode* NewNode = (SListNode*)malloc(sizeof(SListNode));
	assert(NewNode);
	NewNode->val = x;
	NewNode->Next = NULL;
	return NewNode;
}

//��ӡ
void SListPrint(SListNode* Plist)
{
	if (Plist == NULL)
	{
		printf(" no data print\n");
			return;
	}
	while (Plist)
	{
		printf("%d->", Plist->val);
		Plist = Plist->Next;
	}
	printf("NULL\n");
}

//β��
void SListPushBack(SListNode** PPlist, SLTDatetype x)
{
	assert(PPlist);
	SListNode* NewNode = BuySListNode(x);
	if (*PPlist == NULL)
	{
		*PPlist = NewNode;
	}
	else
	{
		SListNode* tail = *PPlist;
		while (tail->Next != NULL)
		{
			tail = tail->Next;
		}
		tail->Next = NewNode;
	}
}

//βɾ
void SListPopBack(SListNode** PPlist)
{
	SListNode* cur = *PPlist;
	SListNode* tail = NULL;
	if (cur == NULL||cur->Next==NULL)
	{
		free(cur);
		*PPlist = NULL;
	}
	else
	{
		while (cur->Next!=NULL)
		{
				tail = cur;
				cur = cur->Next;
		}
		free(cur);
		cur = NULL;
		tail->Next = NULL;
	}
}

//ͷ��
void SListpushFront(SListNode** PPlist,SLTDatetype x)
{
	assert(PPlist);
	SListNode* NewNode = BuySListNode(x);
	if (*PPlist == NULL)
	{
		*PPlist = NewNode;
	}
	else
	{
		NewNode->Next = *PPlist;
		*PPlist = NewNode;
	}
}

//ͷɾ
void SListPopFront(SListNode** PPlist)
{
	SListNode* node = *PPlist;
	if (*PPlist == NULL)
	{
		return;
	}
	node = node->Next;
	free(*PPlist);
	*PPlist = node;
}

//����
SListNode* SListFind(SListNode* Plist, SLTDatetype x)
{
	SListNode* cur = Plist;
	while (cur)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->Next;
	}
	return NULL;
}

//posλ�ú��
void SListInsertAfter(SListNode* pos, SLTDatetype x)
{
	assert(pos);
	SListNode* next = pos->Next;
	SListNode* newnode = BuySListNode(x);
	newnode->Next = next;
	pos->Next = newnode;
}

//posλ�ú�ɾ��
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->Next == NULL)
	{
		printf("֮��������ɾ��\n");
	}
	SListNode* save = pos->Next;
	SListNode* nextnext = save->Next;
	pos->Next = nextnext;
	free(save);
	save = NULL;
}
