#include "stack.h"



void StackInit(Stack* ps)
{
  ps->_top = 0;
  ps->_capacity = 20;
  ps->_a = (STDataType*)malloc(sizeof(STDataType) * ps->_capacity);
}
void StackCheack_capacity(Stack* ps)
{
  if(ps->_top >= ps->_capacity)
  {
    ps->_capacity *= 2;
    ps->_a = realloc(ps->_a, sizeof(ps->_capacity));
  }
}
void StackPush(Stack* ps, STDataType data)
{
  StackCheack_capacity(ps);
  ps->_a[ps->_top++] = data;
}
void StackPop(Stack* ps)
{
  ps->_top--;
}
STDataType StackTop(Stack* ps)
{
  return ps->_a[ps->_top - 1];
}
int StackSize(Stack* ps)
{
  return ps->_top;
}
int StackEmpty(Stack* ps)
{
  if(ps->_top == 0)
    return 1;
  return 0;
}
void StackDestory(Stack* ps)
{
  free(ps->_a);
  ps->_a = NULL;
  ps->_top = 0;
  ps->_capacity = 0;
}
