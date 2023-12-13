#define  _CRT_SECURE_NO_WARNINGS
#include"Sort.h"



//ֱ�Ӳ�������
void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1; i++)//�ӵ�һ����ʼ����
	{
		int end=i;
		int tmp = a[end + 1];//����n+1��ֵ
		while (end >= 0)
		{
			if (a[end] > tmp)//�ӵ�end����tmp�Ƚ�
			{
				a[end + 1] = a[end];//����a[end+1]��ֵ
				--end;              //��endǰ��һ������tmp�Ĵ�С
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
	
}
//ϣ������
void ShellSort(int* a, int n)//���ڲ�������Ļ����ϼ�����Ԥ����
{
	assert(a);
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//����gap��ֵ���˴��ɸ��ģ��Ƚ���Ԥ��������Сgap��һ��Ԥ��
		for (int i = 0; i < n - gap; i++)//gap����1���������
		{
			int end = i;
			int tmp = a[end + gap];//����tmp��ֵ
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

//ѡ������
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
				mini = i;//������Сֵ���±�
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		if (maxi==start)//���maxi�±��start��Ȼᵼ��maxi��λ
		{
			Swap(&a[start], &a[mini]);
			maxi = mini;
		}
		else
		{
			Swap(&a[start], &a[mini]);

		}
		Swap(&a[end], &a[maxi]);
		start++;//��С����λ��
		end--;
	}
}

//ð������
void BubbleSort(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n; i++)
	{
		int exchange = 0;//��¼ѭ�����Ƿ�������
		for (int j = 1; j < n - i; j++)//ÿ�ν���ֵ�ŵ����Ͳ����ٱȽ�������n-i��
		{
			if (a[j] < a[j-1])
			{
				exchange = 1;
				Swap(&a[j], &a[j - 1]);
			}
		}
		if (exchange == 0)//�����һ��û�з���������ʾ��������ֱ��break��
		{
			break;
		}
	}
}

//������
void HeapSort()
{

}

//���µ����㷨
void AdjustDown()
{

}