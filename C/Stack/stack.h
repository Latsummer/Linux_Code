#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int STDataType;
typedef struct Stack
{
  STDataType* _a;
  int _top;
  int _capacity;
}Stack;

void StackInit(Stack* ps);
void StackCheack_capacity(Stack* ps);
void StackPush(Stack* ps, STDataType data);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackSize(Stack* ps);
int StackEmpty(Stack* ps);
void StackDestory(Stack* ps);
