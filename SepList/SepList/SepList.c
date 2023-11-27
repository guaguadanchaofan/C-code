#define  _CRT_SECURE_NO_WARNINGS
#include"SepList.h"

//顺序表初始化
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

//顺序表销毁
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

//顺序表容量检查
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

//顺序表尾插
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

//顺序表尾删
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

//顺序表打印
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

//头插
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

//头删
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

//查找
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

// 顺序表在pos位置插入x
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


// 顺序表删除pos位置的值
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