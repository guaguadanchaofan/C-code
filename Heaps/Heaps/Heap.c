#include"Heap.h"
void print(Heap hp)
{
	for (int i = 0; i < hp._size; i++)
	{
		printf("%d ", hp._a[i]);
	}
	printf("\n");
}
int main()
{
	int a[] = {5,3,1,6,4,2,7,8,9,0 };
	Heap hp;
	HeapInit(&hp, a, 10);
	print(hp);
	/*HeapSort(&hp, 10);*/
	//print(hp);
	//HeapPush(&hp,-1);
	/*print(hp);*/
	HeapPop(&hp);
	print(hp);
	return 0;
}