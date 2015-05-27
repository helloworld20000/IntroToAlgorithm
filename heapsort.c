//http://liuxinzhangyin.cn/59.html
#include <stdlib.h>
#include <stdio.h>
 
int min(int a[], int i, int j)
{
  if(a[i] < a[j])
    return i;
  else 
    return j;
 
   return -1;
}
 
void swap(int *i, int *j)
{
  int temp = *i;
  *i = *j;
  *j = temp;   
}
 
void printArray(int a[], int size, char *ch)
{
	printf("%s", ch);
	int i = 0;
	for(i = 0; i < size; i++)
		printf(" %d ", a[i]);
	printf("\n");
}
 
int minHeap(int a[], unsigned int size)
{
	int i = 0;
	for(i = (size -1)/2; i >= 0; i--)
		MinHeapFixdown(a, i, size);
	return 0;
}
 
int MinHeapFixdown(int a[], int begin, unsigned int size)
{
	int i = begin, minValue = 0;
	for(i = begin; 2*i + 1 < size;)
	{
		minValue = min(a, 2*i + 1, 2*i +2);
		if(2*i + 2 < size)
			minValue = min(a, 2*i + 1, 2*i +2);
		if(a[minValue] < a[i])
		{
			swap(&a[minValue], &a[i]);
			i = minValue;
		}
		else
			break;
	}
	return 0;
}
 
int heapSort(int a[], unsigned int size)
{
	int i =0;
	minHeap(a, size);
	
	printArray(a, size, "MinHeap: ");
	
	for(i = size -1; i > 0; i--)
	{
		swap(&a[i], &a[0]);
		MinHeapFixdown(a, 0, i-1);
		printArray(a, i, "heapSort ");
	}
	return 0;
}
 
int main()
{
	int a[10] = {9, 12, 17, 30, 50, 20, 60, 65, 4, 49};
	printArray(a, 10, "orgin array:  ");
	heapSort(a, 10);
	printArray(a, 10, "after heapsorting:");
}
