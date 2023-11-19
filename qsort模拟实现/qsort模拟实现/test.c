#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void swap(char*arr,char*arr1,int width)
{
	char temp = 0;
	int i = 0;
	for (i = 0; i < width; i++)
	{
		temp = *arr;
		*arr = *arr1;
		*arr1 = temp;
		*arr++;
		*arr1++;
	}
	
}
int cmpa(const void* e1,const void* e2)
{
	return (*(int*)e2 - *(int*)e1);
}
void my_qsort(void* arr, int sz, int width,int(*cmpa)(const void *e1,const void *e2) )
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int flag = 1;
		int j = 0;
		for (j = 0; j < sz; j++)
		{
			if(cmpa((char*)arr+j*width,(char*)arr+(j+1)*width)>0)
			{
			 swap((char*)arr + j * width, (char*)arr + (j + 1) * width,width);
			 flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int width = sizeof(arr[0]);
	my_qsort((void*)arr, sz, width, cmpa);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}