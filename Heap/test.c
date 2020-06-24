#include "Heap.h"

void test1()
{
  Heap hp;
  int a[11] = {100, 20, 30, 20, 25, 18, 10, 5, 21, 15, 23};
  HeapCreat(&hp, a, 11);
  HeapPrint(&hp);
  HeapPop(&hp);
  HeapPrint(&hp);
  HeapPush(&hp, 150);
  HeapPrint(&hp);
}

void topK()
{
  int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  PrintTopK(arr, 10, 4);
}

int main()
{
  test1();
  topK();
  return 0;
}
