#define  _CRT_SECURE_NO_WARNINGS
#include"SList.h"

int main()
{
	SListNode *PList=NULL;
	SListPushBack(&PList, 1);
	SListPushBack(&PList, 2);
	SListPushBack(&PList, 3);
	SListPushBack(&PList, 4);
	SListPushBack(&PList, 5);
	SListPushBack(&PList, 6);
	SListPushBack(&PList, 7);
	SListPushBack(&PList, 8);
	SListPrint(PList);
	SListPopBack(&PList);
	SListPopBack(&PList);
	SListPopBack(&PList);
	SListPopBack(&PList);
	SListpushFront(&PList, 5);
	SListpushFront(&PList, 6);
	SListpushFront(&PList, 7);
	SListpushFront(&PList, 8);
	SListPrint(PList);
	SListPopFront(&PList);
	SListPrint(PList);
	SListNode* ret = SListFind(PList,100);
	return 0;
}
