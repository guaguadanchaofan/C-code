#include"Heap.h"

//交换
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

//向下调整(左右分树为小堆)
void AdjustDown(HPDataType* a, int len ,int root)
{
	//找出左右孩子最小的哪个
	int parent = root;
	int child = parent * 2 + 1;
	while (child < len)
	{
		if (a[child] > a[child + 1] && (child + 1) < len)//找出左右孩子中最小的那个（注意child+1要小于数组长度防止越界）
		{
			child++;
		}
		if (a[child] < a[parent])//如果父亲小于最小的孩子则交换
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else//否则结束
		{
			break;
		}
	}
}

//堆初始化
void HeapInit(Heap* php, HPDataType* a, int len)
{
	assert(a);//判断数组传址不能为空
	php->_a = (HPDataType*)malloc(sizeof(HPDataType) * len);//动态开辟内存空间
	memcpy(php->_a, a, sizeof(HPDataType) * len);//使用内存拷贝将数组a拷贝到结构体_a
	php->_size = len;
	php->_capacity = len;
	//构建堆
	for (int i = (len - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->_a, len, i);
	}
}

//堆销毁
void HeapDestory(Heap* php)
{
	assert(php);
	php->_capacity = 0;
	php->_size = 0;
	free(php->_a);
	php->_a = NULL;
}

//堆排序
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

//向上调整
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

//堆尾插
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

//堆头删
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size);
	Swap(&php->_a[0],&php->_a[php->_size - 1]);
	php->_size--;
	AdjustDown(php->_a, php->_size, 0);
}

//查堆顶数据
HPDataType  HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);
	return php->_a[0];
}