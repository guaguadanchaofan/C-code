#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//���Ͷ���
typedef int SLTDatetype;
//�����ṹ��
typedef struct SListNode
{
	SLTDatetype val;
	struct SListNode* Next;
}SListNode;

//��̬����ڵ�
SListNode* BuySListNode(SLTDatetype x);

//��ӡ������
void SListPrint(SListNode* Plist);

//������β��
void SListPushBack(SListNode** PPlist,SLTDatetype x);

//������βɾ
void SListPopBack(SListNode** PPlist);

//������ͷ��
void SListpushFront(SListNode** PPlist, SLTDatetype x);

//������ͷɾ
void SListPopFront(SListNode** PPlist);

//���������
SListNode* SListFind(SListNode* Plist, SLTDatetype x);

//��posλ��֮�����
void SListInsertAfter(SListNode* pos, SLTDatetype x);

//��posλ��֮��ɾ��
void SListEraseAfter(SListNode* pos);
