#include"Stack.h"


//检查容量
void CheckCapacity(Stack* ps)
{
	if (ps->_capacity == ps->_top)
	{
		ps->_capacity *= 2;
		ps->_a = (STDataType*)realloc(ps->_a,ps->_capacity* sizeof(STDataType));
	}
}

//初始化栈
void SrackInit(Stack* ps)
{
	assert(ps);
	ps->_a = (STDataType*)calloc(STACKSIZE, sizeof(STDataType));
	ps->_top = 0;
	ps->_capacity = STACKSIZE;
}

//入栈
void SrackPush(Stack* ps,STDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->_a[ps->_top] = x;
	ps->_top++;
}
//出栈
void SrackPop(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return;
	}
	ps->_top--;
}

//获取栈顶数据
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

//获取栈中元素有效个数
STDataType SrackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
//检测栈是否为空，空为1，非空为0
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
//销毁栈
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
