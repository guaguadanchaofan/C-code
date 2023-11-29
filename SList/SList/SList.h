#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//类型定义
typedef int SLTDatetype;
//创建结构体
typedef struct SListNode
{
	SLTDatetype val;
	struct SListNode* Next;
}SListNode;

//动态申请节点
SListNode* BuySListNode(SLTDatetype x);

//打印单链表
void SListPrint(SListNode* Plist);

//单链表尾插
void SListPushBack(SListNode** PPlist,SLTDatetype x);

//单链表尾删
void SListPopBack(SListNode** PPlist);

//单链表头插
void SListpushFront(SListNode** PPlist, SLTDatetype x);

//单链表头删
void SListPopFront(SListNode** PPlist);

//单链表查找
SListNode* SListFind(SListNode* Plist, SLTDatetype x);

//在pos位置之后插入
void SListInsertAfter(SListNode* pos, SLTDatetype x);

//在pos位置之后删除
void SListEraseAfter(SListNode* pos);
