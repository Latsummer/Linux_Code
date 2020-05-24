#include "Seqlist.h"


int main()
{
  SeqList p;
  p.PushBack(1);
  p.PushBack(2);
  p.PushBack(3);
  p.PushBack(4);
  p.PushBack(5);

  p.Print();

  p.PushFront(1);
  p.PushFront(2);
  p.PushFront(3);
  p.PushFront(4);
  p.PushFront(5);

  p.Print();
  
  p.PopBack();
  p.PopFront();

  p.Print();

  p.SeqListInsert(3, 9);
  p.SeqListInsert(4, 9);
  p.Print();
  p.SeqListErase(7);
  p.Print();

  return 0;
}
