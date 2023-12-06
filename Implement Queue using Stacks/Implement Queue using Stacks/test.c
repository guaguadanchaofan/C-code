#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;
void CheckCapacity(Stack* ps)
{
	if (ps->_capacity == ps->_top)
	{
		ps->_capacity *= 2;
		ps->_a = (STDataType*)realloc(ps->_a, ps->_capacity * sizeof(STDataType));
	}
}

//初始化栈
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = (STDataType*)calloc(4, sizeof(STDataType));
	ps->_top = 0;
	ps->_capacity = 4;
}

//入栈
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->_a[ps->_top] = x;
	ps->_top++;
}
//出栈
void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return;
	}
	ps->_top--;
}

//获取栈顶数据
STDataType StackTop(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return (STDataType)0;
	}
	return ps->_a[ps->_top - 1];
}

//获取栈中元素有效个数
STDataType StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
//检测栈是否为空，空为1，非空为0
STDataType StackEmpty(Stack* ps)
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
void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->_a)
	{
		free(ps->_a);
		ps->_capacity = 0;
		ps->_top = 0;
	}
}


typedef struct {
	Stack pushST;
	Stack popST;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* pqueue = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&pqueue->pushST);
	StackInit(&pqueue->popST);
	return pqueue;
}

void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->pushST, x);
}
int myQueuePop(MyQueue* obj) {
	if (StackEmpty(&obj->popST) == 1)
	{
		while (StackEmpty(&obj->pushST) != 1)
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	int front = StackTop(&obj->popST);
	StackPop(&obj->popST);
	return front;
}

int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->popST) == 1)
	{
		while (StackEmpty(&obj->pushST) != 1)
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	return StackTop(&obj->popST);
}
bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}

void myQueueFree(MyQueue* obj) {
	StackDestory(&obj->pushST);
	StackDestory(&obj->popST);
	free(obj);
}

int main()
{
	MyQueue* obj= myQueueCreate();
	myQueuePush(obj, 1);
	myQueuePush(obj, 2); 
	int ret = myQueuePeek(obj);
	int pop = myQueuePop(obj);
	return 0;
}