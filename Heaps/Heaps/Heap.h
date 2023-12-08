#define  _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

//�ѳ�ʼ��
void  HeapInit(Heap* php,HPDataType* a,int len);

//������
void HeapDestory(Heap* php);

//������
void HeapSort(Heap* php, int len);

//��ͷ��
void HeapPush(Heap* php, HPDataType x);

//��ͷɾ
void HeapPop(Heap* php);

//��Ѷ�����
HPDataType  HeapTop(Heap* php);