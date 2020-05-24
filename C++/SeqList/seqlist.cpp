#include "Seqlist.h"

void SeqList::Print()
{
  size_t i = 0;
  for(i = 0; i < _size; i++)
   cout << _a[i] << " ";
  cout << endl;
}

void SeqList::ChickSize()
{
  if(_size >= _capacity)
  {
    _capacity *= 2;
    _a = (SLDateType*)realloc(_a, sizeof(SLDateType) *_capacity);
  }
}

void SeqList::PushBack(SLDateType data)
{
  SeqList::ChickSize();
  _a[_size++] = data;
}

void SeqList::PushFront(SLDateType data)
{
  SeqList::ChickSize();
  size_t end = _size;
  while(end > 0)
  {
    _a[end] = _a[end - 1];
    end--;
  }
  _a[0] = data;
  _size++;
}

void SeqList::PopBack()
{
  _size--;
}

void SeqList::PopFront()
{
  size_t i;
  for(i = 0; i < _size; i++)
    _a[i] = _a[i + 1];
  _size--;
}

void SeqList::SeqListInsert(size_t pos, SLDateType x)
{
  SeqList::ChickSize();
  size_t end = _size;
  while(end > (pos - 1))
  {
    _a[end] = _a[end - 1];
    end--;
  }
  _a[pos - 1] = x;
  _size++;
}

void SeqList::SeqListErase(size_t pos)
{
  size_t Erase = pos - 1;
  while(Erase < _size)
  {
    _a[Erase] = _a[Erase + 1];
    Erase++;
  }
  _size--;
}

