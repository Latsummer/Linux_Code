#include"Seqlist.h"

void test1()
{
  SeqList sl;
  SeqListInit(&sl);
  PushFront(&sl, 10);

  PushFront(&sl, 11);
  PushFront(&sl, 12);
  PushFront(&sl, 13);
  PushFront(&sl, 14);
  PushFront(&sl, 15);
  PushBack(&sl, 99);
  PopFront(&sl);
  PopBack(&sl);
  SeqListPrint(&sl);
}
int main()
{
  test1();
  return 0;
}
