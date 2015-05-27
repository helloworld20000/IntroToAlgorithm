/*A priority queue is a data structure for maintaining a set S of elements, each with an associated value called a key.
 *A max priority queue supports the following operations:
 *INSERT(S, x) inserts the element x into the set S
 *MAXIMUN(S) returns the element of S with the largest key
 *EXTRACT-MAX(S) removes and returns the element of S with largest key
 *INCREASE-KEY(S, x, k) increase the value of element x's key to the new value k, which is assumed to be at least as large as x's current key
 *value.
 *when compile, please use command below:
 *  gcc priority-queue.c -o prioriy-queue  -lm
 *Introduction to GDB: http://blog.csdn.net/liigo/article/details/582231
 *http://liuxinzhangyin.cn/64.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100
#define MIN -1000

int heap[100]; //begin with 1.Max heap. heap[0] store heap.length

void printHeap(int *S)
{
   int height = floor(log(S[0])/log(2));
   int i = 1, j = 1;
   for(;i <= height + 1; i++)
   {
      for(; j <= S[0] && j <= pow(2, i) -1; j++) {
         printf(" %d ", S[j]);
      }
      printf("\n");
   }
}

int exchange(int *i, int *j)
{
   int tmp = *i;
   *i = *j;
   *j = tmp;
   return 0;
}

int maxHeapify(int *S, int i)
{
   int l = 2*i;
   int r = 2*i + 1;
   int largest = 0;
   if(l <= S[0] && S[l] > S[i]) // S[0] store length of heap
      largest = l;
   else
      largest = i;
   if(r <= S[0] && S[r] > S[largest])
      largest = r;
   if(largest != i) {
      exchange(S + i, S + largest);
      maxHeapify(S, largest);
   }
   return 0;
}

int buildMaxHeap(int *S)
{
   int i = S[0] / 2;
   for(; i >= 1; i--){
      maxHeapify(S, i);
   }
   return 0;
}

int maxHeapInsert(int *S, int key)
{
   S[0] = S[0] + 1;
   S[S[0]] = MIN;
   heapIncreaseKey(S, S[0], key);
   return 0;
}

int heapMaximun(int *S)
{
   return S[1];
}

int heapExtractMax(int *S)
{
   int max = 0;
   if(S[0] < 1)
     perror("heap underflow");
   max = S[1];
   S[1] = S[S[0]];
   S[0] = S[0] - 1;
   maxHeapify(S, 1);
   return max;
}

int heapIncreaseKey(int *S, int i, int key)
{
   if(key < S[i])
     perror("new key is smaller than current key");

   S[i] = key;
   while(i > 1 && S[i/2] < S[i]){
      exchange(S + i, S + i/2);
      i = i / 2;
   }
   return 0;
}

int main()
{
   int max = 0;
   heap[0] = 10;
   heap[1] = 1; heap[2] = 2; heap[3] = 3; heap[4] = 4;
   heap[5] = 7; heap[6] = 8; heap[7] = 9; heap[8] = 10;
   heap[9] = 14; heap[10] = 16;
  
   printf("Original State:\n");
   printHeap(heap);

   buildMaxHeap(heap);
   printf("\n After Heapifying:\n");
   printHeap(heap);

   heapIncreaseKey(heap, 9, 15);
   printf("\n After Increasing S[9]'s key to 15:\n");
   printHeap(heap);

   max = heapExtractMax(heap);
   printf("\n Max key is %d, After Extracting Max Key:\n", max);
   printHeap(heap);

   maxHeapInsert(heap, 13);
   printf("\n After inserting key 13:\n");
   printHeap(heap);

   return 0;
}
