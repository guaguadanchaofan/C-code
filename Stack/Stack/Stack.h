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
void SrackInit(Stack* ps);

//��ջ
void SrackPush(Stack* ps, STDataType x);

//��ջ
void SrackPop(Stack* ps);

//��ȡջ������
STDataType SrackTop(Stack* ps);

//��ȡջ��Ԫ����Ч����
STDataType SrackSize(Stack* ps);

//���ջ�Ƿ�Ϊ�գ���Ϊ1���ǿ�Ϊ0
STDataType SrackEmpty(Stack* ps);

//����ջ
void SrackDestory(Stack* ps);
