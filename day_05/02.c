#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main( int argc, char* argv[] )
{
  pid_t pid = fork();

  switch( pid )
  {
    case -1:
      break;
    case 0:
      strcpy(argv[0], "worker");
      printf("ddddd\n");
      break;
    default:
      strcpy(argv[0], "master");
      printf("xxxxx\n");
      break;

  }
  getchar();
}
