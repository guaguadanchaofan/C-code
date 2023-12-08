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

//堆初始化
void  HeapInit(Heap* php,HPDataType* a,int len);

//堆销毁
void HeapDestory(Heap* php);

//堆排序
void HeapSort(Heap* php, int len);

//堆头插
void HeapPush(Heap* php, HPDataType x);

//堆头删
void HeapPop(Heap* php);

//查堆顶数据
HPDataType  HeapTop(Heap* php);