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


//��ʼ��ջ
void StackInit(Stack* ps);

//��ջ
void StackPush(Stack* ps, STDataType x);

//��ջ
void StackPop(Stack* ps);

//��ȡջ������
STDataType StackTop(Stack* ps);

//��ȡջ��Ԫ����Ч����
STDataType StackSize(Stack* ps);

//���ջ�Ƿ�Ϊ�գ���Ϊ1���ǿ�Ϊ0
STDataType StackEmpty(Stack* ps);

//����ջ
void StackDestory(Stack* ps);
