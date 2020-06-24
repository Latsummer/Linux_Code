#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef int HPDataType;
typedef struct Heap
{
  HPDataType* _arr;
  int _size;
  int _capacity;
}Heap;

void HeapCreat(Heap* hp, HPDataType* arr, int size);
void ShiftDown(HPDataType* arr, int size, int parent);
void ShiftUp(HPDataType* arr, int child);
void HeapPrint(Heap* hp);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType data);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
void PrintTopK(int* a, int n, int k);
