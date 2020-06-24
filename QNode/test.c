#include "Qnode.h"

void test1()
{
  Queue q;
  QueueInit(&q);
  QueuePush(&q, 1);
  QueuePush(&q, 2);
  QueuePush(&q, 3);
  QueuePush(&q, 4);
  QueuePush(&q, 5);

  printf("%d \n", QueueFront(&q));
  printf("%d \n", QueueBack(&q));
}

int main()
{
  test1();
  return 0;
}
