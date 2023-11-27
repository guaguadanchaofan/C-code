#define  _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<windows.h>
typedef int SepListType;
//创建结构体
typedef struct SepList
{
	SepListType* data;
	size_t size;
	size_t capacity;
}SepList;


//初始化顺序表
void SepListInit(SepList* ps);

//销毁顺序表
void SepListDstroy(SepList* ps);

//顺序表打印
void SepListPrint(SepList* ps);

//顺序表尾插
void SepListPushBack(SepList* ps, SepListType x);

//顺序表尾删
void SepListPopBack(SepList* ps);

//容量检查
void SepListCheckCapacity(SepList* ps);

//头插
void SepListPushFront(SepList* ps,SepListType x);

//头删
void SepListPopFront(SepList* ps);

//查找
int SepListFind(SepList* ps, SepListType x);

// 顺序表在pos位置插入x
void SepListInsert(SepList* ps, size_t pos, SepListType x);

// 顺序表删除pos位置的值
void SepListErase(SepList* ps, size_t pos);