#include<stdio.h>

int* p = NULL;

int fun(int n)
{
  p = (int*)"abc";
  return n + 1;
}
int main(int argc, char* argv[]){
    int ra = fun(3) ;
    *p = 10;
printf("*p = %d\n", *p);
    for(int i = 0; i<argc; i++)
    {
      printf("argv[%d] = %s\n", i, argv[i]);
    }
}
