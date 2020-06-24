#include "ListNode.h"

void test1()
{
  ListNode pHead;
  Init(&pHead);
  ListPushFront(&pHead, 1);
  ListPushFront(&pHead, 2);
  ListPushFront(&pHead, 3);
  ListPushFront(&pHead, 4);
  ListPushFront(&pHead, 5);
  ListPrint(&pHead);
}
int main()
{
  test1();
  return 0;
}
