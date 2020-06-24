#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main()
{
  srand((unsigned int)time(NULL));
  char str[11];
  str[10] = '\0';
  int set = 0;
  while(1)
  {
    int i = 0;
    for(; i < 10; i++)
    {
       set = rand()%126;
       if(set < 33)
         continue;
       str[i] = set;
    }
    printf("%s\b", str);
    //printf("\033[3A");
    printf("\033[K");
    fflush(stdout);
    sleep(1);

  }
  return 0;
}
