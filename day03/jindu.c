#include<stdio.h>
#include<unistd.h>
int main()
{
  char buf[100] = {0};
  int i = 0;
  char* p = "|/-\\";
  for(i = 0; i < 100 ; i++)
  {
    buf[i] = '#';
    printf("[%-100s][%d%%][%c]\r", buf, i + 1, p[i % 4]);
    fflush(stdout);
    usleep(100000);
  }
  printf("\n");
}
