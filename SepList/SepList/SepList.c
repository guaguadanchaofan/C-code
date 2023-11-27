#define  _CRT_SECURE_NO_WARNINGS
#include"SepList.h"

//˳����ʼ��
void SepListInit(SepList* ps)
{
	assert(ps);
	if (ps == NULL)
	{
		return;
	}
	ps->capacity = 0;
	ps->data = NULL;
	ps->size = 0;
}

//˳�������
void SepListDstroy(SepList* ps)
{
	assert(ps);
	if (ps == NULL)
	{
		return;
	}
	free(ps->data);
	ps->data= NULL;
	ps->capacity = 0;
	ps->size = 0;
}

//˳����������
void SepListCheckCapacity(SepList* ps)
{
	assert(ps);
	if (ps == NULL)
	{
		return;
	}
	if (ps->size == ps->capacity)
	{ 
		SepListType* temp =realloc(ps->data,sizeof(SepListType) * (ps->capacity+2));
		if (temp == NULL)
		{
			return;
		}
		ps->capacity += 2;
		ps->data = temp;
	}
}

//˳���β��
void SepListPushBack(SepList* ps, SepListType x)
{
	assert(ps);
	if (ps == NULL)
	{
		return;
	}
	SepListCheckCapacity(ps);
	ps->data[ps->size] = x;
	ps->size++;
}

//˳���βɾ
void SepListPopBack(SepList* ps)
{
	assert(ps);
	if (ps == NULL)
	{
		return;
	}
	if (ps->size > 0)
	{
		ps->size--;
	}
}

//˳����ӡ
void SepListPrint(SepList* ps)
{
	assert(ps);
	if (ps == NULL)
	{
		return;
	}
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}

//ͷ��
void SepListPushFront(SepList* ps, SepListType x)
{
	assert(ps);
	if (ps == NULL)
	{
		return;
	}
	SepListCheckCapacity(ps);
	for (int i = 0; i < ps->size; i++)
	{
		ps->data[ps->size - i] = ps->data[ps->size - 1 - i];
	}
	ps->data[0] = x;
	ps->size++;
}

//ͷɾ
void SepListPopFront(SepList* ps)
{
	assert(ps);
	if (ps == NULL)
	{
		return;
	}
	if(ps->size>1)
	{
		for (int i = 1; i < ps->size; i++)
		{
			ps->data[i-1] = ps->data[i];
		}
	}
	ps->size--;
}

//����
int SepListFind(SepList* ps, SepListType x)
{
	assert(ps);
	if (ps == NULL)
	{
		return -1;
	}
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->data[i] == x)
		{
			return i;
		}
	}
	return -1;
}

// ˳�����posλ�ò���x
void SepListInsert(SepList* ps, size_t pos, SepListType x)
{
	assert(ps);
	if (ps == NULL)
	{
		return;
	}
	SepListCheckCapacity(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->size - 1 - i >= pos)
		{
			ps->data[ps->size-i] = ps->data[ps->size -1-i];
		}
	}
	ps->data[pos] = x;
	ps->size++;
}


// ˳���ɾ��posλ�õ�ֵ
void SepListErase(SepList* ps, size_t pos)
{
	assert(ps);
	if (ps == NULL)
	{
		return;
	}
	for (int i = 0; i < ps->size-1-pos; i++)
	{
		if (ps->size - 1 - i >= pos)
		{
			ps->data[pos+i] = ps->data[pos+1+i];
		}
	}
	ps->size--;
}