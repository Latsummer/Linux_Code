#include<stdio.h>
#include<stdlib.h>
int main( int argc, char* argv[] ,char* envp[])
{
  int i;
  /*printf("argc = %d\n",argc);

  for(i = 0; i< argc; i++)
  {
    printf("argv[%d] : %s\n", i, argv[i]);
  }
  while(*argv)
  {
    printf("%s\n", *argv++);
  }*/
  /*for(i = 0; envp != NULL; i++)
  {
    printf("%d : %s\n", i, envp[i]);
  }*/
  char* bash = getenv("SHELL");
  printf("%s\n", bash == NULL ? "NULL": bash);

  if(putenv("AAA=abc") == 0)
    printf("putenv() ok\n");
  else
    printf("putenv() error\n");

  bash = getenv("AAA");
  printf("%s\n", bash == NULL ? "NULL" : bash);
}
