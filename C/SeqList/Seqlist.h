#include<stdio.h>

typedef int SLDataType;

typedef struct SeqList
{
  SLDataType* arr;
  size_t size;
  size_t capicity;
}SeqList;

void SeqListInit(SeqList* sl);//初始化
void SeqListDestory(SeqList* sl);//销毁
void SeqListPrint(SeqList* sl);//打印
void CheckCapacity(SeqList* sl);//检查或扩容
void PushBack(SeqList* sl, SLDataType data);//尾插
void PopBack(SeqList* sl);//尾删
void PushFront(SeqList* sl, SLDataType data);//头插
void PopFront(SeqList* sl);//头删
int SeqListFind(SeqList* sl, SLDataType data);//查找
void SeqListInsert(SeqList* sl, size_t pos, SLDataType data);//pos位置插入
void SeqListErase(SeqList* sl, size_t pos);//pos位置删除
