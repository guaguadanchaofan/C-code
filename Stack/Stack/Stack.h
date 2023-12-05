#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


#define STACKSIZE 4
typedef int STDataType;
typedef struct Stack
{
	STDataType*  _a;
	int _top;
	int _capacity;
}Stack;


//初始化栈
void StackInit(Stack* ps);

//入栈
void StackPush(Stack* ps, STDataType x);

//出栈
void StackPop(Stack* ps);

//获取栈顶数据
STDataType StackTop(Stack* ps);

//获取栈中元素有效个数
STDataType StackSize(Stack* ps);

//检测栈是否为空，空为1，非空为0
STDataType StackEmpty(Stack* ps);

//销毁栈
void StackDestory(Stack* ps);
