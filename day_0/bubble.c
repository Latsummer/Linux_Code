#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 20

void InitA(int* a, int size)
{
  int i = 0;
  for(i = 0; i < size; i++)
  {
    a[i] = rand()%100;
  }
}

void Boubble(int* a, int size)
{
  int i = 0;
  int j = 0;
  for(i = 0; i < size - 1; i++)
  {
    for(j = 0; j < size - 1 - i; j++)
    {
      if(a[j] < a[j + 1])
      {
        int tmp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp;
      }
    }
  }
}

void Print(int* a, int size)
{
  int i = 0;
  for(i = 0; i < size; i++)
    printf("%3d%c", a[i], (i % 10 == 9 || i == size - 1) ? '\n' : ' ' );
}

int main()
{
  srand((unsigned int)time(NULL));
  int a[SIZE] = {0};  
  InitA(a, SIZE);
  Boubble(a, SIZE);
  Print(a, SIZE);
  return 0;
}
