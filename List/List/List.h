#define  _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType x;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;


//双链表初始化
ListNode* InitList();

//双链表打印
void PrintList(ListNode* phead);

//尾插
void ListPushBack(ListNode* phead, LTDataType x);

//尾删
void ListPopBack(ListNode* phead);

//头插
void ListPushFront(ListNode* phead, LTDataType x);

//头删
void ListPopFront(ListNode* phead);

//查找
ListNode* ListFind(ListNode* phead, LTDataType x);

//pos插入
void ListInsert(ListNode* pos, LTDataType x);

//pos删除
void ListErase(ListNode* pos);

//链表清空
void ListDestory(ListNode* phead);
