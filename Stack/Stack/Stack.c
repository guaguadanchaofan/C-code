#include"Stack.h"


//�������
void CheckCapacity(Stack* ps)
{
	if (ps->_capacity == ps->_top)
	{
		ps->_capacity *= 2;
		ps->_a = (STDataType*)realloc(ps->_a,ps->_capacity* sizeof(STDataType));
	}
}

//��ʼ��ջ
void SrackInit(Stack* ps)
{
	assert(ps);
	ps->_a = (STDataType*)calloc(STACKSIZE, sizeof(STDataType));
	ps->_top = 0;
	ps->_capacity = STACKSIZE;
}

//��ջ
void SrackPush(Stack* ps,STDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->_a[ps->_top] = x;
	ps->_top++;
}
//��ջ
void SrackPop(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return;
	}
	ps->_top--;
}

//��ȡջ������
STDataType SrackTop(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		printf("stack no data!\n");
		return (STDataType)0;
	}
	return ps->_a[ps->_top - 1];
}

//��ȡջ��Ԫ����Ч����
STDataType SrackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
//���ջ�Ƿ�Ϊ�գ���Ϊ1���ǿ�Ϊ0
STDataType SrackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//����ջ
void SrackDestory(Stack* ps)
{
	assert(ps);
	if (ps->_a)
	{
		free(ps->_a);
		ps->_capacity = 0;
		ps->_top = 0;
	}
}
