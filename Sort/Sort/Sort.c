#define  _CRT_SECURE_NO_WARNINGS
#include"Sort.h"



//直接插入排序
void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1; i++)//从第一个开始遍历
	{
		int end=i;
		int tmp = a[end + 1];//保存n+1的值
		while (end >= 0)
		{
			if (a[end] > tmp)//从第end个与tmp比较
			{
				a[end + 1] = a[end];//覆盖a[end+1]的值
				--end;              //在end前面一个数与tmp的大小
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
	
}
//希尔排序
void ShellSort(int* a, int n)//（在插入排序的基础上加入了预排序）
{
	assert(a);
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//控制gap的值（此处可更改）先进行预排序，再缩小gap进一步预排
		for (int i = 0; i < n - gap; i++)//gap等于1是排序完成
		{
			int end = i;
			int tmp = a[end + gap];//保存tmp的值
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}


void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//选择排序
void SelectSort(int* a, int n)
{
	assert(a);
	int start = 0;
	int end = n-1;
	while (start < end)
	{
		int maxi;
		int mini;
		maxi = mini = start;
		for (int i = start; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;//保存最小值的下标
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		if (maxi==start)//如果maxi下标和start相等会导致maxi换位
		{
			Swap(&a[start], &a[mini]);
			maxi = mini;
		}
		else
		{
			Swap(&a[start], &a[mini]);

		}
		Swap(&a[end], &a[maxi]);
		start++;//缩小两边位置
		end--;
	}
}

//冒泡排序
void BubbleSort(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n; i++)
	{
		int exchange = 0;//记录循环内是否发生交换
		for (int j = 1; j < n - i; j++)//每次将最值放到最后就不用再比较所以是n-i；
		{
			if (a[j] < a[j-1])
			{
				exchange = 1;
				Swap(&a[j], &a[j - 1]);
			}
		}
		if (exchange == 0)//如果第一遍没有发生交换表示数组有序直接break；
		{
			break;
		}
	}
}

//堆排序
void HeapSort()
{

}

//向下调整算法
void AdjustDown()
{

}