#include<stdio.h>
#include<unistd.h>

int main()
{
  pid_t pid = fork();
  if(pid != 0)
  {
    pid_t pid2 = fork();
    if(pid2 != 0)
    {
      printf("1\n");
    }
    else
      printf("3\n");
  }
  else
    printf("2\n");
  getchar();
}
