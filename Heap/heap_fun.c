#include "Heap.h"


void swap(HPDataType* arr, int left, int right)
{
  HPDataType tmp = arr[left];
  arr[left] = arr[right];
  arr[right] = tmp;
}
void ShiftDown(HPDataType* arr, int size, int parent)
{
  /*
   * 小堆
  int child = 2 * parent + 1;
  while(child < size)
  {
    if(child + 1 < size && arr[child + 1] < arr[child])
      child++;
    if(arr[child] < arr[parent])
    {
      swap(arr, child, parent);
      parent = child;
      child = 2 * parent + 1;
    }
    else
      break;
  }
  */
  //大堆
  int child = 2 * parent + 1;
  while(child < size)
  {
    if(child + 1 < size && arr[child + 1] > arr[child])
      child++;
    if(arr[child] > arr[parent])
    {
      swap(arr, child, parent);
      parent = child;
      child = 2 * parent + 1;
    }
    else
      break;
  }

}
void ShiftUp(HPDataType* arr, int child)
{
  /*  小堆
  int parent = (child - 1) / 2;
  while(child > 0)
  {
    if(arr[child] < arr[parent])
    {
      swap(arr, child, parent);
      child = parent;
      parent = (child - 1) / 2;
    }
    else
      break;
  }
  */
  int parent = (child - 1) / 2;
  while(child > 0)
  {
    if(arr[child] > arr[parent])
    {
      swap(arr, child, parent);
      child = parent;
      parent = (child - 1) / 2;
    }
    else
    {
      break;
    }
  }
  
}
void HeapCreat(Heap* hp, HPDataType* arr, int size)
{
  hp->_arr = (HPDataType*)malloc(sizeof(HPDataType) * size);
  hp->_size = size;
  hp->_capacity = size;
  memcpy(hp->_arr, arr, sizeof(HPDataType) * size);

  int parent = (size - 2) / 2;
  for(; parent >= 0; parent--)
    ShiftDown(hp->_arr, size, parent);
}
void HeapPrint(Heap* hp)
{
  int i = 0;
  for(; i < hp->_size; i++)
    printf("%d ", hp->_arr[i]);
  printf("\n");
}
void HeapDestory(Heap* hp)
{
  free(hp->_arr);
  hp->_arr = NULL;
  hp->_size = 0;
  hp->_capacity = 0;
}
void CheckCapacity(Heap* hp)
{
  if(hp->_size >= hp->_capacity)
  {
    hp->_capacity *= 2;
    hp->_arr = realloc(hp->_arr, sizeof(HPDataType) * hp->_capacity);
  }
}
void HeapPush(Heap* hp, HPDataType data)
{
  CheckCapacity(hp);
  hp->_arr[hp->_size++] = data;
  ShiftUp(hp->_arr, hp->_size - 1);
}
void HeapPop(Heap* hp)
{
  if(hp->_size > 0)
  {
    swap(hp->_arr, 0, hp->_size - 1);
    hp->_size--;
    ShiftDown(hp->_arr, hp->_size, 0);
  }
}
HPDataType HeapTop(Heap* hp)
{
  return hp->_arr[0];
}
int HeapSize(Heap* hp)
{
  return hp->_size;
}
int HeapEmpty(Heap* hp)
{
  if(hp->_size == 0)
    return 1;
  return 0;
}


void PrintTopK(int* a, int n, int k)
{
  Heap hp;
  HeapCreat(&hp, a, k);
  int i = k;
  for(; i < n; i++)
  {
    if(a[i] < HeapTop(&hp))
    {
      HeapPop(&hp);
      HeapPush(&hp, a[i]);
    }
  }
  for(i = 0; i < k; i++)
  {
    printf("%d \n",HeapTop(&hp));
    HeapPop(&hp);
  }
}
