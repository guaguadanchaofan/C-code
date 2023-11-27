#define  _CRT_SECURE_NO_WARNINGS
#include"SepList.h"
int main()
{
	SepList s1;
	SepListInit(&s1);
	SepListPushBack(&s1, 1);
	SepListPushBack(&s1, 2);
	SepListPushBack(&s1, 3);
	SepListPushBack(&s1, 4);
	SepListPushBack(&s1, 5);
	SepListPushBack(&s1, 6);
	SepListPushBack(&s1, 7);
	SepListPushBack(&s1, 8);
	SepListPushBack(&s1, 9);
	SepListInsert(&s1, 4, 4);
	SepListPrint(&s1);
	SepListErase(&s1, 4);
	SepListErase(&s1, 4);
	SepListErase(&s1, 4);
	SepListErase(&s1, 4);
	SepListErase(&s1, 4);
	SepListPrint(&s1);

	return 0;
}