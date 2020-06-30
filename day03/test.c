#include<stdio.h>

int main()
{
  int num;
  do
  {
    printf("请输入：");
    if(scanf("%d",&num) != 1)
    {
      printf("输入非法\n");
      scanf("%*[^\n]%*c");
      continue;
    }
    break;
  }while(1);

  return 0;
}
