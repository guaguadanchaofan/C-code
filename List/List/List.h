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


//˫�����ʼ��
ListNode* InitList();

//˫�����ӡ
void PrintList(ListNode* phead);

//β��
void ListPushBack(ListNode* phead, LTDataType x);

//βɾ
void ListPopBack(ListNode* phead);

//ͷ��
void ListPushFront(ListNode* phead, LTDataType x);

//ͷɾ
void ListPopFront(ListNode* phead);

//����
ListNode* ListFind(ListNode* phead, LTDataType x);

//pos����
void ListInsert(ListNode* pos, LTDataType x);

//posɾ��
void ListErase(ListNode* pos);

//�������
void ListDestory(ListNode* phead);
