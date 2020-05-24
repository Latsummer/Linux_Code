#include "stack.h"

void test1()
{
  Stack ps;
  StackInit(&ps);
  StackPush(&ps, 5);
  StackPush(&ps, 4);
  StackPush(&ps, 3);
  StackPush(&ps, 2);
  StackPush(&ps, 1);
  
  printf("%d\n", StackTop(&ps));
  StackPop(&ps);
  printf("%d\n", StackTop(&ps));
  StackPop(&ps);
  printf("%d\n", StackTop(&ps));
  StackPop(&ps);

}

int main()
{
  test1();
  return 0;
}
