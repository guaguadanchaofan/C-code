#define  _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<windows.h>
typedef int SepListType;
//�����ṹ��
typedef struct SepList
{
	SepListType* data;
	size_t size;
	size_t capacity;
}SepList;


//��ʼ��˳���
void SepListInit(SepList* ps);

//����˳���
void SepListDstroy(SepList* ps);

//˳����ӡ
void SepListPrint(SepList* ps);

//˳���β��
void SepListPushBack(SepList* ps, SepListType x);

//˳���βɾ
void SepListPopBack(SepList* ps);

//�������
void SepListCheckCapacity(SepList* ps);

//ͷ��
void SepListPushFront(SepList* ps,SepListType x);

//ͷɾ
void SepListPopFront(SepList* ps);

//����
int SepListFind(SepList* ps, SepListType x);

// ˳�����posλ�ò���x
void SepListInsert(SepList* ps, size_t pos, SepListType x);

// ˳���ɾ��posλ�õ�ֵ
void SepListErase(SepList* ps, size_t pos);