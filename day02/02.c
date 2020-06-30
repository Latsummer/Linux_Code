#include<stdio.h>

int sum(int n)
{
 // if(n < 1)
  //  return n;
 // else
  //  return n + sum(n - 1);
  return 3;

}
int main()
{
  int i = 10;
  int r = sum(i);

  printf("r = %d\n",r);

  return 0;
  
}
