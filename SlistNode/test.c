#include "Slist.h"

void test1()
{
  SList p = {NULL};
  PushBack(&p, 1);
  
  PushBack(&p, 2);
  PushBack(&p, 3);
  PushBack(&p, 4);
  Print(&p);
  PopBack(&p);

  Print(&p);
  PopBack(&p);
  PopBack(&p);
  PopBack(&p);
  PopBack(&p);
  PopBack(&p);
  PopBack(&p);

  Print(&p);
  PushFront(&p, 4);
  PushFront(&p, 3);
  PushFront(&p, 2);
  PushFront(&p, 1);
  PushFront(&p, 0);
  Print(&p);
  PopFront(&p);
  Print(&p);

  DesTory(&p);
}

int main()
{
  test1();
  return 0;
}
