#include"Heap.h"

//����
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

//���µ���(���ҷ���ΪС��)
void AdjustDown(HPDataType* a, int len ,int root)
{
	//�ҳ����Һ�����С���ĸ�
	int parent = root;
	int child = parent * 2 + 1;
	while (child < len)
	{
		if (a[child] > a[child + 1] && (child + 1) < len)//�ҳ����Һ�������С���Ǹ���ע��child+1ҪС�����鳤�ȷ�ֹԽ�磩
		{
			child++;
		}
		if (a[child] < a[parent])//�������С����С�ĺ����򽻻�
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else//�������
		{
			break;
		}
	}
}

//�ѳ�ʼ��
void HeapInit(Heap* php, HPDataType* a, int len)
{
	assert(a);//�ж����鴫ַ����Ϊ��
	php->_a = (HPDataType*)malloc(sizeof(HPDataType) * len);//��̬�����ڴ�ռ�
	memcpy(php->_a, a, sizeof(HPDataType) * len);//ʹ���ڴ濽��������a�������ṹ��_a
	php->_size = len;
	php->_capacity = len;
	//������
	for (int i = (len - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->_a, len, i);
	}
}

//������
void HeapDestory(Heap* php)
{
	assert(php);
	php->_capacity = 0;
	php->_size = 0;
	free(php->_a);
	php->_a = NULL;
}

//������
void HeapSort(Heap* php, int len)
{
	for (int i = (len - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->_a, len, i);
	}
	int end = len - 1;
	while (end > 0)
	{
		Swap(&php->_a[0], &php->_a[end]);
		AdjustDown(php->_a, end, 0);
		end--;
	}
}

//���ϵ���
void Adjustup(HPDataType* a, int len, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//��β��
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	if (php->_capacity == php->_size)
	{
		php->_capacity *= 2;
		HPDataType* tmp = (HPDataType*)realloc(php->_a, sizeof(HPDataType) * php->_capacity);
		php->_a = tmp;
	}
	php->_a[php->_size] = x;
	php->_size++;
	Adjustup(php->_a, php->_size, php->_size - 1);
}

//��ͷɾ
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size);
	Swap(&php->_a[0],&php->_a[php->_size - 1]);
	php->_size--;
	AdjustDown(php->_a, php->_size, 0);
}

//��Ѷ�����
HPDataType  HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);
	return php->_a[0];
}