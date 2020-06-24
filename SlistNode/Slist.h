#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int SLTDataType;

typedef struct SListNode
{
  SLTDataType _data;
  struct SListNode* _next;
}SListNode;

typedef struct SList
{
  SListNode* _head;
}SList;

SListNode* CreatNode(SLTDataType data);
void Print(SList* p);
void PushBack(SList* p, SLTDataType data);
void PopBack(SList* p);
void PushFront(SList* p, SLTDataType data);
void PopFront(SList*p);
SListNode* Find(SList* p, SLTDataType data);
void SlistInsert_After(SListNode* pos, SLTDataType data);
void SlistErase_After(SListNode* pos);
void DesTory(SList* p);
