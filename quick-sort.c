// quick sort is in place algorithm
// http://liuxinzhangyin.cn/65.html
#include <stdlib.h>
#include <stdio.h>

int A[8] = {3, 1, 17, 0, 9, 22, 13, 7};

void exchange(int *i, int *j)
{
   int tmp = *i;
   *i = *j;
   *j = tmp;
}

void printA(int *A, int length)
{
   int i = 0;
   for(;i < length; i++)
     printf(" %d ", A[i]);
   printf("\n");
}

int quickSort(int *A, int p, int r)
{
   int q = 0;
   if(p < r) {
      q = partition(A, q, r);
      quickSort(A, p, q - 1);
      quickSort(A, q + 1, r);
   }
   return 0;
}

int partition(int *A,int p, int r)
{
  int x = A[r];
  int i = p - 1;
  int j = p;
  for(;j <= r; j++){
    if(A[j] < x){
      i = i + 1;
      exchange(A + i, A + j);
    }
  }
  exchange(A + i + 1, A + r);
  return i + 1;
}

int main()
{
  printf("Original Array: ");
  printA(A, 8);

  quickSort(A, 0, 7);
  printf("After Sorting: ");
  printA(A, 8);
  
  return 0;
}
