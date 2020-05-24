#pragma once
#include<iostream>
#include<stdlib.h>
#include<memory.h>
using namespace std;

typedef int SLDateType;

class SeqList
{
public:
  SeqList(size_t capacity = 2)
  {
    _capacity = capacity; 
    _a = (SLDateType*)malloc(sizeof(SLDateType) * _capacity);
    _size = 0;
  }
  SeqList(const SeqList& p)
  {
    _capacity = p._capacity;
    _size = p._size;
    _a = (SLDateType*)malloc(sizeof(SLDateType) * _capacity);
    memcpy(_a, p._a, sizeof(SLDateType) * p._size);
  }
  ~SeqList()
  {
    free(_a);
    _size = 0;
    _capacity = 0;
  }
  void ChickSize();
  void Print();
  void PushBack(SLDateType data);
  void PushFront(SLDateType data);
  void PopBack();
  void PopFront();
  int SeqListFind(SLDateType x);
  void SeqListInsert(size_t pos, SLDateType x);
  void SeqListErase(size_t pos);

private:
  SLDateType* _a;
  size_t _size;
  size_t _capacity;
};
